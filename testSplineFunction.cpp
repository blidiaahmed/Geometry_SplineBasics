#include "pch.h"
#include "splineFunctions.h"

using namespace std;
TEST(splineFunction, constructor)
{
	spline sp;
	ASSERT_EQ(sp.getAmbiantDimension(), 1);
	sp.tensor1;
	sp.tensor1.push_back({ 1 });
	sp.tensor1.push_back({ 1 });
	sp.tensor1.push_back({ 3. });
	sp.tensor1.push_back({ 2.});

}