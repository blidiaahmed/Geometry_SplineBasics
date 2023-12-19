#include "pch.h"
#include"MultiPatch.h"

#include"WriteObj.h"
#include "MeshConvert.h"
#include "ReadObj.h"


TEST(FunctionApproximation, ComputeHEdgesList_ArroundAVertex)
{
	OBJMesh Om = ReadObj("models/tube.obj");
	multipatch mltp(ConvertObjToHEdge(Om));
	int numberof3vertices = 0;
	int numberof1vertices = 0;
	int numberof2vertices=0;
	for (int i = 0; i < mltp.HalfEdge_Mesh.vertices.size(); i++)
	{

		Vertex vtx = mltp.HalfEdge_Mesh.vertices[i];

		int HE_Nb = mltp.ComputeHEdgesIndexesList_ArroundAVertex(vtx).size();
		if (HE_Nb == 3)numberof3vertices++;
		if (HE_Nb == 1)numberof1vertices++;
		if (HE_Nb == 2)numberof2vertices++;

	}

	EXPECT_EQ(numberof2vertices, 4);
	EXPECT_EQ(numberof3vertices, 4);
}


TEST(FunctionApproximation, BaseEvaluation)
{

	OBJMesh Om = ReadObj("models/tube.obj");
	multipatch mltp(ConvertObjToHEdge(Om));

	
	
	mltp.CreateControleVector();

	mltp.CreateG0Basis();

	//Number of basis elements
	EXPECT_EQ(mltp.G0Basis.shape1, 52);

	//Partition of the unity Test
	//take the sum of all basis elements and evaluate it at random parameters
	
	for (int i = 0;i < mltp.ControleVector[0].size();i++)
	{
		mltp.ControleVector[0][i] = 0;
	}
	for (int k = 0;k < mltp.G0Basis.matrixCoefficients.size();k++)
	{
		mltp.ControleVector
			[0]
			[mltp.G0Basis.matrixCoefficients[k].jIdx]
		+= 1;
	}
	/*cout << "coefficients of the CV" << endl;
	for (int i = 0;i< mltp.ControleVector[0].size();i++)
		cout<<"****"<<i<<"***" << mltp.ControleVector[0][i] << endl;
		*/
	mltp.RebuildSplinesFromControlVector();
	for (int faceIndex = 1;faceIndex <= mltp.Splines.size();faceIndex++)
	{
		vector <float> x = { 0.2,0.8 };

		EXPECT_EQ(mltp.EvaluateMultipatch_FaceBased(faceIndex, x).
			getCoordinate(0), 1);
	}
}
