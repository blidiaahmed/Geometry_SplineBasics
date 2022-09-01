read "src/CreateG1Functions.mpl";




VertexBsplineCPPFile:=proc(valence, knotsLists, degrees, ControleGridShape,FileName)
local sol, i,j,k;
print(ControleGridShape);

sol := simplify(CreateG1VertexFuction(valence, knotsLists, degrees, ControleGridShape));
fct:=simplify([seq(subs(sol, Matrix([seq([seq(f[k][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)])), k=1..valence)]);

setOfCoeffs:=indets(fct);
for coefficient in setOfCoeffs do
    if member(coefficient, setOfCoeffs) then
        FileTools[Text][WriteString]("try/VertexGDFile.txt","VFunction\n");
        sys:={coefficient-1};
        
        sys:={op(sys),op(setOfCoeffs minus {coefficient}),op(sol)};

        sol1:=solve(sys);

        
        for k from 1 to valence do
            
            for i from 1 to ControleGridShape  do

                for j from 1 to ControleGridShape do
                    if not(subs(sol1,f[k][i-1,j-1])=0) then 
                        
                        str:=cat(String(k)," ",String(i)," ",String(j)," ",String(subs(sol1,f[k][i-1,j-1])),"\n");
                        FileTools[Text][WriteString]("try/VertexGDFile.txt",str);
                        
                    end if;
                    

                end;
            end;
        end;
    end if;
end;
FileTools[Text][Close]("try/VertexGDFile.txt");
return sol,fct;
end proc;
