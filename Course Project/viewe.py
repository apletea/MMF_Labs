import cv2
import pandas as pd
import numpy as np
import os
from scipy import ndimage



def parse_log(log,i):
  return [],[]

def aproximate_log(log):
  return []

log = pd.read_csv('log(3).txt',sep='|')
print log.head()
vc = cv2.VideoCapture('/home/apletea/work/vid.mp4')
i = 0
while True:
  _,frame = vc.read()
#  frame = ndimage.rotate(frame, -90)
  acc,gyro = parse_log(log,i)
  acc,gyro = aproximate_log(acc),aproximate_log(gyro)
  print frame.shape
  cv2.putText(frame, 'Accselerometr:' + str(acc) , (20, frame.shape[0]-60), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2, cv2.LINE_AA)
  cv2.putText(frame, 'Gyroscope    :' + str(gyro), (20, frame.shape[0]-10), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2, cv2.LINE_AA)
  cv2.imshow('frame',frame)
  cv2.waitKey(5)

