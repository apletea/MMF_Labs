#include <iostream>
#include <clocale>

using std::cin;
using std::cout;
using std::endl;

int xorshift128(int x)
 {
    int t;
    int a=13,b=15,c=5;
    t = x ^ (x << a);
    t = t ^ (t >> b);

    return x = x ^ (t << c);
}
void initialize (int mas[],int N)
{     mas[0]=5;
     for (int i=1;i<N;i++)
     {
         mas[i]=xorshift128(mas[i-1]);
     }
     for (int i=1;i<N;i++)
     {
         mas[i]=mas[i]%51;
     }

}
void couut (int mas[],int N)
{
    for (int i=0;i<N;i++)
    {
        cout<<mas[i]<<"  ";
    }
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




void taskC (int mas[],int N)//задание с
{ int mx,mn,j=0;
    mxmn(mas,N,mx,mn);
     for (j=0;j<N;j++)
      {
          if (mas[j]==0){mas[j+1]=999;break;}
      }
      for (j=0;j<N;j++)
      {
          if (mas[j]==mn){mas[j+1]=111;break;}
      }
      for (j=0;j<N;j++)
      {
          if (mas[j]==mx){mas[j-1]=222;break;}
      }



}


int main()
{  const int N=25;
   setlocale(LC_ALL,"Russian");
   int mas[N];
   initialize(mas,N);//инитиализация массива
   couut(mas,N);//массив до изменений
   taskC(mas,N);//задание С
   couut(mas,N);//массив после изменнений
   return 0;
}

