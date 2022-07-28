import numpy as np 

from sympy import *

x=Symbol('x')
y=Symbol('y')

A=np.array([0,0])
B=np.array([1,0])
C=np.array([1,1])
D=np.array([0,1])

Ap=np.array([0,0])
Bp=np.array([1,0])
Cp=np.array([1,1/2])
Dp=np.array([1/2,1/2])

def bi2interpolation(Ap,Bp,Cp,Dp,x,y):
    pt1=Ap+(Bp-Ap)*x
    pt2=Dp+(Cp-Dp)*x
    return pt1+(pt2-pt1)*y

