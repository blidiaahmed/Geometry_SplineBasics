read "src/SymbolicTensorSpline.mpl";
degrees := [3,3];
ControlePoints := [
[1, 2, 1, 1, 4,3],
[1, 2, 1, 1, 4,4],
[1, 2, 1, 1, 4,4],
[1, 2, 1, 1, 4,4],
[1, 2, 1, 1, 4,4],
[2, 2, 1, 1, 4,4]
];
knotsLists := [[0, 0, 0, 0, 1/3, 1/2, 1, 1, 1, 1],[0, 0, 0, 0, 1/3, 1/2, 1, 1, 1, 1]];

with(CodeTools);

val:=SymbolicTensorSpline(0.,0.,ControlePoints,knotsLists,degrees);
Test(val[1][1],1.);


val:=SymbolicTensorSpline(1.,0.,ControlePoints,knotsLists,degrees);
Test(val[2][1],2.);