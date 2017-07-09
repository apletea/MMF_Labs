import numpy as np
import matplotlib.pyplot as plt
import pylab



def mnk_1(X,Y,i):
    sumx = np.sum(X)
    sumx2 = np.sum(X**2)
    sumy = np.sum(Y)
    sumxy = np.sum(Y*X)
    print(sumx,sumx2,sumy,sumxy)
    a = (len(X)*sumxy - (sumx*sumy))/(len(X)*sumx2 - sumx**2)
    b = (sumy - a*sumx)/len(X)
    print (a)
    print b
    return a*i+b


def createC(X,Y,power):
    return np.sum((X**power)*Y)

def createT(X,Y,level, power):
    return np.array([np.sum(X**i) for i in range(level,level+power+1)])

def minus(a,j):
    if (j%2!=0):
        return -a
    return a

def mnk_n(X,Y,i,n):
    T = np.array([createT(X,Y,j,n) for j in range(0,n+1)])
    C = np.array([[createC(X,Y,power)] for power in range(0,n+1)])
    delta = np.linalg.det(T)
    T = np.append(T,C,axis=1)
    koef = []
    for j in range(0,n+1):
        tmp = np.array(T)
        tmp = np.delete(tmp,j,1)
        print tmp
        koef.append(np.linalg.det(tmp)/delta)
    koef = [minus(koef[j],j) for j in range(0,len(koef))]
    print(koef)
    ans = 0

    for j in range(0,n+1):
        ans += koef[n-j]*i**(n-j)
    return ans


def main():
    X = np.array([0.78,1.56,2.34,3.12,3.81])
    Y = np.array([2.5,1.2,1.12,2.25,4.28])
    plt.plot(X,Y,'o')
    mnk_1(X,Y,1)
    xnew = np.linspace(np.min(X),np.max(X),150)
    ynew = [mnk_1(X,Y,i) for i in xnew]
    plt.plot(xnew,ynew,'o')
    ynow = [mnk_n(X,Y,i,2) for i in xnew]
    plt.plot(xnew,ynow,'o')
    plt.plot(X,Y,'o')
    pylab.show()
main()