#pragma once

#include "pch.h"
//#include <stdio.h>
using namespace std;
//template <int i>
class tensor
{
	
	
public:
	unsigned __int8 dimension;
	vector<float> vect;
	tensor(unsigned __int8);
	tensor(const tensor& T);
	tensor(tensor&& T);
	tensor(unsigned __int8 , vector<float>);

	//getters
	float get_value(unsigned __int8);
	unsigned __int8 get_dimension();
	vector<float> get_vector();
	
};
