#include "pch.h"
#include "splineFunctions.h"

using namespace std;
TEST(splineFunction, constructor)
{
	unsigned int dimension = 1;
	vector<unsigned int> degree(1);
	degree [0]= 3;
	BSpline BS(dimension,degree);
	vector<float> v = { 0 ,0,0,0 };
	tensor Tensr(v);
	spline sp(Tensor);
	EXPECT_EQ(Tensor.get_dimension(), sp.get_dimension());
	Spline sp(BS);

	//EXPECT_EQ(sp(v), 0); 
	EXPECT_EQ()


}