acces := proc(tab, idx) return tab[idx + 1]; end proc;

IntervalIndex := proc(x, knotsVector) 
       local cmp, i; 
       cmp := 0; 
       for i from 0 to nops(knotsVector) - 2 do 
              if acces(knotsVector, i) < acces(knotsVector, i + 1) then
                     cmp := i;
                     if acces(knotsVector, i) <= x and x < acces(knotsVector, i + 1) then
                            return i;
                     end if; 
              end if;
       end do;
       return cmp;
end proc;


AllIntevalIndexes := proc(knots)
local allIndexes, k;
allIndexes := []; 
for k to nops(knots) - 1 do if knots[k] < knots[k + 1] then allIndexes := [op(allIndexes), k - 1]; end if;
end do;
return allIndexes; 
end proc: