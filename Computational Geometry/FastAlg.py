import random
import math
import GrahamAlg as toDraw
from graphics import *

length = 30

def newPoint():
    return Point(random.randint(1,500), random.randint(1,500))

def init():
    points = []
    for i in range (0,length):
        points.append(newPoint())
    return points

def initWin():
    return GraphWin("Where is Point",700, 700)

def findLeftAndRight(points):
    leftPoint = points[0]
    rightPoint = points[0]
    for point in points:
        if (point.x < leftPoint.x):
            leftPoint = point
        else:
            if (point.x > rightPoint.x):
                rightPoint = point
    ans = [leftPoint, rightPoint]
    return ans

def isLeft(p1,p2,p3):
    return (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) > 0

def dist(a,b):
    return (math.sqrt(float((a.x-b.x)**2-(a.y-b.y)**2)))

def distFromLine(p1,p2,p):
    a =(p1.y-p2.y)
    b = (p1.x-p2.x)
    c =-(a*p1.x+b*p1.y)
    return math.fabs(a*(p.x)+b*(p.y)+c)/math.sqrt(float(a**2+b**2))

def getPointsLeftByLine(points, setPoints, p1, p2):
    ans = []
    for point in setPoints:
        if (isLeft(p1,p2,point)):
            ans.append(point)
    return ans


def QuickHull2(initPoints,leftPoint,rightPoint, setOfPoint):
    if (len(setOfPoint)==0):
        return [rightPoint]
    topPos = setOfPoint[0]
    maxDist = distFromLine(leftPoint,topPos,topPos)
    for point in setOfPoint:
        curDist = distFromLine(leftPoint,topPos,point)
        if (maxDist == curDist):
            if (isLeft(leftPoint,topPos,point)):
                topPos = point
        if (maxDist < curDist):
            maxDist = curDist
            topPos = point
    S11 = getPointsLeftByLine(initPoints,setOfPoint,leftPoint,topPos)
    ans1 = QuickHull2(initPoints,leftPoint,topPos,S11)
    S12 = getPointsLeftByLine(initPoints,setOfPoint,topPos,rightPoint)
    ans2 = QuickHull2(initPoints,topPos,rightPoint,S12)
    for point in ans2:
        ans1.append(point)
    return ans1


def QuickHull(points):
    leftAndRight = findLeftAndRight(points)
    leftPoint = leftAndRight[0]
    rightPoint = leftAndRight[1]
    S1 = []
    S2 = []
    for point in points :
        if (isLeft(leftPoint, rightPoint, point)):
            S1.append(point)
        else:
            if (isLeft(rightPoint,leftPoint,point)):
                S2.append(point)
    ans1 = QuickHull2(points,leftPoint,rightPoint,S1)
    ans2 = QuickHull2(points,rightPoint, leftPoint, S2)
    for point in ans2:
        ans1.append(point)
    return ans1




def main():
    points = init()
    win = initWin()
    for i in points:
        i.draw(win)
    mypoints = QuickHull(points)
    mypoints = toDraw.draw(mypoints)
    first = mypoints[0]
    current = mypoints[0]
    for i in range(0, len(mypoints)):
        p1 = mypoints[i]
        if (p1 == first):
            continue
        line = Line(current, p1)
        current = p1
        line.draw(win)
    line = Line(current, first)
    line.draw(win)
    a = input()
main()