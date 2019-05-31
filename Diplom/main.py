import sys
import cv2
import os

import cv2
import numpy as np
cap = cv2.VideoCapture("vid.mp4")

ret, frame1 = cap.read()
prvs = cv2.cvtColor(frame1,cv2.COLOR_BGR2GRAY)
hsv = np.zeros_like(frame1)
hsv[...,1] = 255
inte = None


def convert_offsets(flow):
    mag, ang = cv2.cartToPolar(flow[...,0], flow[...,1])
    hsv[...,0] = ang*180/np.pi/2
    hsv[...,2] = cv2.normalize(mag,None,0,255,cv2.NORM_MINMAX)
    bgr = cv2.cvtColor(hsv,cv2.COLOR_HSV2BGR)
    return bgr
i = 0
while(1):
    ret, frame2 = cap.read()

    next = cv2.cvtColor(frame2,cv2.COLOR_BGR2GRAY)
    flow = cv2.calcOpticalFlowFarneback(prvs,next, None, 0.5, 3, 15, 3, 5, 1.2, 0)
    if inte is None:
        inte = flow
    else:
        inte += flow
    bgr      = convert_offsets(flow)
    interbgr = convert_offsets(inte)

    cv2.imshow('frame2',bgr)
    cv2.imshow('frame1', prvs)
    cv2.imshow('integral_opt_flow', interbgr)
    cv2.imwrite(f'./integral/{i}.jpg', interbgr)
    cv2.imwrite(f'./optflow/{i}.jpg', bgr)
    i += 1
    k = cv2.waitKey(30) & 0xff
    prvs = next

cap.release()
cv2.destroyAllWindows()
