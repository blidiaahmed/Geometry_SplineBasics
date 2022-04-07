#include"pch.h"
#include"tensor.h"
//template <int i>
tensor/*<i>*/::tensor(unsigned __int8 dim):dimension(dim)
{
	if (dim == 1)
	{
		vect=vector<float>();
	}
	else
	{
		//vect= vector<tensor>;
	}
}
tensor::tensor(const tensor& T) : dimension(T.dimension), vect(T.vect) {}
tensor::tensor(tensor&& T) : dimension(T.dimension), vect(T.vect) {}
tensor::tensor(unsigned __int8 dim, vector<float> v) : dimension(dim), vect(v){};
float tensor::get_value(unsigned __int8 iIndex){return vect[iIndex];}
unsigned __int8 tensor::get_dimension(){return dimension;}
vector<float> tensor::get_vector(){	return vect;}



