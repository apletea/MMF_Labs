from PIL import Image, ImageDraw
import random
import math
import time

import delaunay_check as delaunay_check
import convex_hull as convex_hull


class simpleTriangulation(object):
    triangles = []

    def __init__(self, draw, c, cv):
        bc = delaunay_check.BarycentricCoordinates()
        self.triangulateConvHull(draw, cv)
        self.triangulateCloud(draw, bc, c)

    def triangulateConvHull(self, draw, cv):
        for i in range(2, len(cv.polygon)):
            draw.line([cv.polygon[0], cv.polygon[i]], fill="black")
            self.triangles.append([cv.polygon[0], cv.polygon[i], cv.polygon[i - 1]])

    def triangulateCloud(self, draw, bc, c):
        for i in range(len(c.cloud)):
            tri = self.isPointInTriangle(c.cloud[i], bc)
            if tri != False:
                draw.line([c.cloud[i], tri[0]], fill="black")
                draw.line([c.cloud[i], tri[1]], fill="black")
                draw.line([c.cloud[i], tri[2]], fill="black")
                self.triangles.append([c.cloud[i], tri[0], tri[1]])
                self.triangles.append([c.cloud[i], tri[1], tri[2]])
                self.triangles.append([c.cloud[i], tri[2], tri[0]])
                self.triangles.remove(tri)

    def isPointInTriangle(self, point, bc):
        flag = False
        i = 0
        while i < len(self.triangles):
            p1 = self.triangles[i][0]
            p2 = self.triangles[i][1]
            p3 = self.triangles[i][2]

            bar_c = bc.calcBarCoord(p1, p2, p3, point)

            if bar_c != None:
                if 0.0 < bar_c[0] < 1.0 and 0.0 < bar_c[1] < 1.0 and 0.0 < bar_c[2] < 1.0:
                    flag = True
                    tri = self.triangles[i]
                    i = len(self.triangles)
            i = i + 1

        if flag == True:
            return tri
        else:
            return flag


if __name__ == '__main__':
    im = Image.new("RGBA", (1000, 800), (255, 255, 255, 255))
    draw = ImageDraw.Draw(im)

    points = int(input("How many points?"))

    c = convex_hull.Cloud(draw, points)
    cv = convex_hull.ConvHull(draw, c.cloud)

    st = simpleTriangulation(draw, c, cv)

    im.save("new.png")

