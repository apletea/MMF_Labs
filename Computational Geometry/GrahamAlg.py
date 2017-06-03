import random
from graphics import *

length = 30

def comparator(a,b):
    if (a.x < b.x):
        return 1
    if (a.x == b.x and a.y == b.y):
        return 1
    return -1

def cmp_to_key(comparator):
    'Convert a cmp= function into a key= function'
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
    return Point(random.randint(1,500), random.randint(1,500))

def init():
    points = []
    for i in range (0,length):
        points.append(newPoint())
    return points

def initWin():
    return GraphWin("Where is Point",700, 700)

def cw (a, b, c):
    if ( (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)) < 0 ):
        return True
    else:
        return False

def ccw(a, b, c):
    if( (a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)) > 0):
        return True
    else:
        return False


def draw(points):
    points.sort(key=cmp_to_key(comparator))
    p1 = points[0]
    p2 = points[len(points)-1]
    up = []
    down = []
    up.append(p1)
    down.append(p1)
    for i in range(1, len(points)):
        if (i == len(points) - 1 or cw(p1, points[i], p2)):
            while ((int(len(up)) >= 2) and not cw(up[(len(up)-2)],up[(len(up)-1)], points[i])):
                up.pop()
            up.append(points[i])
        if (i == len(points)-1 or ccw(p1, points[i], p2)):
            while (len(down) >= 2 and not ccw(down[(len(down)-2)],down[(len(down)-1)], points[i])):
                    down.pop()
            down.append(points[i])
    ans = []
    for i in range(0, len(up)):
        ans.append(up[i])
    for i in range(0, len(down)-2):
        ans.append(down[len(down)-2-i])
    return ans
