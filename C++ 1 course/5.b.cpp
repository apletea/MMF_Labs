#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
//b) В программе объявлен массив целых чисел фиксированной "емкости" N. Пользователь вводит массив, затем пользователь вводит число, если такое число есть - то печатается его индекс, если такого числа нет об этом сообщается пользова- телю. При выполнении задания надо написать функцию, осуществляющую поиск в массиве. Она возвращает первый индекс, если таких чисел несколько, и -1 если такого числа нет.

using std::cout;
using std::cin;
using std::endl;


void initialize (int mas[], int N)//инитиализация массива
{
	for (int i=0;i<N;i++)
	{
	cin>>mas[i];
	}
}

void ink (int &k)//ввод числа
{
	cin>>k;
}

void poisk (int mas[], int N, int k) //поиск
{int q=-2;
	while (q==-2)
	{
	 	for (int i=0;i<N;i++)
	 	{
	 	if (mas[i]==k){q=k;}
	 	if ((i==N-1) && (q<0))q=-1;
		}
	}
	cout<<q;

}

	int main ()
{	

	setlocale (LC_ALL,"Russian");
	const int N=10;
	int mas[N];
	int k;
	initialize (mas,N);//инитиализация массива
	ink(k);//ввод числа
	poisk (mas,N,k);//поиск



}

