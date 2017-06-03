#include <iostream>
#include <clocale>
#include <cmath>
#include <stdlib.h>

using namespace std;
//Задача № 48 сортировка перемешиванием
//48. *(9) Элементы массива А(N) упорядочить в порядке возрастания, используя сортировку Шелла (см. ниже), и вставить k
 //заданных числа, не нарушая упорядоченности массива.
void showtask()
{
    cout << "Элементы массива А(N) упорядочить в порядке возрастания, используя сортировку Перемешиванием (см. ниже), и вставить k заданных числа, не нарушая упорядоченности массива." << endl;
}



void SWAP(int *mas, int i)
{
    int temp;
    temp=*(mas+i);
    *(mas+i)=*(mas+i-1);
    *(mas+i-1)=temp;
}


void m_sheker(int *mas, int n)
{
	int last = n-1, left = 1, right = n-1, j;

	do
	{
		for(j = right; j >= left; j--)
		{
			if(*(mas+j-1) > *(mas+j))
			{
				SWAP(mas, j);
				last = j;
			}
		}

		left = last + 1;

		for(j = left; j <= right; j++)
		{
			if(*(mas+j-1) > *(mas+j))
			{
				SWAP(mas, j);
				last = j;
			}
		}

		right = last-1;

	} while(left < right);
}
void initializer(int *begin, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> *(begin+i);
    }
    m_sheker(begin, size);
}

void initialize(int *begin, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        *(begin+i) = rand()%300;
    }
    m_sheker(begin, size);
}

void print(int *begin, int size)
{
    if (size == 0) {cout << "массив ещё не создан" << endl;}
    else
    {
        for (int i = 0; i < size ; i++)
        {
            cout << *(begin+i) << "=:" << i <<"   ";
        }
        cout << " " << endl;
    }
}

void task(int *begin, int &size, int k)
{
    int a = 0;
    if (size == 0) {cout << "массив ещё не создан" << endl;}
    else
    {
        while (k)
        {
            cout << "введите элемент" << endl;
            cin >> a;
            for (int i = 0; i < size; i++)
            {
                if (*(begin+i) > a)
                    {
                        for (int j = size-1; j >= i; j--)
                        {
                            *(begin+j+1)=*(begin+j);
                        }
                        size++;
                        *(begin + i) = a;break;
                    }
                if (i == size-1){size++;*(begin+size)=a;}
            }
            k--;
        }
    }
}


int main()
{
    int *p;
    int j = 0;
    setlocale(LC_ALL,"Russia");
    int status = 0;
    int k = 0;
    while (1)
    {
        cout << "Введите 1, если хотите просмотреть текст задания." << endl;
		cout << "Введите 2, если хотите проинициализировать массив вручную." << endl;
		cout << "Введите 3, если хотите проинициализировать массив случайными числами." << endl;
		cout << "Введите 4, если хотите распечатать массив." << endl;
		cout << "Введите 5, если хотите выполнить задание" << endl;
		cout << "Введите 6, если хотите выйти из программы." << endl;
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
                cout << "Введите окл-во элементов"<<endl;
                cin >> j;
                 cout << "Введите " << j << " элементов" << endl;
                int *array_m = new int[j];
                p = array_m;
                initializer(p,j);
                break;
            }
           case 3:
            {
                cout << "Введите окл-во элементов" << endl;
                cin >> j;
                int *array_m = new int[j];
                p = array_m;
                initialize(p,j);
                break;
            }
            case 4:
            {
                print(p,j);
                break;
            }
            case 5:
            {
                cout << "Введите k - сколько элементов которые хотите добавить в масив" << endl;
                cin >> k;
                task(p,j,k);
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
