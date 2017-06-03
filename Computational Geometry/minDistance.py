import random
import math
import GrahamAlg as createHull
from graphics import *

length = 30
mindist = 100000
ansa = Point(0,0)
ansb = Point(700,700)
a = []


def cmp_x(a,b):
    return a.x < b.x or a.x == b.x and a.y < b.y

def cmp_y(a,b):
    return a.y < b.y

def cmp_to_key(comparator):
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return comparator(self.obj, other.obj) < 0
        def __gt__(self, other):
            return comparator(self.obj, other.obj) > 0
        def __eq__(self, other):
            return comparator(self.obj, other.obj) == 0
        def __le__(self, other):
            return comparator(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return comparator(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return comparator(self.obj, other.obj) != 0
    return K



def newPoint():
    return Point(random.randint(150,600), random.randint(150,600))

def init():
    points = []
    for i in range (0,length):
        points.append(newPoint())
    return points

def initWin():
    return GraphWin("Where is Point",700, 700)

def upd_ans(a,b):
    dist = math.sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
    print(dist)
    global mindist, ansa, ansb
    if (dist < mindist and a!=b):
        mindist = dist
        ansa = a
        ansb = b

def show():
    global a
    for i in a:
        for j in a:
            upd_ans(i,j)

def merge(start,to,start2,to2,ans, comparator):
    i = start
    j = start2
    global a
    while(i < to and j < to2):
        if (comparator(a[i],a[j])):
            ans.append(a[i])
            i+=1
        else:
            ans.append(a[j])
            j+=1
    if (i == to):
        while(j < to2):
            ans.append(a[j])
            j+=1
    else:
        while(i < to):
            ans.append(a[i])
            i+=1
    return ans

def copy(t,end,start2):
    global a
    for i in (0,end-2):
        a[start2+i] = t[i]


def rec(l,r):
    global a
    if (r - l <= 3):
        for i in (l,r):
            for j in (i+1,r):
                upd_ans(a[i],a[j])
                return
    median = int((l+r)/2)
    medianx = a[median].x
    rec(l,median)
    rec(median+1,r)
    t = []
    t = merge(l,median,median,r,t,cmp_y)
    copy(t,r-l+1,l)
    tsz = 0
    for i in (l,r-1):
        if (math.fabs(a[i].x-medianx) < mindist):
            j = tsz
            while(j >= 0):
                if (a[i].y-t[j].y >= mindist):
                    break
                upd_ans(a[i],t[j])
                j-=1
            tsz+=1
            t[tsz] =a[i]

def main():
    global a
    a = init()
    window = initWin()
    a.sort(key = cmp_to_key(cmp_x))
    show()
    rec(0, length)
    for i in a:
        if (not i.canvas):
          i.draw(window)
    l = Line(ansa,ansb)
    l.draw(window)
    print(l)
    print('hi')
    a = input()
main()