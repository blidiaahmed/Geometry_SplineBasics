#include "pch.h"
#include "splineFunctions.h"



unsigned __int8 spline::getAmbiantDimension()
{

	return AmbiantDimension;
}

point spline::Evaluate(float x)
{

	if (BS.ParametricDimension == 1)
	{
		vector<float> coordiantes;
		unsigned int controlPointsNumber = BS.getControlGridShape()[0];
		for (int i = 0;i < AmbiantDimension;i++)
		{
			vector<float > controlCoefficients;
			
			for (unsigned int j = 0;j < controlPointsNumber;j++)
			{
				controlCoefficients.push_back(tensor1[j].getCoordinate(i));
			}
			
			coordiantes.push_back(evaluate_spline(x, BS.knot[0], BS.knot[0].size(), controlCoefficients, BS.degree[0], BS.degree[0]));
		}
		point pt(coordiantes);
		return pt;
		
	}
}