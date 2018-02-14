#! /usr/bin/env python
# -*- coding: utf-8 -*-
import cv2
import numpy as np
import os
print 'hi'

def sieve_of_eratoshjen(N):
    arr = np.array([1 for i in xrange(0,N+1)])
    arr[0] = 0
    arr[1] = 0
    for i in xrange(2,len(arr)):
        print i
        for j in xrange(i+1,len(arr)):
            if (j%i==0):
                arr[j] = 0
    ans = []
    for i in xrange(0,len(arr)):
        if (arr[i] == 1):
            ans.append(i)
    return ans

def get_str(arr):
    string = ' '
    for i in arr:
        string = string+str(i) + ', '
    return string

def get_str_no_commos(arr):
    string = ' '
    for i in arr:
        string = string+str(i) + ' '
    return string

N = input()
N = int(round(N))
n = input()
n = int(round(n))
pro=np.array(sieve_of_eratoshjen(N))
print 'кол-во простых чисел: {}'.format(len(pro))
for power in xrange(1,n+1):
    print '{}-е степени: {}'.format(power,get_str(pow(pro,power)))

arr = []
while True:
    a = input()
    if (a == -1):
        break
    arr.append(a)
# arr = [5,10,15,20,25,30]
arr_max = max(arr)
arr_min = min(arr)
N = arr_min
M = arr_max
count_N = 0
count_M = 0
idx_N = []
idx_M = []
for i in xrange(0,len(arr)):
    if (N < arr[i] and arr[i] != arr_max):
        N = arr[i]
        count_N = 0
        idx_N = []
    if (M > arr[i] and arr[i] != arr_min):
        M = arr[i]
        count_M = 0
        idx_M = []
    if (arr[i] == N):
        count_N+=1
        idx_N.append(i+1)
    if (arr[i] == M):
        count_M+=1
        idx_M.append(i+1)

print 'M={} N={}'.format(M,N)
print 'кол-во вхождений M={} кол-во вхождений N={}'.format(count_M,count_N)
print 'вхождения M={}'.format(get_str(idx_M))
print 'вхождения N={}'.format(get_str(idx_N))

def check_upper(arr):
    for i in xrange(1,len(arr)):
        if (arr[i]<arr[i-1]):
            return False
    return True

def check_lower(arr):
    for i in xrange(1,len(arr)):
        if (arr[i]>arr[i-1]):
            return False
    return True

arr = [1,-1,-2]
if (check_upper(arr)):
    print 'Возрастающая'
elif (check_lower(arr)):
    print 'Убывающая'
else:
    print 'Не обладающая свойтсвом монатонности'

for i in  xrange(0,len(arr)):
    for j in xrange(i,len(arr)):
        if (arr[j]< arr[i]):
            arr[i],arr[j] = arr[j],arr[i]

for i in xrange(0,len(arr)):
    print get_str_no_commos(arr[0:i+1])

A = int(input())
B = int(input())
C = int(input())
D = int(input())
ans = []
for i in xrange(1,D/A):
    for j in xrange(1,D/B):
        for k in xrange(1,D/C):
            if ((i*A + B*j + C*k) == D):
                ans.append([i,j,k])
print 'Всего решений : {}'.format(len(ans))
for i in xrange(0,len(ans)):
    print '{}-й набор: {}'.format(str(i+1),get_str_no_commos(ans[i]))
# def load_test_data():
#     X = []
#     y = []
#
# print os.listdir('./train/')
