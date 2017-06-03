#include <iostream>
#include <clocale>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <bits/stdc++.h>
/*73. Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно побочной диагонали,
 умножить на вектор В(N). В памяти матрицу не получать. */
using namespace std;

void showtask(){
    cout << "73. Симметричную матрицу А(N,N), заданную верхним треугольником в виде одномерного массива относительно побочной диагонали, умножить на вектор В(N). В памяти матрицу не получать."<<endl;
}

int **memoryforarray(int N){
    int **array = 0;
    try
    {
         array = new int*[N];
        for (int i = 0; i < N; i++){
            *(array+i) = new int[N];
            }
    }
    catch(bad_alloc){cout << "404 error";array = 0;}
    return array;
}

int *fin (int *array, int N,int vorm)
{
    if(vorm)
    {
        ifstream fin ("inputvektor.txt");
        array = new int[N];
        for (int i = 0 ; i < N; i++){
        fin >> *(array+i);}
     }
     else
    {
        ifstream fin ("inputarray.txt");
        array = new int[N];
        for (int i = 0 ; i < N; i++){
        fin >> *(array+i);}
     }

     return array;
}
int *initaarays (int *array, int N,int vorm)
{
    if(vorm)
    {
        cout << "введите координаты вектора " << N<<"чисел"<<endl;
        array = new int[N];
        for (int i = 0 ; i < N; i++){
        cin >> *(array+i);}
     }
     else
    {
        cout << "введите одномерныый массив" << N << "чисел"<< endl;
        array = new int[N];
        for (int i = 0 ; i < N; i++){
        cin >> *(array+i);}
     }
     cout << endl;
     return array;
}


void major_matrix (int **a,int *ia,int N, int k){
    int  q = 0;
    for (int i = 0; i < N-1; i++){
        for (int j = 0; j < N-i-1; j++){
            *(*(a+i)+j) = *(ia+q);
            *(*(a+N-i-1)+N-j-1) = *(ia+q);
            q++;
        }
    }
    for (int i = 0; i < N ; i++){
        *(*(a+i)+N-i-1) = rand()%11;
    }
}

void  watcarray (int **a, int *v,int N){
    cout << "Вот так выглядит матрица" << endl;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << *(*(a+i)+j) << "  ";
        }
        cout << endl;
    }
    cout << "Вот так выглядит вектор"<< endl;
    for (int i = 0; i < N; i++){
        cout << *(v+i) << "  ";
    }
    cout << endl;
}

void **maketask(int **a,int *v,int N){
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N; j++){
           *(*(a+i)+j)*= *(v+j);
            cout << *(*(a+i)+j) << "  ";}
        cout << endl;
    }

}






int main()
{
    setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    int **array;
    int *initaaray;
    int *vektor;
    int N;
    cout << "Введите размер матрици" << endl;
    cin >> N;
    int k = (N*N - N) / 2;
    array = memoryforarray(N);
    int status = 0;
    while (1)
    {
        cout << "Введите 1, чтобы просмотреть текст задания." << endl;
		cout << "Введите 2, чтобы ввести данные из файла." << endl;
		cout << "Введите 3, чтобы просмотреть как выглядит матрица и вектор." << endl;
		cout << "Введите 4, чтобы самостоятельно ввести данные." << endl;
		cout << "Введите 5, чтобы выполнить задание." << endl;
		cout << "Введите 6, чтобы выйти из программы." << endl;
        cin >> status;
        switch (status)
        {
            case 1:
            {
                showtask();
                break;
            }
            case 2:
            {
                initaaray = fin(initaaray, k,0);
                vektor = fin(initaaray, N,1);
                major_matrix(array,initaaray,N,k);
                break;
            }
           case 3:
            {
                watcarray(array, vektor, N);
                break;
            }
            case 4:
            {
                initaaray = initaarays(initaaray, k,0);
                vektor = initaarays(initaaray, N,1);
                major_matrix(array,initaaray,N,k);
                break;
            }
            case 5:
            {
               maketask(array,vektor,N);
               break;
            }
            case 6:
            {
                return 1;

            }
            default: cout << "Введите число заново" << endl;
            break;
        }
    }








}
