// laba3_v6.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include "ListNode.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ListNode<int> * nod = new ListNode<int>(10);
	for (int i = 9; i >= 0; i--) {
		nod->addToNode(i | (i - 1));
	}
	int b = 0;
	while (b != 5) {
		cout << "¬ведите 1,чтобы отсортировать лист методом выбора" << endl;
		cout << "¬ведите 2,чтобы отсортировать лист методом пузырька" << endl;
		cout << "¬ведите 3,чтобы отсортировать лист методом вставки" << endl;
		cout << "¬ведите 4, чтобы вывести св€занный список" << endl;
		cout << "¬ведите 5, чтобы рандомить список" << endl;
		cout << "¬ведите 6, чтобы выйти из программы" << endl;
		int status = 0;
		cin >> status;
		switch (status) {
		case 1: {nod->sortNodeTokenSort();break;}
		case 2: {nod->sortNodeBublSort();break;}
		case 3: {nod->sortNodeBublSort(); break;}
		case 4: {nod->showList(); break;}
		case 5: {nod->randList();break;}
		case 6: {b = 5; break;}
		default: cout << "¬ведите число заново" << endl;break;
		}
		
	}
	return 0;
}



