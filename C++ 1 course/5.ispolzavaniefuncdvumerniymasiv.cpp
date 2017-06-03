#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

void couut (int mas[][5])
{
    for (int i=0;i<5;i++)
	{	for (int j=0;j<5;j++)
		{
			cout<<mas[i][j]<<"  ";
		}
		cout<<" "<<endl;
	}
	cout<<"  "<<endl;
}

void initialize ( int mas[][5])//инитиализация массива
{
	for (int i=0;i<5;i++)
	{	for (int j=0;j<5;j++)
		{
			mas[i][j]=rand()%20-10;
		}
	}
}
void sedltchk (int mas[][5])//седловая точка
{ int mn,k,q=0,m=0;

	for (int i=0;i<5;i++)
	{	k=0;
		q=0;
		mn=mas[i][0];
		for (int j=0;j<5;j++)
		{
			if (mn>mas[i][j]){mn=mas[i][j];k=j;}
		}
		for (int a=0;a<5;a++)
		{
		 	if(mn<mas[a][k]){q++;}
		}
		if (q==0) {cout<<"селовая точка ="<<mas[i][k]<<"  находится в"<<i<<"столбце и "<<k<<"строке"<<endl;m++;}

	}
	if (m==0)
		cout<<"седловых точек нет"<<endl;

}
void summ (int mas[][5])//сумма главной диагонали матрици
{
	int sum=0;
	for (int i=0;i<5;i++)
	{
		sum=sum+mas[i][i];
	}
	cout<<"сумма главной диагонали матрици sum:="<<sum<<endl;
}
void sumtr(int mas[][5])//сумма нижнего треугольника матрици
{
int sum=0;
	for (int i=0;i<5;i++)
	{
		for (int j=0;j<=i;j++)
		{
		sum=sum+mas[i][j];
		}
	}
cout<<"сумма нижнего треугольника матрици sumtr:="<<sum<<endl;
}

	int main ()
{	

	setlocale (LC_ALL,"Russian");
	int mas[5][5];
	initialize (mas);//инитаализация
	couut (mas); //вывод
	sedltchk (mas);//седловая точка
	summ(mas);//сумма главной диагонали матрици
	sumtr(mas);//сумма нижнего треугольника матрици



}

