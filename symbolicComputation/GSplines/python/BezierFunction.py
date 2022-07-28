#define the bezier functions
import scipy.special
from helperFile import *

def Bezier(i,n,x):
    return binomial(n, i)*(x**i)*(1-x)**(n-i)
