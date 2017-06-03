#!/bin/bash

echo "введите n"
read n

echo "введите x"
read x

pow=x
fact=1
sum=1
i=1

while [ "$i" -lt "$n" ];
do
  tmp=$(echo "scale=12; $pow/$fact" | bc)
  sum=$(echo "scale=12; $sum+$tmp" | bc)
  pow=$(echo "scale=12; $pow*$x" | bc)
  i=$(($i+1))
  fact=$(($fact*$i))
echo $(echo "scale=12; $pow*$x" | bc)
done

echo "Сумма ряда равна $sum"
