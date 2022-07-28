from symtable import Symbol
from BezierFunction import Bezier
import numpy as np 
from sympy import *

x=Symbol('x')
y=Symbol('y')
s=Symbol('s')
t=Symbol('t')

def indexed_variable(Sym,i,j):
    return Symbol(''.join([Sym,'_{',str(i),',',str(j),'}']))

#c=[[indexed_variable('c',i,j) for i in range(Transition_degree+1)] for j in range(Transition_degree+1)]

def bivariate_bezier(sym,degree,x,y):
    coeff=[[indexed_variable(sym,i,j) for i in range(Transition_degree+1)] for j in range(Transition_degree+1)]
    S=sum([coeff[i][j]*Bezier(i,Transition_degree,x)*Bezier(j,Transition_degree,y) for i in range(Transition_degree+1) for j in range(Transition_degree+1)])
    return  S


patch_degree=3
Transition_degree=2
phi=np.array(['\u03C6_1','\u03C6_2'])#phi
f='f'
g='g'
transitionMap=np.array([bivariate_bezier(phi[0],Transition_degree,x,y),bivariate_bezier(phi[1],Transition_degree,x,y)])

fmap=bivariate_bezier(f,patch_degree,x,y)
gmap=bivariate_bezier(g,patch_degree,s,t)

difference=gmap.subs({s:transitionMap[0], t:transitionMap[1]})-fmap

difference_x=difference.diff(x)
difference_y=difference.diff(y)

exp=[difference_x.subs({y:0}),difference_y.subs({y:0})]
