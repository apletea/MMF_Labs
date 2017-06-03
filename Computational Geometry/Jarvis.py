import random
from graphics import *

def newPoint():
    return Point(random.randint(350,500), random.randint(350,500))

length = 15
def init():
    points = []
    for i in range (0,length):
        points.append(newPoint())
    return points

def initWin():
    return GraphWin("Where is Point",700, 700)

def OrientTriangle(p1,p2,p3):
    return p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y) + p3.x*(p1.y-p2.y)

def isInside(p1,p,p2):
    return  ( p1.x <= p.x and p.x <= p2.x and p1.y <= p.y and p.y <= p2.y)

def alghoritm(points):
    base = 0
    ans = []
    for i in range(0,length):
        if (points[i].y < points[base].y):
            base = i
        else :
            if(points[i].y == points[base].y and points[i].x < points[base].x):
                base = i
    ans.append(base)
    first = base
    cur = base
    j = 0
    while True :
        next = (cur + 1)%length
        for i in range (0,length):
            sign = OrientTriangle(points[cur], points[next], points[i])
            if (sign < 0):
                next = i
            else:
                if (sign == 0):
                    if (isInside(points[cur],points[next],points[i])):
                        next = i
        cur = next

        ans.append(next)
        print("iteration ",j)
        j +=1
        print(ans)
        if (cur == first):
            break
    return ans

def main():
    points = init()
    win = initWin()
    sortedPoints = alghoritm(points)
    print(points)
    first = points[sortedPoints[0]]
    current = points[sortedPoints[0]]
    for point in points:
        point.draw(win)
    for i in sortedPoints:
        p1 = points[i]
        if (p1 == first):
            continue
        line = Line(current,p1)
        current = p1
        line.draw(win)
    line = Line(current,first)
    line.draw(win)
    a = input()
main()