from PIL import Image, ImageDraw
import random


class Cloud(object):
    cloud = []

    def __init__(self, draw, points=100):
        self.draw = draw
        self.cloud = self.createPoints(points, self.draw)

    def createPoints(self, points, draw):
        x = []
        y = []
        for i in range(points):
            x.append(random.randint(30, 970))
            y.append(random.randint(30, 770))
            draw.point((x[i], y[i]), fill="black")

        return sorted(zip(x, y))


class ConvHull(object):
    polygon = []

    def __init__(self, draw, cloud):
        self.cloud = cloud
        self.polygon = self.convexHull(cloud)
        draw.polygon(self.polygon, fill=None, outline="black")

    def det(self, p, q, r):
        sum1 = q[0] * r[1] + p[0] * q[1] + r[0] * p[1]
        sum2 = q[0] * p[1] + r[0] * q[1] + p[0] * r[1]

        return sum1 - sum2

    def isRightTurn(self, p, q, r):
        "Do the vectors pq:qr form a right turn, or not?"

        # assert p != q and q != r and p != r

        if self.det(p, q, r) < 0:
            return 1
        else:
            return 0

    def convexHull(self, cloud):
        polygonL = []
        polygonU = []

        polygonL.append(cloud[0])
        polygonL.append(cloud[1])
        for i in range(2, len(cloud)):
            polygonL.append(cloud[i])
            while (len(polygonL) > 2 and (polygonL[-1] > polygonL[-2]) and not self.isRightTurn(
                    polygonL[-3], polygonL[-2], polygonL[-1])):
                del polygonL[-2]

        cloud.reverse()
        polygonU.append(cloud[0])
        polygonU.append(cloud[1])
        for i in range(2, len(cloud)):
            polygonU.append(cloud[i])
            while (len(polygonU) > 2 and (polygonU[-1] < polygonU[-2]) and not self.isRightTurn(
                    polygonU[-3], polygonU[-2], polygonU[-1])):
                del polygonU[-2]

        del polygonL[0]
        del polygonL[-1]

        return list(polygonU + polygonL)


if __name__ == '__main__':
    im = Image.new("RGBA", (1000, 800), (255, 255, 255, 255))
    draw = ImageDraw.Draw(im)

    points = int(input("How many points?"))
    c = Cloud(draw, points)
    cv = ConvHull(draw, c.cloud)
    im.save("new.png")