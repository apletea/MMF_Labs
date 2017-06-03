sum=0

echo "введите число"
read a

len=`expr length $a`

while [ "$len" -gt 0 ]
do
	sum=$(($sum+$a%10))
	a=$(($a/10))
	len=$(($len-1))
done

echo "сумма цифр $sum"
