//Ввести целое число,вывести наибольшую цифру и на какой оно позиции
#include <iostream>
#include <clocale>

using std::endl;
using std::cin;
using std::cout;

int main()
{setlocale(LC_ALL,"Russian");
    int num=0,mx=0,num1=0,q=0,i=1;
    cout << "Введи число" << endl;
    cin>>num;
    num1=num;
        while (num1>0){
            q=num1%10;
                if (q>mx){mx=q;}
            num1=num1/10;}
    cout<<"цифра "<<mx<<" самая большая в числе. Стоит на ";
        while (num>0){
            q=num%10;
                if(q==mx){cout<<i<<"  ";}
            i++;
            num=num/10;}
    cout<<"позициях справа";
    return 0;
}
