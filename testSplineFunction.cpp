#include "pch.h"
#include "splineFunctions.h"

using namespace std;

TEST(splineFunction, SplineCurve3D)
{
	spline sp(3);
	sp.tensor1.push_back(point({ 1,1,1 }));
	sp.tensor1.push_back(point({ 1,1,0 }));

	sp.tensor1.push_back(point({ 1,0,1 }));

	sp.tensor1.push_back(point({ 0,1,1 }));
	point pt (sp.Evaluate(0.5));
	EXPECT_NEAR(pt.getNorm(), 1.2437, 0.01);


}

TEST(splineFunction, SplineCurve3D_KnotInsertion)
{
	spline sp(3);
	sp.tensor1 = vector<point>({ point({0,0,0}),point({1,0,0}),point({0,1,0}),point({1,1,1}) });
	vector<point> values;
	for (int i = 0;i < 11; i++)
	{
		values.push_back(sp.Evaluate(i / 10.0));
	}

	sp.knotInsert(0.5, 0);
	float error = 0;

	for (int i = 0;i < 11; i++)
	{
		point ptt = values[i];
		point pt = values[i] - sp.Evaluate(i / 10.0);
		error += pt.getNorm();
	}
	ASSERT_NEAR(error, 0, 0.001);
}


TEST(splineFunction, SplineSurface3D)
{
	spline sp(3);
	sp.BS= BSpline(2);
	sp.tensor2 = vector<vector<point>> 
	{
		vector<point>{point({ 0,0,1 }), point({ 1,0,1 }), point({ 2,0,1 }), point({ 3,0,1 }) },
			vector<point>{point({ 0,1,1 }), point({ 1,1,1 }), point({ 2,1,1 }) , point({ 3,1,1 }) },
			vector<point>{point({ 0,2,1 }), point({ 1,2,1 }), point({ 2,2,1 }), point({ 3,2,1 })},
	vector<point>{point({ 0,3,1}), point({1,3,1}), point({2,3,1}), point({3,3,1})}
	};
	point pt(sp.Evaluate({ 0,0}));
	point pt1(sp.Evaluate({ 0.5,0.5 }));
	point pt2(sp.Evaluate({ 0.75,0.25 }));
	EXPECT_NEAR(pt.getNorm(), 1., 0.01);
	EXPECT_NEAR(pt1.getNorm(), 2.34, 0.01);
	EXPECT_NEAR(pt2.getNorm(), 2.57, 0.01);


}