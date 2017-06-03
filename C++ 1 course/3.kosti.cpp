#include <iostream>
#include <clocale>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

int main()
//Напишите игру в кости между человеком и компьютером. Они по очереди кидают по два кубика. Побеждает тот у кого сумма больше. Кубики рисуйте псевдографикой
{   int a,b,c,res1,res2;
    setlocale(LC_ALL,"Russian");
    while (1>0){
    cout << "Введите 1 чтобы играть" << endl;
    cin>>a;
        if (a==1){
            b=rand()%6+1;
            c=rand()%6+1;
            cout<<"Ваш бросок"<<endl;
                if (b==1) {
                    cout<<"-----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"-----"<<endl;}
                if (b==2) {
                    cout<<"-----"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-----"<<endl;}
                if (b==3) {
                    cout<<"o----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"----o"<<endl;}
                if (b==4) {
                    cout<<"--o--"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"--o--"<<endl;}
                if (b==5) {
                    cout<<"--o--"<<endl;
                    cout<<"o-o-o"<<endl;
                    cout<<"--o--"<<endl;}
                if (b==6) {
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;}
                    cout<<"  "<<endl;
                    cout<<"  "<<endl;
                if (c==1) {
                    cout<<"-----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"-----"<<endl;}
                if (c==2) {
                    cout<<"-----"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-----"<<endl;}
                if (c==3) {
                    cout<<"o----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"----o"<<endl;}
                if (c==4) {
                    cout<<"--o--"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"--o--"<<endl;}
                if (c==5) {
                    cout<<"--o--"<<endl;
                    cout<<"o-o-o"<<endl;
                    cout<<"--o--"<<endl;}
                if (c==6) {
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;}
                res1=b+c;
                cout<<"Ваш результат:  "<<res1<<endl;
                b=rand()%6+1;
                c=rand()%6+1;
                if (b==1) {
                    cout<<"-----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"-----"<<endl;}
                if (b==2) {
                    cout<<"-----"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-----"<<endl;}
                if (b==3) {
                    cout<<"o----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"----o"<<endl;}
                if (b==4) {
                    cout<<"--o--"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"--o--"<<endl;}
                if (b==5) {
                    cout<<"--o--"<<endl;
                    cout<<"o-o-o"<<endl;
                    cout<<"--o--"<<endl;}
                if (b==6) {
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;}
                    cout<<"  "<<endl;
                    cout<<"  "<<endl;
                if (c==1) {
                    cout<<"-----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"-----"<<endl;}
                if (c==2) {
                    cout<<"-----"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-----"<<endl;}
                if (c==3) {
                    cout<<"o----"<<endl;
                    cout<<"--o--"<<endl;
                    cout<<"----o"<<endl;}
                if (c==4) {
                    cout<<"--o--"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"--o--"<<endl;}
                if (c==5) {
                    cout<<"--o--"<<endl;
                    cout<<"o-o-o"<<endl;
                    cout<<"--o--"<<endl;}
                if (c==6) {
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;
                    cout<<"-o-o-"<<endl;}
                res2=b+c;
                cout<<"Мой рузельтат:"<<res2<<endl;
                if (res1>res2){cout<<"вы выйграли"<<endl;}
                if (res1<res2){cout<<"вы проиграли"<<endl;}
                if (res1==res2){cout<<"ничья"<<endl;}
        }}
    return 0;
}
