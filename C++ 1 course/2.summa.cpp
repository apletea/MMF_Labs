//Вводятся числа до первого отрицательного,выводится сумма чисел
#include <iostream>
#include <clocale>
using std::endl;
using std::cin;
using std::cout;

int main()
{ int num,sum;
  num=0;sum=0;
        while (num>=0){
            sum=sum+num;
            cout<<"Введи число";
            cin>>num;}
  cout<<"sum="<<sum<<endl;
  return 0;
}
