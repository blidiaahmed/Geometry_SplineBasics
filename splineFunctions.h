#include "pch.h"
#include "point.h"
#include "BSpline.h"
#include "tensor.h"

template <int i>
class spline
{
	BSpline BS;
	//tensor <i> Tensor;
public:
	spline(RecursiveVector Tensr); 

	unsigned __int8 get_dimension();

	
};
