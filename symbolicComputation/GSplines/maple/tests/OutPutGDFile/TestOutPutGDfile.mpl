read "src/OutPutGDForCPP/OutPutEdgeGD.mpl";
read "src/OutPutGDForCPP/OutPutVertexGD.mpl";

valence := 3;
degrees := [5,5];
knotsLists := [[seq(0, i = 0 .. degrees[1]), seq(1, i = 0 .. degrees[1])],[seq(0, i = 0 .. degrees[2]), seq(1, i = 0 .. degrees[2])]];
ControleGridShape := degrees[1]+1;
sol,fct:=VertexBsplineCPPFile(valence, knotsLists, degrees, ControleGridShape,FileName);
sol1,fct1:=EdgeBsplineCPPFile(valence, knotsLists, degrees, ControleGridShape,FileName);