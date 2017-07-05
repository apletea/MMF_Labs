import numpy as np
import pylab
import matplotlib.pyplot as plt


def interpolate_linear(X,Y,i,num):
    return Y[i] + (num-X[i])*(Y[i+1]-Y[i])/(X[i+1]-X[i])


def lagranz_intrepolation(X,Y,x):
   z =  0
   for j in range(len(Y)):
       p1 = 1
       p2 = 1
       for i in range(len(X)):
           if i == j :
             continue
           else:
             p1 = p1 * (x - X[i])
             p2 = p2 * (X[j] - X[i])
       z = z + Y[j]/p2*p1
   return z


def product(a):
    p = 1
    for i in a: p *= i
    return p

def newton_interpolation(x, y, u):
    g = y[:]
    s = g[0]
    for i in range(len(y) - 1):
        g = [(g[j + 1] - g[j]) / (x[j + i + 1] - x[j]) for j in range(len(g) - 1)]
        s += g[0] * product(u - x[j] for j in range(i + 1))
    return s

def interpolate_power_two(X,Y,i,num):
    X = np.array([X[i],X[i+1],X[i+2]])
    Y = np.array([Y[i],Y[i+1],Y[i+2]])
    return newton_interpolation(X,Y,num)

def main():
    X = np.array([1,7,15,28])
    Y = np.array([44,-25,4,-34])
    plt.plot(X,Y,'o')
    for i in range(0,X.size-1):
        xnew = np.linspace(X[i],X[i+1],250)
        ynew = np.array([interpolate_linear(X,Y,i,j) for j in xnew])
        plt.plot(xnew,ynew,'g')
    for i in range(0,X.size-2,2):
        xnew = np.linspace(X[i],X[i+2],50)
        ynew = np.array([interpolate_power_two(list(X),list(Y),i,j) for j in xnew])
        plt.plot(xnew,ynew,'b')
    pylab.show()
main()