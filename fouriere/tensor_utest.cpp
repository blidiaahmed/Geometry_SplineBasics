#include "pch.h"
#include "tensor.h"
#include "BSpline.h"
using namespace std;

//TEST(Tensor, Basics)
//{
//	vector<float> v{0,2,2};
//	unsigned __int8 dim = 1;
//	tensor Tensor(dim,v);
//	EXPECT_EQ(Tensor.get_value(0), 0);
//	EXPECT_EQ(Tensor.get_dimension(), 1);
//	dim = Tensor.get_dimension();
//	tensor Tensor2(Tensor);
//	EXPECT_EQ(Tensor.get_value(1), Tensor2.get_value(1)); 
//
//	EXPECT_EQ(Tensor.get_vector()[0], Tensor2.get_vector()[0]);
//	
//}

//TEST(Tensors, MultiDimensionnalTensor)
//{
//	unsigned __int8 dim=2;
//	tensor<float> Tensor(dim);
//	EXPECT_EQ(Tensor.dimension, 2);
//}