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
	spline() :BS(), tensor1() {};
	spline(unsigned __int8 dim) :AmbiantDimension(dim), BS(), tensor1() {};

	//evaluation funciton

	float getValue(float p)
	{
		int knotNumber = BS.knot.size();

		
		vector<float> TheVect = tensor1;
		int Index = 1;
		int dim = 0;
		for (int CoxLevel = 0;CoxLevel< knotNumber;Index++)
		{
			float w1 = (p - BS.knot[dim][Index]) / (BS.knot[dim][Index - CoxLevel] - BS.knot[dim][Index]);
			float w2 = 1 - w1;
			TheVect[0] = TheVect[0] * w1 + TheVect[1] * w2;
		}

		return 0; 
	}
};
