#include "pch.h"
#include "tensor.h"
#include "BSpline.h"
using namespace std;


TEST(Tensors, UniDimensionnalTensor)
{
	const unsigned __int8 dim=1;
	RecursiveVector<float> Tensor(dim);
	EXPECT_EQ(Tensor.dimension, 1);
	
}

TEST(Tensors, BiDimensionnalTensor)
{
	const unsigned __int8 dim = 2;
	RecursiveVector<RecursiveVector<float>> Tensor(dim);
	EXPECT_EQ(Tensor.dimension, 2);
	tensor1<1,float> ten();

}

