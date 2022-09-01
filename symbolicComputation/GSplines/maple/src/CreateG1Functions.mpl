
read "src/G1Conditions.mpl";
with(Student[LinearAlgebra]);

CreateG1EdgeFuction := proc(Valence, knotsLists, degrees, ControleGridShape) 
local F1ControlePoints, i, j, F2ControlePoints, axe, F1ValuesAtEdge, F2ValuesAtEdge, sys, sol;
F1ControlePoints := [seq([seq(f[1][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)]; 
F2ControlePoints := [seq([seq(f[2][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)];
axe := 1;
F1ValuesAtEdge := ValuesAtEdge(axe, Valence, F1ControlePoints, knotsLists, degrees, ControleGridShape); 
axe := 2;
F2ValuesAtEdge := ValuesAtEdge(axe, Valence, F2ControlePoints, knotsLists, degrees, ControleGridShape); 
sys := G0Conditions(F1ValuesAtEdge, F2ValuesAtEdge); 
sys := [op(sys), op(G1Conditions(F1ValuesAtEdge, F2ValuesAtEdge))];
sys := [op(sys), op(VanishAtVertex(F1ValuesAtEdge, F2ValuesAtEdge))]; 
sys := [op(sys), op(InteriorCoefficientsVanishing(F2ControlePoints))];
sys := [op(sys), op(InteriorCoefficientsVanishing(F1ControlePoints))];
sol := solve(sys, indets([F1ControlePoints, F2ControlePoints])); 
return sol; 
end proc;


CreateG1VertexFuction := proc(Valence, knotsLists, degrees, ControleGridShape)
  local F1ControlePoints, i,k, j, F2ControlePoints, axe, F1ValuesAtEdge, F2ValuesAtEdge, sys, sol, FControlePoints;
  FControlePoints := [];
  for k to valence do
    FControlePoints := [op(FControlePoints), [seq([seq(f[k][i, j], j = 0 .. ControleGridShape - 1)], i = 0 .. ControleGridShape - 1)]]; 
  end do;

  F1ValuesAtEdge := []; 
  F2ValuesAtEdge := [];
  sys:=[];
  for i to Valence - 1 do
    axe := 1;
    F1ValuesAtEdge := ValuesAtEdge(axe, Valence, FControlePoints[i], knotsLists, degrees, ControleGridShape);
    axe := 2; 
    F2ValuesAtEdge := ValuesAtEdge(axe, Valence, FControlePoints[i + 1], knotsLists, degrees, ControleGridShape);
    sys := [op(sys), op(G0Conditions(F1ValuesAtEdge, F2ValuesAtEdge))]; 
    sys := [op(sys), op(G1Conditions(F1ValuesAtEdge, F2ValuesAtEdge))]; 
    sys := [op(sys), op(VanishCapBorder(FControlePoints[i]))]; 
    sys := [op(sys), op(InteriorCoefficientsVanishing(FControlePoints[i]))]; 

  end do; 
  axe := 1; 
  F1ValuesAtEdge := ValuesAtEdge(axe, Valence, FControlePoints[valence], knotsLists, degrees, ControleGridShape);
  axe := 2; 
  F2ValuesAtEdge := ValuesAtEdge(axe, Valence, FControlePoints[1], knotsLists, degrees, ControleGridShape);
  sys := [op(sys), op(G0Conditions(F1ValuesAtEdge, F2ValuesAtEdge))]; 
  sys := [op(sys), op(G1Conditions(F1ValuesAtEdge, F2ValuesAtEdge))]; 
  sys := [op(sys), op(VanishCapBorder(FControlePoints[valence]))];
  sys := [op(sys), op(InteriorCoefficientsVanishing(FControlePoints[valence]))];
  
  sol := solve(sys, indets(FControlePoints)); 

  return sol;
end proc;



VanishCapBorder:=proc(ControleGrid)
  local sys,i,j;
  sys:=[];
  for i from nops(ControleGrid)-1 to nops(ControleGrid) do
    for j from 1 to nops(ControleGrid[1]) do
      sys:=[op(sys),ControleGrid[i,j]];
    end do;
  end do;

  for j from nops(ControleGrid[1])-1 to  nops(ControleGrid[1]) do
    for i from 1 to nops(ControleGrid) do
      sys:=[op(sys),ControleGrid[i,j]];
    end do;
  end do;

  return sys;
end proc:


InteriorCoefficientsVanishing:=proc(ControleGrid)
  local sys,i,j;
  sys:=[];
  for i from 3 to nops(ControleGrid)-2 do
    for j from 3 to nops(ControleGrid[1])-2 do
      sys:=[op(sys),ControleGrid[i,j]];
    end do;
  end do;

  return sys;
end proc: