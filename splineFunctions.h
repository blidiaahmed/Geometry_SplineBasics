#include <vector>
#pragma once 
#include "pch.h"
#include"OBJMesh.h"
#include "point.h"
#include "BSpline.h"
#include"Maths.h"
using namespace std;
class spline
{
public:
	BSpline BS;


	vector<point> tensor1;
	vector<vector<point>> tensor2;

	unsigned __int8 AmbiantDimension = 1;

	unsigned __int8 getAmbiantDimension();
	// Constructors
	spline() :BS(), tensor1() {};
	spline(unsigned __int8 dim) :AmbiantDimension(dim), BS() 
	{
		if (AmbiantDimension == 1) tensor1=vector<point>();
		else tensor1= vector<point>();
	};
	
	
	//evaluation function
	point Evaluate(float x);
	point Evaluate(vector<float> x);

	//produce mesh
	OBJMesh ProduceOBJMesh();
	OBJMesh ProduceOBJMesh(int precision);
};



