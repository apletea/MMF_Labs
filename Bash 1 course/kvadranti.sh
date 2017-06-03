#!/bin/bash


echo "введите х"
read x

echo "введите у"
read y

if [ "$x" -eq 0 ]
then
  if [ "$y" -eq 0 ]
  then
    echo "В начале координат"
  elif [ "$y" -lt 0 ]
  then
    echo "В левой полуплоскости"
  else
    echo "В правой полуплоскости"
  fi
elif [ "$x" -lt 0 ]
then
  if [ "$y" -eq 0 ]
  then
    echo "В нижней полуплоскости"
  else
    if [ "$y" -lt 0 ]
    then
      echo "3 квадрант"
    else
      echo "2 квадрант"
    fi
  fi
else
  if [ "$y" -eq 0 ]
  then
    echo "В верхней полуплоскости"
  else
    if [ "$y" -lt 0 ]
    then
      echo "4 квадрант"
    else
      echo "1 квадрант"
    fi
  fi
fi
