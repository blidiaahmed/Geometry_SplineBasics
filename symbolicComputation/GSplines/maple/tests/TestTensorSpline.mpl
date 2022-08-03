read "src/TensorSpline.mpl";
degrees := [3,3];
ControlePoints := [[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2]];
knotsLists := [[0, 0, 0, 0, 1/2, 1, 1, 1, 1],[0, 0, 0, 0, 1/2, 1, 1, 1, 1]];

val:=tensorSpline(0.5,0.75,ControlePoints,knotsLists,degrees);
with(CodeTools);
Test(val,1.15625);