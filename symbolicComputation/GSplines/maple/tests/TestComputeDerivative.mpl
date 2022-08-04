

read "src/ComputeDerivative.mpl";
deg := 3;
ControlePoints := [1, 2, 1, 1, 2];
knots := [0, 0, 0, 0, 1/2, 1, 1, 1, 1];
val1:=computeDerivative(ControlePoints,knots,deg);
with(CodeTools);
Test(val1, [[6, -3, 0, 6], [0, 0, 0, 1/2, 1, 1, 1]]);
