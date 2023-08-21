#include "pch.h"
#include"MultiPatch.h"

#include"WriteObj.h"
#include "MeshConvert.h"
#include "ReadObj.h"

TEST(FunctionApproximation, BaseEvaluation)
{
	OBJMesh Om = ReadObj("models/tube.obj");
	multipatch mltp(ConvertObjToHEdge(Om));

	vector <float> param = vector<float>{ 0.,0. };

	int HalfEdgeIndex=1;

	int Next_HalfEdgeIndex = mltp.HalfEdge_Mesh.HalfeEdges[HalfEdgeIndex - 1].next;

	point pt = mltp.EvaluateMultipatch_EdgeBased(Next_HalfEdgeIndex, param);
	
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
	for (int j = 0;j < mltp.G0Basis.matrixCoefficients.size();j++)
	{
		mltp.ControleVector
			[0]
			[mltp.G0Basis.matrixCoefficients[j].jIdx]
		+= 1;
	}

	for(int i=0;i< mltp.ControleVector[0].size();i++)
		cout<< mltp.ControleVector[0][i] << endl;

	for (int faceIndex = 1;faceIndex <= mltp.Splines.size();faceIndex++)
	{
		vector <float> x = { 0.2,0.8 };

		cout << "faceNumber" << faceIndex << endl;
		EXPECT_EQ(mltp.EvaluateMultipatch_FaceBased(faceIndex, x).getCoordinate(0), 1) << "need to make it C0 at edges and vertices" << endl;
	}
}