//Вычеслить значение е встпени x
#include <iostream>
#include <clocale>
using std::cin;
using std::cout;
using std::endl;

int main()
{  setlocale(LC_ALL,"Russian");
    double E,res,b;
    int i=1,x=0;
    E=1;
    b=0,001;
    res=1;
    cout << "Введите x" << endl;
    cin>>x;
        while (E>b) {
        E=E*x/i;
        res=res+E;
        i++;}
     cout<<"res="<<res<<endl;
    return 0;
}

