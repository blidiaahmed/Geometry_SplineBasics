#include "pch.h"
#include "point.h"
#include "BSpline.h"



class spline
{
public:
	BSpline BS;

	vector<float> tensor1;
	vector<vector<float>> tensor2;
	vector<vector<vector<float>>> tensor3;

	unsigned __int8 AmbiantDimension = 1;

	unsigned __int8 getAmbiantDimension();
	spline():BS(), tensor1() {}
	spline(unsigned __int8 dim) :AmbiantDimension(dim),BS(), tensor1() {}
};
