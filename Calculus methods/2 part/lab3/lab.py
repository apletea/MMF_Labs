import numpy as np
import matplotlib.pyplot as plt
import pylab


def F(x):
    return 1/(7+x**3)


def main():
    a = 0.1
    b = 0.8
    n = 6
    I1 = 0
    x = np.linspace(a,b,6)
    print x
    for i in range(0,len(x)-1):
        I1 += F(x[i]) + F(x[i+1])
    I1 = I1*(b-a)/(2*n)
    print I1
    I2 = 0
    for i in range(0,len(x)-2,2):
        I2 += F(x[i]) + 4*F(x[i+1]) + F(x[i+2])
    I2 = I2*(b-a)/(3*n)
    print I2
    return 0
main()