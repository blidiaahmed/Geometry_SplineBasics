#ifndef POINT_H
#define POINT_H

#include"pch.h"
using namespace std;
class point
{
	unsigned int dimension;
	vector<float> X;
public:
	point();
	point(int dim);
	point(vector<float>& x);
	unsigned int getDimension();
	float getCoordinate(unsigned int);
	vector<float>& getVector();
	void setCoordinate(unsigned int, float);

	point operator -() ;
};
point operator * (float fl, point& pt);
point operator * (point& pt, float fl);
point operator + (point& pt1, point& pt2);
point operator -(point& pt1, point& pt2);
#endif //POINT_H