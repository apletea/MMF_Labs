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
void couut(char A[],int N)
{
    cout<<" массив сейчас"<<endl;
    for (int i=0;i<N;i++)
    {
        cout<<A[i]<<"  ";
    }
    cout<<" "<<endl;
}

void zamena (char A[], int N)
{
    int a=0,i=N-1;

    while (!a)
    {
        if (A[i]=='Z') {A[i]='F';a++;}//может проще по break выходить из цикла????
        if (a==0 && i==0){cout<<"букв Z тут нет";a=2;}
        i--;
    }
}



int main()
{
     setlocale(LC_ALL,"Russian");
     int  const N=20;
     char A[N];
     init (A,N);
     couut (A,N);
     zamena (A,N);couut (A,N);
}
