#include "pch.h"
#include "splineFunctions.h"

using namespace std;



TEST(splineFunction, SplineObject3D)
{
	spline sp(3);
	sp.tensor1.push_back(point({ 1,1,1 }));
	sp.tensor1.push_back(point({ 1,1,0 }));

	sp.tensor1.push_back(point({ 1,0,1 }));

	sp.tensor1.push_back(point({ 0,1,1 }));
	point pt (sp.Evaluate(0.5));
	ASSERT_EQ(pt.getNorm(), 0, 0.01);


}