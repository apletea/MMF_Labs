#!/bin/bash
echo "введите число"
read a

i=$(($a-1))

while [ "$i" -gt 1 ]
do
	if [ "$(($a%$i))" -eq 0 ]
	then
		echo "простым не является"
		exit 0
	fi

	i=$(($i-1))
done

echo "простое"
