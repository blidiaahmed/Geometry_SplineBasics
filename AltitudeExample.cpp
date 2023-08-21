#include "pch.h"

#include "png/CImg.h"

#include"OBJMesh.h"


TEST(Examples, AltitudeExample)
{

	OBJMesh Om;
	//prepare the image
	string str = "models/CarteAltitude.bmp";

	// The Following is a time consuming part
	// You can execute it whene needed
	//PngToPointCloud(str, Om);
	//WriteOBJ("models/test.obj", Om);
	//system("meshlab models/test.obj");
	float Error = 1;
	EXPECT_NEAR(Error, 0, 0.01);
}

