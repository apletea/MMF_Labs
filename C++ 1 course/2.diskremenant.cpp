//написать программу решающие квадратное уравнение (елси D<0,комлпекслными числами вывести ответ)
#include <iostream>
#include <cmath>
#include <clocale>
using namespace std;

int main()
{
setlocale(LC_ALL,"Russian");
int a=0,b=0,c=0;
float D,x1,x2;
D=0;x1=0;x2=0;
cout << "Введи a=";
cin>>a;
cout << "Введи b=";
cin>>b;
cout << "Введи c=";
cin>>c;
    if (a==0)  {
        if ((a==0) && (b==0)){
            if ((a==0) && (b==0) && (c==0)){
            cout<<"х любое число";}
            else {
                cout<<"нет решений";}}
        if ((a==0) && (b!=0)){
            x1=b*(-1);
            x1=c/x1;
        cout<<"x="<<x1;}}
    else{
        D=b*b-a*c*4;
            if (D>0){
                D=sqrt(D);
                x1=(0-b+D)/(2*a);
                x2=(0-b-D)/(2*a);
                cout<<"x1="<<x1<<"    "<<"x2="<<x2;}
            if (D==0){
               x1=(0-b)/(2*a);//исправил эту строчку
                cout<<"x1="<<x1;}
            if (D<0){
                    if (b==0){
                        D=D*(-1);
                        D=sqrt(D);
                        D=D/(2*a);
                        cout<<"x="<<D<<"*i"<<endl;}
                     else{
                        D=D*(-1);
                        D=sqrt(D);
                        D=D/(2*a);
                        x1=(0-b)/(2*a);//исправил эту строчку
                        cout<<"x1="<<x1<<"+"<<D<<"*i"<<endl;
                        cout<<"x1="<<x1<<"-"<<D<<"*i"<<endl;}}}
    return 0;
}
