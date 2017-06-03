#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
// В программе объявлен массив А целых чисел (размер массива 100). Пользователь вводит число реально используемой части массива (число N). Эта часть затем заполняется последовательно числами от 1 до N. Затем пользователь вводит произвольное число и мы его помещаем в отсортированный А так, чтобы не нарушить порядок и изменяем значение N на единицу. Затем пользователь вводит произвольное число и если оно есть в массиве (используйте ф-цию из задачи а)) то оно удаляется.

using std::cout;
using std::cin;
using std::endl;


void initialize (int mas[], int n) //инитиализация массива
{
	for (int i=0;i<n;i++)
	{
	mas[i]=i+1;
	}
}

void couuut (int mas[], int n) // вывод массива
{
	for (int i=0;i<n;i++)
	{
	cout<<mas[i]<<"  ";
	}
	cout<<""<<endl;
}

void inn (int & n)//вводчисла 
{
	cout<<"введите число"<<endl;
	cin>>n;
}

void vvod1 ( int mas[], int & n)
{	int k;
	cout<<"введите число которое хотите поместить в массив"<<endl;
	cin>>k;
	n++;
	for (int i=0;i<n;i++)
	{
		if (k==mas[i])
		{
			 for (int a=n;a>=i;a--)
	   		 {
	   		  mas[a]=mas[a]+1;
			 }
			mas[i]=k;
		}

	}
	if (k<mas[0])
		{
		  for (int a=n;a>=n;a--)
	   		 {
	   		  mas[a]=mas[a]+1;
			 }
		  mas[0]=k;
		}
	if (k>mas[n])
		{
		mas[n+1]=k;
		}

}

void vvod2 (int mas[], int & n)
{
	int k,w=0;
	cout<<"введите число,если оно будет в массиве оно удалится"<<endl;
	cin>>k;
	for (int i=0;i<n;i++)
	{
		
		if (mas[i]==k)
			{
			for (int a=i;a<n;a++)
				{
				mas[a]=mas[a+1];
				}
				n--;
			}
	}

}

	int main ()
{	

	setlocale (LC_ALL,"Russian");
	const int N=100;
	int mas[N];
	int n,q=1;
	int k;
	inn(n);//ввод числа
	initialize (mas,n); //инитиализация массива
	couuut (mas,n);
	while (q==1)
	{
		vvod1 (mas,n);
		vvod2 (mas,n);
		couuut (mas,n);
	}


}

