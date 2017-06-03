#!/bin/bash
echo введите день
read day

case "$day" in
	1) echo "понедельник";;
	2) echo "вторник";;
	3) echo "среда";;
	4) echo "четверг";;
	5) echo "пятница";;
	6) echo "суббота";;
	7) echo "воскресенье";;
esac
