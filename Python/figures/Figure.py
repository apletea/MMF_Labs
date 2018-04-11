#coding: utf-8
class Figure:

    def __init__(self):
        self._area = float('{:.3f}'.format(self._count_area()))
        self._value = float('{:.3f}'.format(self._count_value()))

    @property
    def figure_type(self):
        return self._figure_type

    @property
    def value(self):
        return self._value

    @property
    def area(self):
        return self._area

    def __str__(self):
        return "{}\nБоковая поверхность: {}\nОбъем: {}\n\n".format(self._figure_type, self._area, self._value)

    def _count_area(self):
        raise NotImplementedError

    def _count_value(self):
        raise NotImplementedError

    def __del__(self):
        print("Вычисления закончены(area:{0}, value:{1})".format(self._area, self._value))
