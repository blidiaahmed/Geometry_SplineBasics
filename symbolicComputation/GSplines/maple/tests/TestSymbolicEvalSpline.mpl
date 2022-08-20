
read "src/SymbolicEvalSpline.mpl";
deg := 3;
ControlePoints := [1, 2, 1, 1, 2];
knots := [0, 0, 0, 0, 1/2, 1, 1, 1, 1];
k := 3;
val1:=SymbolicEvaluateSpline(u, ControlePoints, knots, deg);
with(CodeTools);
Test([subs(u=0,val1[1]),subs(u=1,val1[2])], [1,2]);
