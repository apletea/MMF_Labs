#!/bin/bash

echo введите символ
read letter

case "$letter" in
	[a-zA-Z]) echo буква;;
	[0-9]) echo цифра;;
	а) echo буква;;
	б) echo буква;;
	в) echo буква;;
	г) echo буква;;
	д) echo буква;;
	е) echo буква;;
	ё) echo буква;;
	ж) echo буква;;
	з) echo буква;;
	и) echo буква;;
	й) echo буква;;
	к) echo буква;;
	л) echo буква;;
	м) echo буква;;
	н) echo буква;;
	о) echo буква;;
	п) echo буква;;
	р) echo буква;;
	с) echo буква;;
	т) echo буква;;
	у) echo буква;;
	*) echo управляющий символ
esac
