
read "src/EvalSpline.mpl";
deg := 3;
ControlePoints := [1, 2, 1, 1, 2];
knots := [0, 0, 0, 0, 1/2, 1, 1, 1, 1];
k := 3;
val1:=evaluateSpline(0., ControlePoints, knots, k, deg);
with(CodeTools);
Test(val1, 1);

#---------

deg := 3;
ControlePoints := [1,1,1, 1, 1, 2];
knots :=[0, 0, 0, 0, 1/3, 1/2, 1, 1, 1, 1];
k := 5;
val1:=evaluateSpline(0.999, ControlePoints, knots, k, deg);

Test(val1, 2);
