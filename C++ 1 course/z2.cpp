//Вести число,выяснить является ли оно зеркальным
#include <iostream>
#include <clocale>
using std::endl;
using std::cin;
using std::cout;

int main(){
    setlocale(LC_ALL,"Russian");
    int a=0,a1=0,i=0,i1=0,q=0,r1=0,r2=0,q1=0,p1=0,p2=0;
    cout << "Введите число" << endl;
    cin>>a;
    a1=a;
            while(a>0){
            i++;
            a=a/10;}
    i--;
             while(i>q){
             r1=1;
             r2=1;
             q1=q;
             i1=i;
             p1=a1;
             p2=a1;
                    while (q1>0){
                    r1=r1*10;
                    q1--;}
                    while (i1>0){
                    r2=r2*10;
                    i1--;}
             p1=(p1/r1)%10;
             p2=(p2/r2)%10;
                    if (p1==p2){
                    q++;
                    i--; }
                    else {
                    i=-5;}}
    if (i==-5) {
        cout<<"число "<<a1<<" не является зеркальным"<<endl;}
    else {
        cout<<"число "<<a1<<" зеркально"<<endl;}
    return 0;}
