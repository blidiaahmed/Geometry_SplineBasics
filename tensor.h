#pragma once

#include "pch.h"

using namespace std;
template<class T>
class RecursiveVector
{
public:
	unsigned __int8 dimension;
	vector<T> vect;
	RecursiveVector(unsigned __int8 dim):dimension(dim) {
		vect = vector<T>();
	};
	//tensor(const tensor& T);
	//tensor(tensor&& T);
	//tensor(unsigned __int8 , vector< >);

	////getters
	//float get_value(unsigned __int8);
	//unsigned __int8 get_dimension();
	//vector<float> get_vector();
	
};


//template class RecursiveVector<float>;
//template class RecursiveVector<RecursiveVector<float>>;
//template class RecursiveVector<RecursiveVector<RecursiveVector<float>>>;

template<int dim,class T>
class tensor1 
{
public:
	RecursiveVector<T> ten;
	
};

