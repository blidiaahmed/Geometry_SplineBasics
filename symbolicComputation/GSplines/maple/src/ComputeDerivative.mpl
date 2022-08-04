
computeDerivative := proc(ControlePoints, knots, deg) 
local NewControlePoints, NewKnotDitribution, i, Q; 
NewControlePoints := [];
NewKnotDitribution := [seq(knots[i], i = 2 .. nops(knots) - 1)]; 
for i to nops(ControlePoints) - 1 do
Q := deg*(ControlePoints[i + 1] - ControlePoints[i])/(knots[deg + 1 + i] - knots[i + 1]);
NewControlePoints := [op(NewControlePoints), Q]; 
end do; 
return [NewControlePoints, NewKnotDitribution];
end proc;