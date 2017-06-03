#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
//В программе объявлен массив А целых чисел (размер массива 100). Пользователь вводит число реально используемой части массива (число N). Эта часть затем заполняется случайными числами.
using std::cout;
using std::cin;
using std::endl;


void initialize (int mas[], int n) //инитиализация массива
{
	for (int i=0;i<n;i++)
	{
	mas[i]=rand()%50-25;
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

void inn (int & n)//ввод числа
{	
	cout<<"введите размер используемого масива"<<endl;
	cin>>n;
}

void sdvig (int mas[], int & n)//сдвиг
{
	
	for (int i=0;i<n-1;i++)
	{
		mas[i]=mas[i+1];
	}
	n=n-1;
}

void plus (int mas[], int &n)//добавление
{
	int k;
	cout<<"введите число "<<endl;
	cin>>k;
	n+=1;
	mas[n-1]=k;
}

	int main ()
{	

	setlocale (LC_ALL,"Russian");
	const int N=100;
	int mas[N];
	int n,q=1;
	inn(n);//ввод числа
	initialize (mas,n); //инитиализация массива
	while (q==1)
	{
		couuut(mas,n);//вывод массива
		sdvig (mas,n);//сдвиг
		plus (mas,n);//добавление

	}

}

