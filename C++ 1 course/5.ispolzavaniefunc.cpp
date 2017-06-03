#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;

void couut (int mas[],int N)
{
    for (int i=0;i<N;i++)
    {
        cout<<mas[i]<<"  ";
    }
	cout<<"  "<<endl;
}

void initialize ( int mas[], int N)//инитиализация массива
{
	for (int i=0;i<N;i++)
	{
	mas[i]=rand()%50-25;
	}
}
void perestanovka (int mas[], int N)// В массиве случайных целых чисел *первый положительный элемент и последний отрицательный элемент переставить местами.
{
	int k=N-1,i=0;
	while (mas[i]<0){i++;}
	while (mas[k]>0){k--;}
	mas[i]=mas[i]-mas[k];
	mas[k]=mas[k]+mas[i];
	mas[i]=mas[k]-mas[i];
}
void mxmn (int mas[],int N, int &mx, int &mn)
{
  mx=mas[0];
  mn=mas[0];
    for (int i=0;i<N;i++)
    {
        if (mas[i]>mx){mx=mas[i];}
        if (mas[i]<mn){mn=mas[i];}
    }

}
void zamena (int mas[], int N)//все четные элементы заменить максимальным элементом, а нечетные — минимальным.
{
    int mx,mn;
    mxmn(mas,N,mx,mn);
     for (int i=0;i<N;i++)
     {
     	if (i%2==0){mas[i]=mx;}
     	else {mas[i]=mn;}
     }

}
void poiskmx (int mas[], int N)//найти максимальный из элементов, встречающихся только один раз.
{
     int mn,mx,g=0,k=2,w;
     mx=mas[0];
     mn=mas[0];
     while (k==2)
     {
     	int j=0;
      	for (int i=0;i<N;i++)
    	{
       		 if (mas[i]==mx){g++;}
       		 if (mas[i]>mx){mx=mas[i];g=1;}
       		 if (mas[i]<mn){mn=mas[i];}
       	}
    	if (g==1){
       		while (mas[j]!=mx)
       		{j++;k=1;}
       		w=j;}
		else 
		{
			for (int i=0;i<N;i++)
			{
		 		if (mas[i]==mx){mas[i]=mn;}
			}
		}
     }
     cout<<"максимальнеый элемент встречающийся только один раз:"<<w<<"равный:="<<mx<<endl;
}

void poiskmn (int mas[], int N)//найти минимальное из чисел, встречающихся более одного раза.
{
     int mn,mx,g=0,k=2,w;
     mx=mas[0];
     mn=mas[0];
     while (k==2)
     {
     	int j=0;
      	for (int i=0;i<N;i++)
    	{
       		 if (mas[i]==mn){g++;}
       		 if (mas[i]>mx){mx=mas[i];}
       		 if (mas[i]<mn){mn=mas[i];g=1;}
       	}
    	if (g!=1){
       		while (mas[j]!=mn)
       		{j++;k=1;}
       		w=j;}
		else 
		{
			for (int i=0;i<N;i++)
			{
		 		if (mas[i]==mn){mas[i]=mx;}
			}
		}
     }
     cout<<"минимальный элемент встречающийся более одного раза:"<<w<<"равный:="<<mn<<endl;

}
void posl (int mas[], int N) //* определить максимальную длину последовательности равных элементов.
{
   int k=0,kmx=0;
   for (int i=0;i<N;i++)
	{
         k=0;
		int a=mas[i];
		while (mas[i]==a)
		{
		k++;
		i++;
		}
		if (k>kmx){kmx=k;}
	}
	cout<<"максимальная длина последовательности равных элементов :="<<kmx<<endl;
}

	int main ()
{	
	setlocale (LC_ALL,"Russian");
	int const N=25;
	int mas[N];
	initialize (mas,N);//инитиализация массива 
	couut(mas,N);
	perestanovka (mas,N);//первый положительный элемент и последний отрицательный элемент переставить местами.
	couut(mas,N);
	zamena (mas, N);//все четные элементы заменить максимальным элементом, а нечетные — минимальным.
	couut(mas,N);
	initialize (mas,N);//инитиализация массива 
	couut(mas,N);
	poiskmx (mas,N);//найти максимальный из элементов, встречающихся только один раз.
	initialize (mas,N);//инитиализация массива 
	couut(mas,N);
	poiskmn(mas,N);//найти минимальное из чисел, встречающихся более одного раза.
	initialize (mas,N);//инитиализация массива 
	couut(mas,N);
	posl(mas,N);//* определить максимальную длину последовательности равных элементов.



}

