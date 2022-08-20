read "src/TensorSpline.mpl";
degrees := [3,3];
ControlePoints := [[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2],[1, 2, 1, 1, 2]];
knotsLists := [[0, 0, 0, 0, 1/2, 1, 1, 1, 1],[0, 0, 0, 0, 1/2, 1, 1, 1, 1]];

val:=tensorSpline(0.5,0.75,ControlePoints,knotsLists,degrees);
with(CodeTools);
Test(val,1.15625);

#--------------
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






val:=tensorSpline(1,0.,ControlePoints,knotsLists,degrees);
Test(val,2.);