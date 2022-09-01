read "src/CreateG1Functions.mpl";
valence := 4;
degrees := [5,5];

knotsLists := [[seq(0, i = 0 .. degrees[1]), seq(1, i = 0 .. degrees[1])],[seq(0, i = 0 .. degrees[2]), seq(1, i = 0 .. degrees[2])]];

ControleGridShape := degrees[1]+1;

sol := simplify(CreateG1EdgeFuction(valence, knotsLists, degrees, ControleGridShape));

fct:=simplify([seq(subs(sol, Matrix([seq([seq(f[k][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)])), k=1..2)]);
