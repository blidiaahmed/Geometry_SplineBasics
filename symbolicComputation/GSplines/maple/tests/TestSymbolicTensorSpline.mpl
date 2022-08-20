read "src/SymbolicTensorSpline.mpl";
degrees := [3,3];
ControlePoints := [
[1, 2, 1, 1, 4],
[1, 2, 1, 1, 2],
[1, 2, 1, 1, 2],
[1, 2, 1, 1, 2],
[3, 2, 1, 1, 2]];
knotsLists := [[0, 0, 0, 0, 1/2, 1, 1, 1, 1],[0, 0, 0, 0, 1/2, 1, 1, 1, 1]];

with(CodeTools);

val:=SymbolicTensorSpline(0.,0.,ControlePoints,knotsLists,degrees);
Test(val[1][1],1.);

val:=SymbolicTensorSpline(1,1.,ControlePoints,knotsLists,degrees);
Test(val[2][2],2.);

val:=SymbolicTensorSpline(1,0.,ControlePoints,knotsLists,degrees);
Test(val[2][1],3.);

val:=SymbolicTensorSpline(0,1.,ControlePoints,knotsLists,degrees);
Test(val[1][2],4.);


val:=SymbolicTensorSpline(u,v,ControlePoints,knotsLists,degrees)[1][1];
derivative:=(subs([u=0.0001,v=0],val)-subs([u=0.,v=0],val))/0.0001;
Test(derivative,0);