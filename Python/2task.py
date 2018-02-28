#! /usr/bin/env python
# -*- coding: utf-8 -*-
import cv2
import numpy as np
import os

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

def get_str_no_sep(arr):
    string = ' '
    for i in arr:
        string = string+i
    return string

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


def task1(str):
    check_ = set({'a','e','o','n'})
    size = len(check_)
    char_counter = {char : 0 for char in check_}
    positions = []
    for i in xrange(0,len(str)):
        check_.add(str[i])
        print str[i]
        if (len(check_) == size):
            positions.append(i)
            char_counter[str[i]]+=1
        else:
            check_.remove(str[i])

    print positions
    print char_counter


def task2(str):
    is_gl = set({'a','e','i','o','u','y'})
    is_non = set({'q','w','r','t','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m',' ',',','.'})
    size = len(is_gl)
    for ichar in is_gl:
        str = str.replace(ichar,'1')
    for cjar in is_non:
        str = str.replace(cjar,'0')
    print str
    nums = str.split('1')
    true_nums = []
    print nums
    for i in xrange(0,len(nums)):
        if (nums[i] == '' and nums[i+1]==''):
            true_nums.append(1)
        elif (nums[i] == '' and nums[i+1]!=''):
            nums[i] == 1*(10**len(nums[i+1]))
            if nums[i] > 100:
                true_nums.append(100)
            else :
                true_nums.append(10)
            nums[i+1] = '00000'
    i = 0
    print true_nums


def task3(str1,str2,fathers_name):
    str = str1+str2
    str = filter((lambda char: char in fathers_name),str)
    print str
    return str

def task4(name,surname,ans):
    na_st = set(name)
    sur_st = set(surname)
    na_st = na_st.union(sur_st)
    print na_st
    char_counter = {char : 0 for char in na_st}
    for char in name:
        char_counter[char]+=1
    for char in surname:
        char_counter[char]+=1
    tmp =get_str_no_sep(set(filter((lambda char: char_counter[char]<=2),name+surname)))
    ans = ans+tmp
    print ans



str = 'aec pop aec '
fathers_name = 'urivich'
name = 'dzmitry'
surname = 'kamarouski'
ans = task3(str,str,fathers_name)
task4(name,surname,ans)
task2(str)
#task1(str)

