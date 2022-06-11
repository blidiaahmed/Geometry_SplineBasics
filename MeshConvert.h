#pragma once
#include"HalfeEdge.h"
#include "OBJMesh.h"
void CopyPoints(OBJMesh& Om, HEdgeMesh& HEM);
HEdgeMesh ConvertObj2HEdge(OBJMesh Om)
{
	HEdgeMesh HEM;


	// copy points
	CopyPoints(Om, HEM);

	for (vector<int>& fc : Om.faces)
	{
		HEM.faces.push_back( Face());
		Face& CurrentFace = HEM.faces[HEM.faces.size() - 1];
		CurrentFace.EdgeNumber = HEM.faces.size();
		for (int index = 0;index < fc.size() ;index++)
		{
			HEdge he;
			he.vertex = fc[index];
			
			
			//compute the edge
			int  nextIndex = (index < fc.size()-1) ? index + 1 : 0;
			set<int> EdgeVerticesSet = {fc[index],fc[nextIndex]};

			//
			he.Edge = EdgeVerticesSet;

			//find the edge
			set<set<int>>::iterator it=HEM.SetEdges.find(EdgeVerticesSet);
			
			if (it == HEM.SetEdges.end())
			{
				HEM.SetEdges.insert(EdgeVerticesSet);
				HEM.edges[EdgeVerticesSet ]=edge();
				HEM.edges[EdgeVerticesSet ].HEdge = HEM.hedges.size() + 1;
				//in this case the twin is not known yet (and may not exist if boundary edge)
			}
			else
			{
				// in this case the twin is known and need to be linked to the current hedge
				he.twin = HEM.edges[EdgeVerticesSet ].HEdge;
				HEM.hedges[HEM.edges[EdgeVerticesSet].HEdge - 1].twin= HEM.hedges.size();
			}
			//next half edge
			he.next = HEM.hedges.size() + 2;

			// put the halfe edge in the hEmeshdata structure
			HEM.hedges.push_back(move(he));
			HEM.vertices[fc[index]-1].HalfEdge = HEM.hedges.size()+1;
			if (index == 0)
			{
				CurrentFace.HEdge = HEM.hedges.size()+1;
			}
		}
	}
	
	return HEM;
}


void CopyPoints(OBJMesh& Om, HEdgeMesh& HEM)
{
	for (point pt : Om.points)
	{
		Vertex vrt;

		vrt.Point = pt;
		vrt.HalfEdge = -1;
		HEM.vertices.push_back(vrt);

	}
}