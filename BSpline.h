#ifndef BSpline_H
#define BSpline_H
using namespace std;
class BSpline
{
	

public:
	unsigned int ParametricDimension;
	vector<unsigned int> degree;
	vector<vector<float>> knot;
	vector<unsigned int> controlGridShape;

	void computeControlGridShape();
	void computePolynomialKnotsDistribution();
	vector<vector<float>> BSpline::multivariatePolynomialKnotDistribution(
		unsigned int dim, vector<unsigned int>& deg);
	//contructors

	BSpline();
	BSpline(unsigned __int8 dim);
	BSpline(unsigned int dim, vector<unsigned int>& deg);
	BSpline(unsigned int dim, vector<unsigned int>& deg,vector<vector<float>> knts);
	//getters
	vector<float> getKnots(unsigned int axIndex);
	unsigned int getDimension();
	vector<unsigned int >getDegree();
	vector<unsigned int> getControlGridShape();
	

	//setters
	void setDimension(unsigned int);
	

};

vector<float>& UnivariatePolynomialKnotDistribution(int deg, vector<float>& knts);
#endif //BSpline_H