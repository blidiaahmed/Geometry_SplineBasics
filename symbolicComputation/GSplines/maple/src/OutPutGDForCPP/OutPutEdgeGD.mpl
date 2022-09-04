read "src/CreateG1Functions.mpl";



EdgeBsplineCPPFile:=proc(valence, knotsLists, degrees, ControleGridShape,FileName)
    local sol,i,j,k;

    sol := simplify(CreateG1EdgeFuction(valence, knotsLists, degrees, ControleGridShape));

    fct:=simplify([seq(subs(sol, Matrix([seq([seq(f[k][i, j], j = 0 .. ControleGridShape-1)], i = 0 .. ControleGridShape-1)])), k=1..2)]);

    setOfCoeffs:=indets(fct);

    for coefficient in setOfCoeffs do

        if member(coefficient, setOfCoeffs) then

            FileTools[Text][WriteString]("try/EdgeGDFile.txt","EFunction\n");

            sys:={coefficient-1};
            
            sys:={op(sys),op(setOfCoeffs minus {coefficient}),op(sol)};

            sol1:=solve(sys);
            
            for k from 1 to 2 do
                
                for i from 1 to ControleGridShape  do

                    for j from 1 to ControleGridShape do
                        if not(subs(sol1,f[k][i-1,j-1])=0) then 

                            str:=cat(String(k)," ",String(i)," ",String(j)," ",String(subs(sol1,f[k][i-1,j-1])),"\n");
                            FileTools[Text][WriteString]("try/EdgeGDFile.txt",str);

                        end if;
                        

                    end;
                end;
            end;
        end if;
    end;
    FileTools[Text][Close]("try/EdgeGDFile.txt");
    return sol,fct;
end proc;


