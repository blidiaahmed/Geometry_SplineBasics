#include"pch.h"
#include"knotInsertion_Splines.h"
#include"splineFunctions.h"


TEST(TestkontInsertion_spline, controlPointsNumber)
{
	spline sp(3);
	sp.tensor1 = vector<point>({ point({0,0,0}),point({1,0,0}),point({0,1,0}),point({1,1,1}) });
	vector<point> values;
	for (int i = 0;i < 11; i++)
	{
		values.push_back(sp.Evaluate(i / 10.0));
	}
	knotInsertion::knotInsert(sp.tensor1, sp.BS.knot[0], sp.BS.degree[0], 0.5);
	float error=0;

	for (int i = 0;i < 11; i++)
	{
		point ptt = values[i];
		point pt =values[i]-sp.Evaluate(i / 10.0);
		error += pt.getNorm();
	}
	ASSERT_NEAR(error, 0,0.001);
}