#include "pch.h"
#include "point.h"
#include "BSpline.h"
#include "tensor.h"


class spline
{
	BSpline BS;
	tensor /*<BS.dimension>*/ Tensor;
public:
	spline(tensor Tensr); 

	unsigned __int8 get_dimension();

	
};
