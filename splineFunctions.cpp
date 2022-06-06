#include "pch.h"
#include "splineFunctions.h"



unsigned __int8 spline::getAmbiantDimension()
{

	return AmbiantDimension;
}

point spline::Evaluate(float x)
{


		vector<float> OutputCoordiantes;
		unsigned int controlPointsNumber = BS.getControlGridShape()[0];
		for (int i = 0;i < AmbiantDimension;i++)
		{
			vector<float > controlCoefficients;
			
			for (unsigned int j = 0;j < controlPointsNumber;j++)
			{
				controlCoefficients.push_back(tensor1[j].getCoordinate(i));
			}
			
			OutputCoordiantes.push_back(evaluateSpline(x, BS.knot[0], BS.knot[0].size(), controlCoefficients, BS.degree[0], BS.degree[0]));
		}
		point pt(OutputCoordiantes);
		return pt;
		
}



point spline::Evaluate(vector<float> x)
{
	vector<int > m;
	vector < int> p;
	for (int i = 0;i < BS.ParametricDimension;i++)
	{
		m.push_back(BS.knot[i].size());
		p.push_back((int) BS.degree[i]);

	}

	point pt (evaluateTensorSpline(x, BS.knot,m, tensor2,p ));
	return pt;

	
}