#include <vector>
#pragma once

#include "splineFunctions.h"
#include"point.h"
namespace knotInsertion {

	void knotInsert(vector<point>& controlePoints, vector<float>& knots, int degree, float additionalKnot);
	void knotInsert(vector<point>& controlePoints, vector<float>& knots, int degree, float knotToInsert, int intervalIndex);
	void computeNewControlePoint_knotInsertion(point& Q, int i, vector<point>& controlePoints, vector<float>& knots, int degree, float knotToInsert, int intervalIndex);
}