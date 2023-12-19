#include "pch.h"
#include"MultiPatch.h"

#include"WriteObj.h"
#include "MeshConvert.h"
#include "ReadObj.h"
#include <Eigen/Dense>

float fctttt(float x, float y)
{
	return  x * y * sin(x + y);
}


TEST(FunctionApproximation, XtimesSinusFunction2)
{
	OBJMesh Om = ReadObj("models/tube.obj");
	multipatch mltp(ConvertObjToHEdge(Om));
	multipatch mltp1(ConvertObjToHEdge(Om));

	mltp.CreateControleVector();
	mltp1.CreateControleVector();
	mltp.CreateG0Basis();

	mltp.BasisToControlVector();
	mltp.RebuildSplinesFromControlVector();
}

