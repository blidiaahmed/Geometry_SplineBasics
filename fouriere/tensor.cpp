#include"pch.h"
#include"tensor.h"
template <class T>
tensor<T>::tensor(unsigned __int8 dim):dimension(dim)
{
	
		vect=vector<float>();
	
}

//tensor::tensor(const tensor& T) : dimension(T.dimension), vect(T.vect) {}
//tensor::tensor(tensor&& T) : dimension(T.dimension), vect(T.vect) {}
//tensor::tensor(unsigned __int8 dim, vector<float> v) : dimension(dim), vect(v){};
//float tensor::get_value(unsigned __int8 iIndex){return vect[iIndex];}
//unsigned __int8 tensor::get_dimension(){return dimension;}
//vector<float> tensor::get_vector(){	return vect;}



