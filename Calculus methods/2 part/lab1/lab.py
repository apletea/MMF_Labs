import numpy as np
import matplotlib.pyplot as plt
import pylab



def mnk_1(X,Y,i):
    sumx = 0
    sumx2 = 0
    sumy = 0
    symy2 = 0
    for 
    return i+1+X[0]+Y[0]



def mnk_2(X,Y,i):
    return 0


def main():
    X = np.array([0.1,0.2,0.3,0.4])
    Y = np.array([-1.007,2.076,-5.085,8.082])
    plt.plot(X,Y,'o')
    xnew = np.linspace(np.min(X),np.max(X),150)
    ynew = [mnk_1(X,Y,i) for i in xnew]
    plt.plot(xnew,ynew,'o')
    ynow = [mnk_2(X,Y,i) for i in xnew]
    plt.plot(xnew,ynow,'o')
    pylab.show()
main()