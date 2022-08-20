read "src/EvalSpline.mpl":
tensorSpline := proc(x, y, ControlePoints, knotsLists, degrees)
local sums, kx, ky, i;
sums := []; 
kx := IntervalIndex(x, knotsLists[1]);
ky := IntervalIndex(y, knotsLists[2]);
for i from 0 to nops(ControlePoints)-1 do
sums := [op(sums), evaluateSpline(y, acces(ControlePoints, i), knotsLists[2], ky, degrees[2])];
end do;
return evaluateSpline(x, sums, knotsLists[1], kx, degrees[1]); 
end proc;