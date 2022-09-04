#pragma once

#include "HalfeEdge.h"
#include"splineFunctions.h"


class multipatch
{
public:
	HalfEdgeMesh HalfEdge_Mesh;
	vector<spline> Splines;
	vector<vector<float>> ControleVector;
	multipatch(HalfEdgeMesh &hem);
	void CreateControleVector();
	void AddQuadFaceControlePoints(Face& f);
	void AddAQuarterFaceOfControlePoints(HEdge& he, int HalfEdgeIndexInFace);
	void ComputeQuarterLoopCounters(int& EdgeAxeLoopCounter,int& OtherAxeLoopCounter, HEdge& he, int& HalfEdgeIndexInFace);
	void AddCentralControlePoint(HEdge & he, int EdgeAxeControlePointsNumber, int OtherAxeControlePointsNumber);
};

void Interpolation_QuadPatch(int face, HalfEdgeMesh hem, spline& sp);
void Interpolation_QuadPatch(vector<int> pointsIndeces, HalfEdgeMesh hem, spline& sp);

void interpolation_4points(vector<point> FacePoints, spline & sp);