//найти сумму чётных и нечётных позиций,проверить делимость на 11.
#include <iostream>
#include <clocale>

using std::endl;
using std::cin;
using std::cout;

int main()
{   setlocale(LC_ALL,"Russian");
    int a=0,sum1=0,sum2=0,res=0,i=1;
    cout<<"Введи число"<<endl;
    cin>>a;
    i=1;
    while (a>0){
    int q=0;
          q=a%10;
          if (i%2==0){
          sum1=sum1+q;}
          else {
          sum2=sum2+q;}
          i++;
          a=a/10; }
    cout<<"sum1="<<sum1<<endl;
    cout<<"sum2="<<sum2<<endl;
          res=sum1-sum2;
    if (res==0){cout<<"число делится на 11";}
    else {cout<<"число не делится на 11";}
    return 0;

}
