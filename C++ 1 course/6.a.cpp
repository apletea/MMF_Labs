#include <iostream>
#include <clocale>
#include <iomanip>
using namespace std;
const int maxsize = 100;

bool push(int b[], int &c, int elem)
{
    int k;
    cout<<"Введи число для добовления"<<endl;
    cin>>k;
    b[c++] = k;
    if (c >= maxsize) return 0;
    else
        return 1;
}

int pop(int b[], int &c) // эта ф-ция выполняет неверные действия!!! Она должна возвращать элемент из вершины!!! 
{
    if (c == 0){cout<<"Eror № странное задание"<<endl; return 0;}
    else
    {
     c--;
    }
}
int view ( int b[],int c)
{
    if(c)
    cout<<"голова массива:=  "<<b[c-1]<<endl;
    else
        cout<<"пусто"<<endl;
}
int view1 (int b[],int c)// непонятная ф-ция. Зачем она????
{
    if(c)
    cout<<"изьятие элемента := "<<b[c-1]<<endl;
    else
       return 0;
}
int kolvo (int top)
{
    cout<<"количетсво элементов в стеке:=  "<<top<<endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a[maxsize] = { 0 };
    int top = 0, element = 0;
    push(a, top, element++);
    push(a, top, element++);
    push(a, top, element++);
    view (a,top);
    kolvo (top);
    pop(a, top);
    kolvo(top);
    view1(a,top);
    pop(a,top);
    kolvo(top);
    view1(a,top);
    pop(a,top);
    kolvo(top);
    pop(a,top);
    push(a,top,element++);
    kolvo(top);

}
