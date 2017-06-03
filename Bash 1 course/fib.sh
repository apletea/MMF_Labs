#!/bin/bash

echo "введите количество членов Фибоначчи"
read n

a=0
b=1
i=0

while [ "$i" -lt "$n" ]; do
	a=$(($a + $b))
	printf "$a "
	b=$(($a - $b))

	i=$(($i+1))
done

echo
