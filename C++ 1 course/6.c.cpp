#include <iostream>
#include <clocale>
#include <iomanip>


using namespace std;

void init (char A[], int N)
{
    cout<<"введите двадцать букв"<<endl;
    for (int i=0;i<N;i++)
    {
        cin>>A[i];
    }
}

void poisk (char A[], int N)
{   char a,qmx;
    int j,mx,g;
    mx=0;
    g=0;
    for (int i=0;i<N;i++)
    {
    j=1;
    a=A[i];
        for (int q=i+1;q<N;q++)
        {
            if ((int)a==(int)A[q]){j++;}// зачем преобразования типов?????
        }
    if (j>mx) {mx=j;qmx=a;g=0;}
    if (j==mx){g++;}
    }
    if (!g)
        {
        cout<<"чаще всего встречается "<<qmx<<"   "<<mx<<"раз"<<endl;
        }
    else cout<<"нет элемент который встречается часте чем все остальные";
}


int main()
{   setlocale(LC_ALL,"Russian");
     int  const N=20;
    char A[N];
    init (A,N);
    poisk (A,N);
}
