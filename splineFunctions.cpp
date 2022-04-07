#include "pch.h"
#include "splineFunctions.h"
#include "tensor.h"
//spline::spline(tensor Tensr) :BS(Tensr.get_dimension()),Tensor(Tensr) {}

unsigned __int8 spline::get_dimension()
{

	return Tensor.get_dimension();
}
