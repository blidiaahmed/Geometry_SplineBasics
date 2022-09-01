read "src/CreateG1Functions.mpl";
valence := 4;
degrees := [6,6];

knotsLists := [[seq(0, i = 0 .. degrees[1]), seq(1, i = 0 .. degrees[1])],[seq(0, i = 0 .. degrees[2]), seq(1, i = 0 .. degrees[2])]];

ControleGridShape := degrees[1]+1;

F1ControlePoints := [seq([seq(f[1][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)]; 
F2ControlePoints := [seq([seq(f[2][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)];

axe := 1;
F1ValuesAtEdge := ValuesAtEdge(axe, Valence, F1ControlePoints, knotsLists, degrees, ControleGridShape);
axe := 2;
F2ValuesAtEdge := ValuesAtEdge(axe, Valence, F2ControlePoints, knotsLists, degrees, ControleGridShape);

sys:=G0Conditions(F1ValuesAtEdge, F2ValuesAtEdge);
sys:=[op(sys),op(G0Conditions(F1ValuesAtEdge, F2ValuesAtEdge))];

sol := simplify(solve(sys,indets([F1ControlePoints, F2ControlePoints])));

val1:=subs(sol,f[2][0, 2]-f[1][2, 0]);

with(CodeTools);
Test(val1, 0);
