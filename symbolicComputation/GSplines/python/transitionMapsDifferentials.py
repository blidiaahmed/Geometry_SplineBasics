from symtable import Symbol
from BezierFunction import Bezier
import numpy as np 
from sympy import *
u=Symbol('u')
v=Symbol('v')
k=Function('k')(u,v)
p=Function('p')(u,v)
q=Function('q')(u,v)
def phi_2(u,v):
    return v*k(u, v);


class p(Function):
    @classmethod
    def eval(cls, u,v):
        pass
class k(Function):
    @classmethod
    def eval(cls, u,v):
        pass
class q(Function):
    @classmethod
    def eval(cls, u,v):
        pass
class f(Function):
    @classmethod
    def eval(cls, u,v):
        pass
class g(Function):
    @classmethod
    def eval(cls, u,v):
        pass

class phi_1(Function):
    @classmethod
    def eval(cls, u,v):
        return u*(1 + v*p(u, v)) + v*q(u, v);
class phi_2(Function):
    @classmethod
    def eval(cls, u,v):
        return v*k(u, v)
class expr(Function):
    @classmethod
    def eval(cls, u,v):
        return f(phi_1(u, v), phi_2(u, v))-g(u,v)
diffExpr=expr(u,v).diff(v)
diffExpr.subs(v,0)