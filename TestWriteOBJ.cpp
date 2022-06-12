#include"pch.h"
#include <string>

#include"WriteObj.h"
#include"OBJMesh.h"
#include"splineFunctions.h"
using namespace std;

TEST(WriteOBJ, OneTriangle)
{
	
	std::string str = "OBJfile.obj";
	OBJMesh Om;
	// 3 cordinates for position, then normals, then tesxture
	Om.points = { point({0,0,0,1,2,4,1,2,3}),point({0,0,1,1,2,3,1,2,3}),point({0,1,0,1,2,3,1,2,3}) };

	Om.faces = { {1,2,3}};
	WriteOBJ(str,Om);
	
	// debug
	// system("meshlab OBJfile.obj");

}

TEST(WriteOBJ, SplineSurface)
{
	spline sp(3);
	sp.BS = BSpline(2);
	sp.tensor2 = vector<vector<point>>
	{
		vector<point>{point({ 0,0,1 }), point({ 1,0,1 }), point({ 2,0,1 }), point({ 3,0,1 }) },
			vector<point>{point({ 0,1,1 }), point({ 1,1,1 }), point({ 2,1,1 }) , point({ 3,1,1 }) },
			vector<point>{point({ 0,2,1 }), point({ 1,2,1 }), point({ 2,2,1 }), point({ 3,2,1 })},
	vector<point>{point({ 0,3,1}), point({1,3,1}), point({2,3,1}), point({3,3,1})}
	};

	for (vector<point> &vect : sp.tensor2)
		for (point &pt : vect)
			pt.X[2] =(pt.X[0]+pt.X[1])*sin(20* pt.X[1])*cos(20* pt.X[0]);
	int precision = 20;
	OBJMesh Om=sp.ProduceOBJMesh(precision);

	string str = "objfile.obj";
	WriteOBJ(str, Om);

	//system("meshlab objfile.obj");
}

