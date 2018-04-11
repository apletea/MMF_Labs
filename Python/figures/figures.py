#coding: utf-8
from Figure import Figure
from math import pi, sqrt


class Cube(Figure):

    def __init__(self, edge: float):
        self._figure_type = "Куб"
        self._edge = edge
        super().__init__()

    @property
    def edge(self):
        return self._edge

    def _count_area(self):
        return 4 * self._edge ** 2

    def _count_value(self):
        return self._edge ** 3


class Ball(Figure):

    def __init__(self, radius: float):
        self._figure_type = "Шар"
        self._radius = radius
        super().__init__()

    @property
    def radius(self):
        return self._radius

    def _count_area(self):
        return 4 * pi * self._radius ** 2

    def _count_value(self):
        return 4/3 * pi * self._radius ** 3


class RectangularParallelepiped(Figure):

    def __init__(self, a: float, b: float, h: float):
        self._figure_type = "Параллелипипед прямоугольный"
        self._a = a
        self._b = b
        self._h = h
        super().__init__()

    @property
    def a(self):
        return self._a

    @property
    def b(self):
        return self._b

    @property
    def h(self):
        return self._h

    def _count_area(self):
        return 2 * (self._a*self._h + self._b*self._h)

    def _count_value(self):
        return self._a * self._b * self._h


class Ellipsoid(Figure):
    def __init__(self, a: float, b: float, c: float):
        self._figure_type = "Эллипсоид"
        self._a = a
        self._b = b
        self._c = c
        super().__init__()

    @property
    def a(self):
        return self._a

    @property
    def b(self):
        return self._b

    @property
    def c(self):
        return self._c

    def _count_area(self):
        p = 1.6075
        return 4 * pi * (((self._a*self._b)**p + (self._a*self._c)**p + (self._b*self._c)**p)/3)**(1/p)

    def _count_value(self):
        return 4/3 * pi * self._a * self._b * self._c


class Torus(Figure):
    def __init__(self, r1: float, r2: float):
        self._figure_type = "Тор"
        self._r1 = r1
        self._r2 = r2
        super().__init__()

    @property
    def r1(self):
        return self._r1

    @property
    def r2(self):
        return self._r2

    def _count_area(self):
        return 4 * pi * pi * self._r1 * self._r2

    def _count_value(self):
        return 2 * pi * pi * self._r1 * self._r2 * self._r2


class Cone(Figure):
    def __init__(self, radius: float, h: float):
        self._figure_type = "Конус"
        self._radius = radius
        self._h = h
        super().__init__()

    @property
    def radius(self):
        return self._radius

    @property
    def h(self):
        return self._h

    def _count_area(self):
        return pi * self._radius * sqrt(self._radius**2 + self._h**2)

    def _count_value(self):
        return 1/3 * pi * self._h * self._radius ** 2


class Cylinder(Figure):
    def __init__(self, r: float, h: float):
        self._figure_type = "Цилиндр"
        self._r = r
        self._h = h
        super().__init__()

    @property
    def r(self):
        return self._r

    @property
    def h(self):
        return self._h

    def _count_area(self):
        return 2 * pi * self._r * self._h

    def _count_value(self):
        return pi * self._h * self._r**2
