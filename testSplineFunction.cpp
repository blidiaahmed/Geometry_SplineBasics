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
	ASSERT_NEAR(pt.getNorm(), 1.2, 0.01)<< "\n >> this have to be confirmed, I am not sure about his answer";


}