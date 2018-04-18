import numpy as np
import pylab
import matplotlib.pyplot as plt

def point_val(y):
  return (0.75**(y))*(0.25**y)*((0.75**3) + (0.25)**3)

x = np.array([i for i in xrange(0,100)])
y = np.array([point_val(num) for num in x])
y1 = np.zeros((y.shape))
y1[0] = y[0]
for i in xrange(1, len(y)):
   y1[i] = y1[i-1] + y[i]

plt.plot(x,y,'o')
plt.plot(x,y,'g')
plt.plot(x,y1,'b') 
plt.grid(True)
plt.show()
