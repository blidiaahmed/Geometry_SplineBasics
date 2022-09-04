#include "pch.h"
#include<cmath>
#include"Example.h"
#include "MultiPatch.h"
#include "HalfeEdge.h"
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

void multipatch::CreateControleVector()
{
	int counter = 0;
	for (Face& f : HalfEdge_Mesh.faces)
	{
		
		for (unsigned __int8 i = 0;i < Splines[counter].AmbiantDimension;i++)
			ControleVector.push_back(vector<float>());
		AddQuadFaceControlePoints(f);
	}
}

void multipatch::AddQuadFaceControlePoints(Face& f)
{
	HEdge & he = HalfEdge_Mesh.HalfeEdges[f.HEdge-1];
	for (int HalfEdgeIndexInFace = 1;HalfEdgeIndexInFace <=4;HalfEdgeIndexInFace++)
			AddAQuarterFaceOfControlePoints(he,HalfEdgeIndexInFace);

	int EdgeAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[1];
	int OtherAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[0];

	if (EdgeAxeControlePointsNumber % 2 == 1 && OtherAxeControlePointsNumber % 2 == 1)
		AddCentralControlePoint(he, EdgeAxeControlePointsNumber, OtherAxeControlePointsNumber);
	//See explanation in figure Doc/CentralControlePointInFace.png

}

void multipatch::AddAQuarterFaceOfControlePoints(HEdge& he, int HalfEdgeIndexInFace // starts with 1
)
{
	int EdgeAxeLoopCounter = 0;
	int OtherAxeLoopCounter = 0;
	int signexI = 1, signeyI = 0, signexJ = 0, signeyJ = 1;

	ComputeQuarterLoopCounters(EdgeAxeLoopCounter, OtherAxeLoopCounter, he, HalfEdgeIndexInFace);
	for (int i=0;i<EdgeAxeLoopCounter;i++)
		for (int j = 0;j < OtherAxeLoopCounter;j++)
		{
			for (int k = 0;k < Splines[he.face - 1].AmbiantDimension;k++)
				ControleVector[k].push_back(Splines[he.face - 1].tensor2[signexI*i+ signexJ*j][signeyI*i+ signeyJ*j].getCoordinate(k));
		}
}

void multipatch::ComputeQuarterLoopCounters(int& EdgeAxeLoopCounter, int& OtherAxeLoopCounter, HEdge& he, int& HalfEdgeIndexInFace)
{
	int EdgeAxeControlePointsNumber;
	int OtherAxeControlePointsNumber;
	if (HalfEdgeIndexInFace == 1 || HalfEdgeIndexInFace == 3)
	{
		EdgeAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[0];
		OtherAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[1];
	}
	else
	{
		EdgeAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[1];
		OtherAxeControlePointsNumber = Splines[he.face - 1].BS.controlGridShape[0];
	}

	if (EdgeAxeControlePointsNumber % 2 == 0)
	{
		EdgeAxeLoopCounter = EdgeAxeControlePointsNumber / 2;
	}
	else
	{
		EdgeAxeLoopCounter = static_cast<int>(std::floor(EdgeAxeControlePointsNumber / 2) + 1);
	}
	if (OtherAxeControlePointsNumber % 2 == 0)
	{
	OtherAxeLoopCounter = OtherAxeControlePointsNumber / 2;
	}
	else
	{
	OtherAxeLoopCounter = static_cast<int>(std::floor(OtherAxeControlePointsNumber / 2) );
	}
}

void multipatch::AddCentralControlePoint(HEdge & he, int EdgeAxeControlePointsNumber, int OtherAxeControlePointsNumber)
{
	int i=static_cast<int>(std::floor(EdgeAxeControlePointsNumber / 2) + 1);
	int j= static_cast<int>(std::floor(OtherAxeControlePointsNumber / 2) + 1);
	for (int k = 0;k < Splines[he.face - 1].AmbiantDimension;k++)
		ControleVector[k].push_back(Splines[he.face - 1].tensor2[i][j].getCoordinate(k));
	
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
