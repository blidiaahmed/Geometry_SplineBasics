read "src/HelpFunctions.mpl";
evaluateSpline := proc(x, ControlePoints, knots, k, deg) 
local p, d, t, alpha, r, dd, i, val;
p := deg; d := ControlePoints; t := knots; alpha := 0;

for r to p do dd := [];
for i from k - p + r to k do 
alpha := (x - acces(t, i))/(acces(t, i + 1 + p - r) - acces(t, i)); 
val := (1 - alpha)*acces(d, i - 1) + alpha*acces(d, i); dd := [op(dd), val];
end do; 
for i from k - p + r to k do 
d[i + 1] := acces(dd, i - k + p - r);
end do; end do;
val := acces(d, k);
return val; 
end proc;