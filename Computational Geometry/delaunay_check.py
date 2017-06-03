import convex_hull
import DelanaunayTriangulation
from PIL import Image, ImageDraw
import random
import math
import time


class BarycentricCoordinates():
    def calcBarCoord(self, p1, p2, p3, p):
        ''' calculate the barycentric coordinates '''
        p1x = float(p1[0])
        p1y = float(p1[1])
        p2x = float(p2[0])
        p2y = float(p2[1])
        p3x = float(p3[0])
        p3y = float(p3[1])
        px = float(p[0])
        py = float(p[1])

        d = (p2y - p3y) * (p1x - p3x) + (p3x - p2x) * (p1y - p3y)
        if d != 0:
            alpha = ((p2y - p3y) * (px - p3x) + (p3x - p2x) * (py - p3y)) / (
            (p2y - p3y) * (p1x - p3x) + (p3x - p2x) * (p1y - p3y))
            beta = ((p3y - p1y) * (px - p3x) + (p1x - p3x) * (py - p3y)) / (
            (p2y - p3y) * (p1x - p3x) + (p3x - p2x) * (p1y - p3y))
            gamma = 1 - alpha - beta
            return [alpha, beta, gamma]
        else:
            return None


class circleThroughThreePoints():
    def center(self, p1, p2, p3):
        ''' returns the coordinates of the center point of the circle defined by three points '''
        c = None

        x1 = float(p1[0])
        y1 = float(p1[1])
        x2 = float(p2[0])
        y2 = float(p2[1])
        x3 = float(p3[0])
        y3 = float(p3[1])

        if x2 != x1 and x3 != x2 and y2 != y1 and y3 != y2:
            ma = (y2 - y1) / (x2 - x1)
            mb = (y3 - y2) / (x3 - x2)
            if ma != mb and ma != 0:
                cx = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) / (2 * (mb - ma))
                cy = -(1 / ma) * (cx - (x1 + x2) / 2) + (y1 + y2) / 2
                c = (cx, cy)

        elif x2 == x1 or x2 == x3:
            print
            'vertical line'

        return c

    def radius(self, c, p):
        point = []
        center = []
        point.append(float(p[0]))
        point.append(float(p[1]))
        center.append(float(c[0]))
        center.append(float(c[1]))
        rad = ((point[0] - center[0]) ** 2 + (point[1] - center[1]) ** 2)

        return rad


class DelaunayCheck(object):
    ''' finds non-delaunay triangles '''

    def __init__(self, draw, triangles, cloud, conv_h):
        cir = circleThroughThreePoints()
        self.deleteConvHullPoints(cloud, conv_h)
        self.searchForNonDelaunay(cloud, triangles, cir, draw)

    def searchForNonDelaunay(self, cloud, triangles, cir, draw):
        center_c = ()
        for j in range(len(triangles)):
            ''' takes one triangle '''
            center = cir.center(triangles[j][0], triangles[j][1], triangles[j][2])
            if center != None:
                rad_sqr = cir.radius(center, triangles[j][0])
                i = 0
                while i < len(cloud):
                    ''' now we talk about point cloud[i] '''
                    xi = cloud[i][0]
                    yi = cloud[i][1]

                    if ((xi - center[0]) ** 2 + (yi - center[1]) ** 2) < rad_sqr:
                        ''' a point is inside the circle => triangle[j] is not Delaunay '''
                        draw.polygon(triangles[j], fill="yellow", outline='black')
                        i = len(cloud)
                    i = i + 1

    def deleteConvHullPoints(self, cloud, conv_h):
        ''' delete from set points the convex hull points '''
        for i in range(len(conv_h)):
            cloud.remove(conv_h[i])


if __name__ == '__main__':
    im = Image.new("RGBA", (1000, 800), (255, 255, 255, 255))
    draw = ImageDraw.Draw(im)

    points = int(input("How many points?"))

    c = convex_hull.Cloud(draw, points)
    cv = convex_hull.ConvHull(draw, c.cloud)
    st = DelanaunayTriangulation.simpleTriangulation(draw, c, cv)

    dt = DelaunayCheck(draw, st.triangles, c.cloud, cv.polygon)

    im.save("new.png")
