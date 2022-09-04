read "src/CreateG1Functions.mpl";
valence := 3;
degrees := [6,6];

knotsLists := [[seq(0, i = 0 .. degrees[1]), seq(1, i = 0 .. degrees[1])],[seq(0, i = 0 .. degrees[2]), seq(1, i = 0 .. degrees[2])]];

ControleGridShape := degrees[1]+1;
sol := simplify(CreateG1EdgeFuction(valence, knotsLists, degrees, ControleGridShape));

fct:=simplify([subs(sol, Matrix([seq([seq(f[1][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)])),subs(sol, Matrix([seq([seq(f[2][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)]))]);

val1:=subs(sol,f[2][1, 6]+f[1][6, 1]-2*f[2][0, 6]);

with(CodeTools);
Test(val1, 0);
