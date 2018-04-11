#coding: utf-8
from figures import *
from importantExceptions import IncorrectDataException


def ball_parser(data):
    if len(data) != 2:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        if line1[0].lower() != "радиус":
            raise IncorrectDataException
        else:
            return Ball(float(line1[1]))


def cube_parser(data):
    if len(data) != 2:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        if line1[0].lower() != "ребро":
            raise IncorrectDataException
        else:
            return Cube(float(line1[1]))


def rect_parser(data):
    if len(data) != 4:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        line2 = data[2].split(':')
        line3 = data[3].split(':')
        if line1[0].lower() != "сторона основания 1" or line2[0].lower() != "сторона основания 2" \
                or line3[0].lower() != "высота":
            raise IncorrectDataException
        else:
            return RectangularParallelepiped(float(line1[1]), float(line2[1]), float(line3[1]))


def cylinder_parser(data):
    if len(data) != 3:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        line2 = data[2].split(':')
        if line1[0].lower() != "радиус основания" or line2[0].lower() != "высота":
            raise IncorrectDataException
        else:
            return Cylinder(float(line1[1]), float(line2[1]))


def cone_parser(data):
    if len(data) != 3:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        line2 = data[2].split(':')
        if line1[0].lower() != "радиус основания" or line2[0].lower() != "высота":
            raise IncorrectDataException
        else:
            return Cone(float(line1[1]), float(line2[1]))


def ellipsoid_parser(data):
    if len(data) != 4:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        line2 = data[2].split(':')
        line3 = data[3].split(':')
        if line1[0].lower() != "большая полуось" or line2[0].lower() != "средняя полуось" \
                or line3[0].lower() != "малая полуось":
            raise IncorrectDataException
        else:
            return Ellipsoid(float(line1[1]), float(line2[1]), float(line3[1]))


def torus_parser(data):
    if len(data) != 3:
        raise IncorrectDataException
    else:
        line1 = data[1].split(':')
        line2 = data[2].split(':')
        if line1[0].lower() != "внешний радиус" or line2[0].lower() != "внутренний радиус":
            raise IncorrectDataException
        else:
            return Torus(float(line1[1]), float(line2[1]))


def parser(data):
    if data[0].strip('\n').lower() == "шар":
        return ball_parser(data)
    elif data[0].strip('\n').lower() == "куб":
        return cube_parser(data)
    elif data[0].strip('\n').lower() == "прямоугольный параллелепипед":
        return rect_parser(data)
    elif data[0].strip('\n').lower() == "цилиндр":
        return cylinder_parser(data)
    elif data[0].strip('\n').lower() == "конус":
        return cone_parser(data)
    elif data[0].strip('\n').lower() == "эллипсоид":
        return ellipsoid_parser(data)
    else:
        return torus_parser(data)


