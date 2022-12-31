#include "pch.h"
#include <cmath>
#include "Example.h"
#include "MultiPatch.h"
#include "HalfeEdge.h"
#include "Multipatch_Helper.h"

multipatch::multipatch(HalfEdgeMesh & hem)
{
	HalfEdge_Mesh = hem;
	for (int i = 0; i < hem.faces.size();i++)
	{
		Splines.push_back(spline(3));
		spline& sp = Splines[i];
		sp.BS = BSpline(2);
		tensor_example(sp.tensor2);

		Interpolation_QuadPatch(i+1, hem, sp);
	}	
}

point multipatch::EvaluateMultipatch_FaceBased(int face//face index
	, vector<float> FaceReferenced_Params)
{
	return Splines[face - 1].Evaluate(FaceReferenced_Params);
	
}

point multipatch::EvaluateMultipatch_EdgeBased(int HalfeEdgeIndex, vector<float> EdgeReferenced_Param)
{

	int faceIndex = HalfEdge_Mesh.HalfeEdges[HalfeEdgeIndex - 1].face;
	int HEdgeIndexInFace= HalfEdge_Mesh.HEdgeIndexInFace(HalfeEdgeIndex);
	vector <float> x = CoordinateChange_PatchParameter(EdgeReferenced_Param, HEdgeIndexInFace);
	return Splines[faceIndex - 1].Evaluate(x);
}



int multipatch::previousFaces_CtrlPtsCounter(int face)
{
	int previousFaces_CtrlPtsCounter = 0;
	for (int faceIndex = 1;faceIndex < face;faceIndex++)
	{
		int CtrPtNb_PerOneFace = Splines[faceIndex - 1].BS.controlGridShape[0] *
			Splines[faceIndex - 1].BS.controlGridShape[1];
		previousFaces_CtrlPtsCounter += CtrPtNb_PerOneFace;
	}
	return previousFaces_CtrlPtsCounter;
}



void multipatch::CreateG0Basis()
{
	
	for (Face& f : HalfEdge_Mesh.faces)
	{
		//internal coefficients
		
		
		HEdge& he = HalfEdge_Mesh.HalfeEdges[f.HEdge - 1];
		int EdgeAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[1];
		int OtherAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[0];

		for (int i =0; i< EdgeAxeControlePointsNumber;i++)
			for (int j = 0;j< OtherAxeControlePointsNumber;j++)
			{
				G0Basis.push_back(SparseMatrix());
				G0Basis.back().cfM.push_back(MatrixCoefficient(i, j, 1.));
			}

		
	}
	//edge coefficients
	vector<bool> i_HalfEdge_used(HalfEdge_Mesh.HalfeEdges.size());
	int HEdgeCounter = 0;
	for (HEdge he : HalfEdge_Mesh.HalfeEdges)
	{
		int EdgeAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[1];
		int OtherAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[0];
		HEdge NextEdge = HalfEdge_Mesh.HalfeEdges[he.next];
		HEdge NextNextEdge = HalfEdge_Mesh.HalfeEdges[NextEdge.next];
		HEdge PreviousEdge = HalfEdge_Mesh.HalfeEdges[NextNextEdge.next];
		Face fc = HalfEdge_Mesh.faces[he.face];
		
		if (fc.HEdge == HEdgeCounter)
		{
			int i = 0;
			int j = 0;
			G0Basis.push_back(SparseMatrix());
			G0Basis.back().cfM.push_back(MatrixCoefficient(i, j, 1));
		}
		HEdgeCounter++;
	}
}


void Interpolation_QuadPatch(int face, HalfEdgeMesh hem, spline& sp)

{
	Face* fc= &hem.faces[face - 1];
	 HEdge he=hem.HalfeEdges[ fc->HEdge-1];
	 vector<int> pointsIndeces;
	 for (int i = 0; i < 4;i++)
	 {
		 pointsIndeces.push_back(he.vertex);
		 he = hem.HalfeEdges[he.next-1];

	 }
	Interpolation_QuadPatch(pointsIndeces, hem, sp);
}

void Interpolation_QuadPatch(vector<int> pointsIndeces, HalfEdgeMesh hem, spline& sp)
{
	vector <point> FacePoints;
	for (int i = 0;i < 4;i++)
		FacePoints.push_back(hem.vertices[pointsIndeces[i]-1].Point);
	interpolation_4points(FacePoints, sp);
	
}

void interpolation_4points(vector<point> FacePoints, spline& sp)
{
	point refPoint = FacePoints[0];
	point secondPoint = FacePoints[3];
	point Xaxis= FacePoints[1]-refPoint;
	point Xaxisp = FacePoints[2] -secondPoint;
	/*point Yaxis= FacePoints[3]-refPoint;
	point Yaxisp = FacePoints[2] - FacePoints[1];*/
	
	for (int i = 0; i < 4;i++) {
		point pt1 = refPoint + (i / 3.0) * Xaxis;
		point pt2 = secondPoint + (i / 3.0) * Xaxisp;
		point vect = pt2 - pt1;
		for (int j = 0;j < 4;j++)
		{
			point pt =pt1+(j / 3.0)* vect;
			//= refPoint + (i / 3.0) * Xaxis + (j / 3.0) * Yaxis;
			sp.tensor2[i][j] = pt;


		}
	}

}
