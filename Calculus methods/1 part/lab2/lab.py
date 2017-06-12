import numpy as np
import matplotlib.pyplot as plt
import pylab
import math

def ex():
    # Come up with x and y
    x = np.arange(0, 5, 0.1)
    y = np.sin(x)

    # Just print x and y for fun
    print(x)
    print(y)

    # plot the x and y and you are supposed to see a sine curve
    plt.plot(x, y)

    # without the line below, the figure won't show
    pylab.show()


def mnogolhlen_lagranza(x,y,t):
    z = 0
    for j in range(len(y)):
        p1 = 1;
        p2 = 1
        for i in range(len(x)):
            if i == j:
                p1 = p1 * 1;
                p2 = p2 * 1
            else:
                p1 = p1 * (t - x[i])
                p2 = p2 * (x[j] - x[i])
        z = z + y[j] * p1 / p2
    return z



def main():
    x = np.array([0,math.pi/6,math.pi/4,math.pi/3,math.pi/12])
    x_in = math.pi/5
    y_ex = np.tan(x_in)**2
    y = np.tan(x)**2
    xnew = np.linspace(np.min(x),np.max(x),100)
    ynew = [mnogolhlen_lagranza(x,y,i) for i in xnew]
    plt.plot(x,y,'o',xnew,ynew)
    plt.grid(True)
    pylab.show()
    y_true = mnogolhlen_lagranza(x,y,x_in)
    print(y_ex - y_true)



main()