#!/bin/bash

echo введите букву
read letter

case "$letter" in
	а) echo гласная;;
	у) echo гласная;;
	о) echo гласная;;
	ы) echo гласная;;
	и) echo гласная;;
	э) echo гласная;;
	я) echo гласная;;
	ё) echo гласная;;
	ю) echo гласная;;
	я) echo гласная;;
	и) echo гласная;;
	*) echo согласная;;
esac
