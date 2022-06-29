#include "pch.h"
#include "knotInsertion_Splines.h"
namespace knotInsertion {
	void knotInsert(vector<point>& controlePoints, vector<float>& knots, int degree, float knotToInsert)
	{
		int intervalIndex = SelectIntervalIndex(knotToInsert, knots);
		knotInsert(controlePoints, knots, degree, knotToInsert, intervalIndex);
	}
	void knotInsert(vector<point>& controlePoints, vector<float>& knots, int degree, float knotToInsert, int intervalIndex)
	{
		vector<point> newControlepoints;
		for (int i = intervalIndex - degree + 1; i <= intervalIndex; i++)
		{
			point Q;
			computeNewControlePoint_knotInsertion(Q, i,
				controlePoints,
				knots,
				degree,
				knotToInsert,
				intervalIndex);
			newControlepoints.push_back(Q);
		}

		for (int i = intervalIndex - degree + 1; i < intervalIndex; i++)
		{
			controlePoints[i] = newControlepoints[i - intervalIndex + degree - 1];
		}

		int i = intervalIndex;
		vector<point>::iterator  it_controlePoints = controlePoints.begin();
		controlePoints.insert(it_controlePoints + i, newControlepoints.back());

		vector<float>::iterator  it = knots.begin();
		knots.insert(it + intervalIndex + 1, knotToInsert);

	}

	void computeNewControlePoint_knotInsertion(point& Q, int i,
		vector<point>& controlePoints,
		vector<float>& knots, int degree,
		float knotToInsert, int intervalIndex)
	{
		float a = (knotToInsert - knots[i]) / (knots[i + degree] - knots[i]);
		Q = (1 - a) * controlePoints[i - 1] + a * controlePoints[i];

	}
}