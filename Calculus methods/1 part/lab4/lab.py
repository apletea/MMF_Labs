import numpy as np
import pylab
import matplotlib.pyplot as plt


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


def newton_interpolation(x, y, u):
    g = y[:]
    s = g[0]
    for i in range(len(y) - 1):
        g = [(g[j + 1] - g[j]) / (x[j + i + 1] - x[j]) for j in range(len(g) - 1)]
        s += g[0] * product(u - x[j] for j in range(i + 1))
    return s


def product(a):
    p = 1
    for i in a: p *= i
    return p



def main():
    X = np.array([0,np.pi/6,np.pi/4,np.pi/3,np.pi/2])
    Y = 4*np.sin(X)**2
    x_in = np.sin(np.pi/7)
    y_true = 4*np.sin(x_in)**2
    xnew = np.linspace(np.min(X),np.max(X),100)
    Y_lagranz = np.array([lagranz_intrepolation(X,Y,i) for i in xnew])
    Y_newton = np.array([newton_interpolation(X,Y,i) for i in xnew])
    y_newtwon = newton_interpolation(X,Y,x_in)
    y_lagranz = lagranz_intrepolation(X,Y,x_in)
    print("In newtwon : " + str(y_true-y_newtwon))
    print("In lagranz :" + str(y_true-y_lagranz))
    plt.plot(X,Y,'o')
    plt.plot(xnew,Y_lagranz,'g')
    plt.plot(xnew,Y_newton,'b')
    plt.grid(True)
    pylab.show()
main()