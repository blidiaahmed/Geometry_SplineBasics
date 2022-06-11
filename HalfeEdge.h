#pragma once

#include"point.h"
#include <iostream>
using namespace std;

class Vertex
{
public:
	int HalfEdge;
	//additional
	
	point Point;

};
class HEdge
{
public:
	int twin;// null if boundary edge
	int next;
	int vertex;
	int face;
	set<int> Edge; 
	HEdge() {
		twin = 0;
		next=0;
		vertex=0;
		face=0;
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
	int HEdge;
	int EdgeNumber;
};

class HEdgeMesh
{
public:
	vector<Vertex> vertices;
	vector<HEdge> hedges;
	vector<Face> faces;
	//vector<edge> edges;
	map<set<int>,edge> edges;
	set<set<int>> SetEdges;//two coordinates for vertex index, and the last gives the edge index

	
	point EvaluateHEMesh(vector<float> x, int hedgeIndex);
	HEdge* HEdgeMesh::Privious_edge_finder(HEdge* CurrentHalfeEdge, Face* currentFace);
};

