read "src/symbolicEvalSpline.mpl";
SymbolicTensorSpline := proc(x, y, ControlePoints, knotsLists, degrees)

local sums, i;
sums := []; 

for i from 0 to nops(ControlePoints)-1 do

sums := [op(sums), Vector(SymbolicEvaluateSpline(y, acces(ControlePoints, i), knotsLists[2], degrees[2]))];
end do;

return SymbolicEvaluateSpline(x, sums, knotsLists[1], degrees[1]);
end proc;