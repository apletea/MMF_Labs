import random
import GrahamAlg as sort
from graphics import *
import math

min_x = 700
max_x = 0
min_y = 700
max_y = 0

def newPoint():
    return Point(random.randint(100,500), random.randint(100,500))

def initWin():
    return GraphWin("Where is Point",700, 700)

def is_right(a,b,c):
    return ((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x))

def is_in_line(a,b,c):
    return ((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x)) == 0


def find_max_min(set):
    global min_x
    global min_y
    global max_x
    global max_y
    for p in set:
        if (p.x > max_x ):
            max_x = p.x
        if (p.x < min_x):
            min_x = p.x
        if (p.y > max_y):
            max_y = p.y
        if (p.y < min_y):
            min_y = p.y

def first3(set):
    p = newPoint()
    while (p == set[0]):
        p = newPoint()
    set.append(p)
    p = newPoint()
    while(p == set[0] or p == set[1]):
        p = newPoint()
    set.append(p)
    find_max_min(set)

def intersect(A,B,C,D):
  return is_right(A,B,C)*is_right(A,B,D)<=0 and is_right(C,D,A)*is_right(C,D,B)<0

def point_loc(P,A):
    n = len(P)
    if is_right(P[0],P[1],A) < 0 or is_right(P[0],P[n-1],A) > 0:
        return False
    p,r = 1, n -1
    while r - p > 1:
        q = int((p + r) / 2)
        if is_right(P[0], P[q], A) < 0:
            r = q
        else:
            p = q
    return not intersect(P[0], A, P[p], P[r])

def is_intersect_convex(p1,p2,set):
    for i in range(0,len(set)-1):
        if (intersect(p1,p2,set[i],set[i+1])):
            return True
    return False

def distance(p1,p2):
    return math.sqrt((p1.x-p2.x)**2+(p1.y-p2.y)**2)

def removebetween(p1,p2,set):
    print('remove')
    p1i = 0
    p2i = 0
    for i in (0,len(set)-1):
        if (p1 == set[i]):
            p1i = i
        if (p2 == set[i]):
            p2i = i
    if (is_right(set[p1i],set[p1i+1],set[len(set)-1])) :
        set[p1i:p2i]
    else :
        set[0:p2i]
        set[p1i: 0]

def add_point_to_set(p,set,win):
    point1 = p
    point2 = p
    j = 0
    position = is_right(set[0],set[1],p)
    for i in range (1,len(set)):
        if (position == is_right(set[i-1],set[i],p)):
            point1 = set[i-1]
            j = i
            position = -position
            break
    for i in range (j,len(set)):
        if (position == is_right(set[i-1],set[i],p)):
            point2 = set[i-1]
    set.append(p)
    removebetween(point1,point2,set)


def main():
    win = initWin()
    set = []
    set.append(newPoint())
    first3(set)
    b= 1
    polyhon = Polygon(set)
    polyhon.draw(win)
    while (b==1):
        p = newPoint()
        if (point_loc(set,p)):
            continue
        else:
            add_point_to_set(p,set,win)
            set = sort.draw(set)
            polyhon = Polygon(set)
            polyhon.draw(win)
            print(polyhon)
            a = input()
            continue

main()