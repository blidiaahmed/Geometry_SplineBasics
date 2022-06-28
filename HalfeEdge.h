#include <iostream>

#pragma once

#include"point.h"
#include "OBJMesh.h"
using namespace std;

class Vertex
{
public:
	int HalfEdge = -1;
	//additional
	
	point Point;

};
class HEdge
{
public:
	int twin = -1;// null if boundary edge
	int next = -1;
	int vertex = -1;
	int face = -1;
	set<int> Edge; 
	HEdge() {
		Edge = {};
	}

};

class edge
{
public:
	int HEdge;
	//additional
	/*set<int> vertices;
	int index;*/

};
class Face
{
public:
	int HEdge=-1;
	int EdgesNumber = -1;
};

class HalfEdgeMesh
{
public:
	vector<Vertex> vertices;
	vector<HEdge> HalfeEdges;
	vector<Face> faces;
	//vector<edge> edges;
	map<set<int>,edge> edges;
	set<set<int>> SetEdges;//two coordinates for vertex index, and the last gives the edge index
	//constructor
	HalfEdgeMesh() = default;
	HalfEdgeMesh(OBJMesh Om);
	
	point EvaluateHEMesh(vector<float> x, int hedgeIndex);
	HEdge* HalfEdgeMesh::Privious_Hedge_finder(HEdge* CurrentHalfeEdge, Face* currentFace);
};

