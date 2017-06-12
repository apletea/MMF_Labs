import numpy as np
import matplotlib.pyplot as plt
import pylab
import math


def find_y_in_x(X,Y,x):
    return x


def main():
    X = np.array([0,math.pi/6,math.pi/4,math.pi/3,math.pi/2])
    Y = np.sin(X)**2
    x_in = math.pi/5
    y_true = np.sin(x_in)**2
    xnew = np.linspace(np.min(X),np.max(X),100)
    ynew = [find_y_in_x(X,Y,i) for i in xnew]
    plt.plot(X,Y,'o',xnew,ynew)
    plt.grid(True)
    y_in = find_y_in_x(X,Y,x_in)
    print(y_in-y_true)
    pylab.show()
main()