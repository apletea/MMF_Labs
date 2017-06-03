#include <iostream>
#include <clocale>

using std::cin;
using std::endl;
using std::cout;
// Линейный конгруэнтный генератор псевдослучайных чисел
int main()
{   setlocale(LC_ALL,"Russian");
    int mas[15];// зачем массив? Для чего?????
    int a=4096,c=150889,m=714025;
    mas[0]=1;
    cout<<mas[0]<<"=:1"<<endl;
    for (int i=1;i<15;i++){
        mas[i]=(a*mas[i-1]+c)%m;
        cout<<mas[i]<<"=:"<<i+1<<endl;
    }
    return 0;
}
