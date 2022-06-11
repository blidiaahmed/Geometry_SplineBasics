#include"pch.h"
#include"HalfeEdge.h"




point HEdgeMesh::EvaluateHEMesh(vector<float> x, int hedgeIndex)
{

	HEdge* CurrentHalfeEdge = &hedges[hedgeIndex];
	Face* currentFace = &faces[CurrentHalfeEdge->face];


	point refPoint = vertices[CurrentHalfeEdge->vertex].Point;
	point NextPoint = vertices[hedges[hedges[hedgeIndex].next].vertex].Point;
	point XAxis = NextPoint - refPoint;
	HEdge* PreviousHalfeEdge = Privious_edge_finder(CurrentHalfeEdge, currentFace);
	point PreviousPoint = vertices[PreviousHalfeEdge->vertex].Point;
	point YAxis = PreviousPoint - refPoint;


	point pt = x[0] * XAxis + x[1] * YAxis;;
	return pt;
}

HEdge* HEdgeMesh::Privious_edge_finder(HEdge* CurrentHalfeEdge, Face* currentFace)
{

	int CurrentFaceEdgeNumber = currentFace->EdgeNumber;
	HEdge* Hedge_Cursor = CurrentHalfeEdge;
	for (int counter = 1; counter < CurrentFaceEdgeNumber - 1;counter++)
	{
		Hedge_Cursor = &hedges[Hedge_Cursor->next];
	}
	return Hedge_Cursor;

}
