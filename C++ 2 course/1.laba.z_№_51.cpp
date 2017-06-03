#include <iostream>
#include <clocale>
#include <cstdlib>
#include <time.h>

using namespace std;
/*51. (8-9) Из двух заданных упорядоченных числовых массивов размерности n и m получить новый упорядоченный массив
размерности n+m, не используя алгоритма сортировки.*/

void enteraray(int* px, int sizex)//инитиализация масива
{
    for (int i = 0; i < sizex; i++)
    {
        *(px + i) = rand() % 300;
    }

    for (int i = 0; i < sizex; i++)
    {
        int mx = *(px+i);
        int k = i;
        for (int j = i; j < sizex; j++)
         {
            if (mx>*(px+j)){mx = *(px+j); k = j;}
         }
        int tmp = *(px + i);
        *(px + i) = *(px + k);
        *(px + k) = tmp;
    }

    for (int i = 0; i < sizex; i++)
    {
        cout << i << " :=" << *(px + i) << endl;
    }

}

void enterarayv (int* px, int sizex)//инитиализация массива вручную
{
    for (int i = 0; i < sizex; i++)
    {
        cin >> *(px + i);
    }

    for (int i = 0; i < sizex; i++)
    {
        int mx = *(px+i);
        int k = i;
        for (int j = i; j < sizex; j++)
         {
            if (mx>*(px+j)){mx = *(px+j); k = j;}
         }
        int tmp = *(px + i);
        *(px + i) = *(px + k);
        *(px + k) = tmp;
    }
    cout<<"Итоговый массив:"<<endl;
    for (int i = 0; i < sizex; i++)
    {
        cout << i << " :=" << *(px + i) << endl;
    }

}

void makenewaray (int* pm, int m, int* pn, int n, int* pnm, int nm) // создание нового массива на основе двух предыдущих
{
    int q = 0;
    int j = 0;
    for (int i = 0; i < nm; i++)
    {
        if ((q < m) && (j < n))  *(pnm+i) = (*(pm+q)<*(pn+j)) ? *(pm+q++) : *(pn+j++);
        else if (q == m) { *(pnm+i)=*(pn+j); j++;}
            else { *(pnm+i)=*(pm+q); q++;}
        cout <<i<<" :="<< *(pnm+i)<<endl;
    }
}

void menu(int* pm, int m, int* pn, int n)
{
    cout << "Как вы хотите проинитиализировать массив?(введите номер варинта который вам подходит)"<<endl;
    cout << "1.Ввод массива вручную"<<endl;
    cout << "2.Автоматическая генерация массива"<<endl;

    int a;
    cin >> a;

    if (a == 2){
        srand(time(NULL));
        cout << "Первый изначальный массив :" << endl;
        enteraray (pn, n);
        cout << "Второй изначальный массив :" << endl;
        enteraray (pm, m);
    }

    else {
        cout << "Вводите первый массив(програма сама за вас его упорядочит)"<<endl;
        enterarayv (pn, n);
        cout << "Вводите второй массив(програма сама за вас его упорядочит)"<<endl;
        enterarayv (pm, m);
    }
}


int main()
{

    int n,m;

    cout << "Введите два числа, размеры первого и второго масивов:"<<endl;
    cin >> n >> m;

    int *aray_n = new int[n], *pn = aray_n;
    int *aray_m = new int[m], *pm = aray_m;
    menu(pm, m, pn, n);

    int *aray_nm = new int[n+m], *pnm = aray_nm;
    cout << "Новый массив:" << endl;
    makenewaray (pm,m,pn,n,pnm,n+m);

    delete pn,pm,aray_m,aray_n,aray_nm,pnm;

    return 0;
}
