//вводится целое число,сгенерировать перевёрнтутое число
#include <iostream>
#include <clocale>

using std::endl;
using std::cin;
using std::cout;

int main()
{   setlocale(LC_ALL,"Russian");
    int a=0,a1=0,sum1=0,sum2=0,res=0,i=0;
    cout<<"Введи число"<<endl;
    cin>>a;
    a1=a;
          while (a>0){
          i++;
          a=a/10; }
          while (a1>0){
          int q=0;
          i--;
          int h=0;
          h=i;
          q=a1%10;
          sum1=1;
                    while (h>0){
                    sum1=sum1*10;
                    h--;
                            }
          a1=a1/10;
          sum2=sum1*q;
          res=res+sum2;}
    cout<<"перевёрнутое число = "<<res;
    return 0;

}
