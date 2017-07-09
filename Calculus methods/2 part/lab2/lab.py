import numpy as np
import matplotlib.pyplot as plt
import pylab
from scipy.integrate import quad


def F(x):
    return np.sin(x)**3*np.exp(x)

def integreate(a,b):
    return quad()

def main():
    a = 0.1
    b = 0.6
    trueAns,err = quad(F,a,b)
    ans1 = (b-a)*(F(a)+F(b))/2
    ans2 = (b-a)*(F(a)+4*(F(a+b/2))+F(b))/6
    ans3 = (b-a)*(F(a)+3*(F(a+(b-a)/3))+3*(F(a+2/3*(b-a)))+F(b))
    print(ans1-trueAns,ans2-trueAns,ans3-trueAns)
    print trueAns

    pylab.show()
    return 0
main()