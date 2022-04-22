#include "pch.h"
#include "splineFunctions.h"

using namespace std;
TEST(splineFunction, constructor)
{
	spline sp;
	ASSERT_EQ(sp.getAmbiantDimension(), 1);
	sp.tensor1 = vector<float>{ 1,2 ,3,4};
	// evaluate a SPLINE  FUNCTION
	ASSERT_EQ(sp.getValue(0),1);

		

	

}