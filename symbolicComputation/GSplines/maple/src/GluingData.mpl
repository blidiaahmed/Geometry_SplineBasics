
#phi__2 := (u, v) -> v*k(u, v);
#phi__1 := (u, v) -> u*(1 + v*p(u, v)) + v*q(u, v)
#subs(v = 0, simplify(diff([phi__1(u, v), phi__2(u, v)], v)))

#G0

read "src/symbolicTensorSpline.mpl";

knotsLists := [[0, 0, 0, 0, 1/2, 1, 1, 1, 1],[0, 0, 0, 0, 1/2, 1, 1, 1, 1]];

degrees:=[3,3];

FControlePoints:=[seq([seq(f[i,j],j=0..4)],i=0..4)];
GControlePoints:=[seq([seq(g[i,j],j=0..4)],i=0..4)];

Ffunction:=SymbolicTensorSpline(u,v,FControlePoints,knotsLists,degrees);
Gfunction:=SymbolicTensorSpline(u,v,GControlePoints,knotsLists,degrees);

difference := subs([v = 0], Ffunction - Gfunction);
Expps:=[difference[1][1],difference[1][2]];



#G1
n:=3;
c:=cos(2*pi/n);
a(u):=2*c*(1-u)^2;
b(u):=-1;



expp := [diff(Gfunction[1][ 1], u) - a(u)*diff(Ffunction[1][ 1], u) - b(u)*diff(Ffunction[1][ 1], v),
diff(Gfunction[2][1], u) - a(u)*diff(Ffunction[2][ 1], u) - b(u)*diff(Ffunction[2][ 1], v)];

Eqs:=[seq(coeff(subs(v = 0, expp[1]), u,i),i=0..4)];

Eqs:=[op(Eqs),op(Expps),seq(coeff(subs(v = 0, expp[1]), u,i),i=0..4)];



#Solving


Sol:=solve([op(Eqs), f[4, 0], f[3, 0], f[4, 1], f[3, 1], f[0, 1], f[1, 1], f[1, 0], f[0, 0]], indets([FControlePoints, GControlePoints]));