#!/bin/bash
echo введите а
read a

echo введите операцию
read operation

echo введите b
read b

case "$operation" in
	+) echo a+b=$(($a+$b));;
	/) echo a/b=$(($a/$b));;
	-) echo a-b=$(($a-$b));;
	*) echo a*b=$(($a*$b));;
esac
