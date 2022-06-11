#include"pch.h"
#include "MeshConvert.h"


TEST(MeshConvert, objToHEdgeMesh)
{
	HEdgeMesh hem;

	OBJMesh Om = ReadObj("models/SimpleTest.obj");
	EXPECT_EQ(Om.faces.size(), 3);
	EXPECT_EQ(Om.points.size(), 4);
	

}