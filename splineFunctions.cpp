#include "pch.h"
#include "splineFunctions.h"
#include "tensor.h"
//spline::spline(tensor Tensr) :BS(Tensr.get_dimension()),Tensor(Tensr) {}
template <int i>
unsigned __int8 spline<i>::get_dimension()
{

	return Tensor.get_dimension();
}
