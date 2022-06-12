#include"pch.h"
#include"MeshConvert.h"
#include"HalfeEdge.h"




HalfeEdgeMesh::HalfeEdgeMesh(OBJMesh Om)
{
	*this= ConvertObjToHEdge(Om);
}

point HalfeEdgeMesh::EvaluateHEMesh(vector<float> x, int hedgeIndex)
{

	HEdge* CurrentHalfeEdge = &HalfeEdges[hedgeIndex-1];
	Face* currentFace = &faces[CurrentHalfeEdge->face-1];


	point refPoint = vertices[CurrentHalfeEdge->vertex-1].Point;
	point NextPoint = vertices[HalfeEdges[HalfeEdges[hedgeIndex-1].next-1].vertex-1].Point;
	point XAxis = NextPoint - refPoint;
	HEdge* PreviousHalfeEdge = Privious_edge_finder(CurrentHalfeEdge, currentFace);
	point PreviousPoint = vertices[PreviousHalfeEdge->vertex].Point;
	point YAxis = PreviousPoint - refPoint;


	point pt = x[0] * XAxis + x[1] * YAxis;;
	return pt;
}

HEdge* HalfeEdgeMesh::Privious_edge_finder(HEdge* CurrentHalfeEdge, Face* currentFace)
{

	int CurrentFaceEdgeNumber = currentFace->EdgesNumber;
	HEdge* Hedge_Cursor = CurrentHalfeEdge;
	for (int counter = 1; counter < CurrentFaceEdgeNumber - 1;counter++)
	{
		Hedge_Cursor = &HalfeEdges[Hedge_Cursor->next-1];
	}
	return Hedge_Cursor;

}
