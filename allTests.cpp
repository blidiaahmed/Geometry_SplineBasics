#include "pch.h"

#include "testBSpline.cpp"
#include "testSplineFunction.cpp"
#include"testConvert.cpp"


void main(int argc, char* argv[])
{
	

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	
	
}