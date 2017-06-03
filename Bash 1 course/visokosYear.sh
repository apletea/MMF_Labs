#!/bin/bash
echo "введите год" 
read year

if [ "$(($year % 100))" -eq 0 ]
then
  if [ "$(($year %400))" -eq 0 ]
  then
    echo "високосный"
    exit "0"
  else
    echo "не високосный"
    exit "0"
  fi
fi 

if [ "$(($year % 4))" -eq 0 ]
then
  echo "високосный"
else
  echo "не високосный"
fi 
