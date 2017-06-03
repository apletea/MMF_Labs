#!/bin/bash

echo "Колтчесво аргументов: $#"
sum=0
for i in $@ 
do
   sum=$(($sum+$i))
done
echo "Сумма аргументов: $sum"
