#!/bin/bash

read n
sum=0

sumDig ()
{
  k=$1
  if [ "$((k/10))" -eq 0 ]
  then return $k
  else sum=$(($sum+sumDig $((k/10))))
}

sumDig $n
echo "Сумма цифр = $?"

