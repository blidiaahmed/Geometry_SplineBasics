#pragma once

#include "HalfeEdge.h"
#include"splineFunctions.h"


class multipatch
{
public:
	HalfEdgeMesh HalfEdge_Mesh;
	vector<spline> Splines;

	multipatch(HalfEdgeMesh &hem);


};

void Interpolation_QuadPatch(int face, HalfEdgeMesh hem, spline& sp);
void Interpolation_QuadPatch(vector<int> pointsIndeces, HalfEdgeMesh hem, spline& sp);

void interpolation_4points(vector<point> FacePoints, spline & sp);