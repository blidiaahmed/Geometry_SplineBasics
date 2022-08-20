
read "src/symbolicTensorSpline.mpl";
with(Student[LinearAlgebra]);

ValuesAtEdge := proc(axe, Valence, ControlePoints, knotsLists, degrees, ControleGridShape) 
local TotaleFunction, ValuesAtEdge, i; TotaleFunction := SymbolicTensorSpline(u, v, ControlePoints, knotsLists, degrees); 
if axes = 1 then ValuesAtEdge := Vector([seq(TotaleFunction[i][1], i = 1 .. nops(TotaleFunction))]); 
else ValuesAtEdge := Vector([seq(TotaleFunction[1][i], i = 1 .. Student:-LinearAlgebra:-Dimension(TotaleFunction[1]))]);
end if;
return ValuesAtEdge;
end proc;

ValueAtEdgeFunctions := proc(Valence, knotsLists, degrees, ControleGridShape) 
local F1ControlePoints, i, j, F2ControlePoints, F1function, F2function, F1ValuesAtEdge, F2ValuesAtEdge; 

F1ControlePoints := [seq([seq(f[1][i, j], j = 0 .. ControleGridShape)], i = 0 .. ControleGridShape)]; 
F2ControlePoints := [seq([seq(f[2][i, j], j = 0 .. ControleGridShape)], i = 0 .. ControleGridShape)]; 

F1function := SymbolicTensorSpline(u, v, F1ControlePoints, knotsLists, degrees); 
F2function := SymbolicTensorSpline(u, v, F2ControlePoints, knotsLists, degrees); 

F1ValuesAtEdge := Vector([seq(F1function[i][1], i = 1 .. nops(F1function))]); 
F2ValuesAtEdge := Vector([seq(F2function[1][i], i = 1 .. Student:-LinearAlgebra:-Dimension(F2function[1]))]); 
return F1ValuesAtEdge, F2ValuesAtEdge; end proc;

G0Conditions := proc(F1ValuesAtEdge, F2ValuesAtEdge) 
local G0Expression, sys, i, j; 
G0Expression := subs([v = 0], F1ValuesAtEdge) - subs(v = u, subs([u = 0], F2ValuesAtEdge));
 sys := [];
for i to Student:-LinearAlgebra:-Dimension(G0Expression) do 
 for j from 0 to degree(G0Expression[i], u) do 
 sys := [op(sys), coeff(G0Expression[i], u, j)];
 end do; end do;
 return sys; 
 end proc;

G1Conditions := proc(F1ValuesAtEdge, F2ValuesAtEdge)
 local c, G1Expression, sys, i, j;
  c := cos(2*pi/valence);
  a(u) := 2*c*(1 - u)^2;
  b(u) := -1; 
  G1Expression := subs(v = 0, diff(F1ValuesAtEdge, u)) - a(u)*subs(v = u, subs([u = 0], diff(F2ValuesAtEdge, v))) - b(u)*subs(v = u, subs([u = 0], diff(F2ValuesAtEdge, u)));
  sys := []; 
  for i to Student:-LinearAlgebra:-Dimension(G1Expression) do 
for j from 0 to degree(G1Expression[i], u) do 
sys := [op(sys), coeff(G1Expression[i], u, j)]; 
end do; 
end do;
 return sys; end proc;

VanishAtVertex := proc(F1ValuesAtEdge, F2ValuesAtEdge) 
local sys, Expression, i; 
sys := []; 
Expression := subs([v = 0, u = 0], F1ValuesAtEdge); 
sys := [op(sys), Expression[1]]; 
Expression := subs([v = 0, u = 0], F2ValuesAtEdge);
sys := [op(sys), Expression[1]]; 
Expression := subs([v = 0, u = 1], F1ValuesAtEdge); 
sys := [op(sys), Expression[Student:-LinearAlgebra:-Dimension(Expression)]]; 
Expression := subs([v = 1, u = 0], F2ValuesAtEdge); 
sys := [op(sys), Expression[Student:-LinearAlgebra:-Dimension(Expression)]]; 
return sys;
 end proc;


