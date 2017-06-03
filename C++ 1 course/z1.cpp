//найти сумму цифр числа до первого встреченого 0
#include <iostream>
#include <clocale>

using std::endl;
using std::cin;
using std::cout;

int main()
{   setlocale(LC_ALL,"Russian");
    int a=0,sum1=0;
    cout<<"Введи число"<<endl;
    cin>>a;
          while (a!=0){
          int q=0;
          q=a%10;
                if (q==0) {
                a=0;}
          sum1=sum1+q;
          a=a/10; }
    if (sum1==0){
            cout<<"число заканчивается на ноль";}
    else{
          cout<<"sum1="<<sum1<<endl;}
    return 0;

}
