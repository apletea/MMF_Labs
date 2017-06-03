#!/bin/bash

sum=0

if [ $# -ne 3 ]
then
  echo ошибка, нужны 3 числовых аргумента
  exit 1
fi

for i in $@
do
   sum=$(($sum+$i))
done

echo "Среднее арифметическое: $(echo "scale=2; $sum/$#" | bc)"
