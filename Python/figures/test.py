#coding: utf-8
from Parsers import parser
from importantExceptions import IncorrectDataException


if __name__ == "__main__":

    figure_names_list = ["куб", "шар", "эллипсоид", "тор", "прямоугольный параллелепипед",
                         "цилиндр", "конус"]
    output_list = []
    tmp_list = []

    with open("input.txt", 'r', encoding="utf-8") as f:
        # Reading all figures but not last
        for line in f:
            if line != "\n":
                tmp_list.append(line)
            elif tmp_list[0].strip('\n').lower() not in figure_names_list:
                output_list.append("Неизвестная фигура.\n" +
                                   "(Это достаточно тупая программа, так что, возможно, вы не виноваты)\n\n")
                tmp_list = []
            else:
                try:
                    output_list.append(str(parser(tmp_list)))
                    tmp_list = []
                except IncorrectDataException:
                    output_list.append("Что-то не так со входными данными на данную фигуру({})\n\n"
                                       .format(tmp_list[0].strip('\n')))
                    tmp_list = []

        # Reading last figure
        if tmp_list[0].strip('\n').lower() not in figure_names_list:
                output_list.append("Неизвестная фигура.\n" +
                                   "(Это достаточно тупая программа, так что, возможно, вы не виноваты)\n\n")
                tmp_list = []
        else:
            try:
                output_list.append(str(parser(tmp_list)))
                tmp_list = []
            except IncorrectDataException:
                output_list.append("Что-то не так со входными данными на данную фигуру({})\n\n".format
                                   (tmp_list[0].strip('\n')))
                tmp_list = []

    with open("output.txt", 'w', encoding="utf-8") as f:
        for output in output_list:
            f.write(output)



