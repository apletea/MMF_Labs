import numpy as np
import matplotlib.pyplot as plt
import pylab
import math

def ex():
    # Come up with x and y
    x = np.arange(0, 5, 0.1)
    y = np.sin(x)

    # Just print x and y for fun
    print
    x
    print
    y

    # plot the x and y and you are supposed to see a sine curve
    plt.plot(x, y)

    # without the line below, the figure won't show
    pylab.show()




def main():
    x = np.array([0,math.pi/6,math.pi/4,math.pi/3,math.pi/12])
    x_in = math.pi/5

    y = math.tan(x)**2
    print(y)




main()