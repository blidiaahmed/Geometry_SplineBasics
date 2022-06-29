#include "pch.h"
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
