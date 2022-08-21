
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
sol := solve(sys, indets([F1ControlePoints, F2ControlePoints])); 
return sol; 
end proc;