// laba3_v6.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include <iostream>
#include "node.h"

using namespace std;
void menu();
void PrintMenu();
int chooseMenu(node &a);
void insertionsort(node &a);


int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
    return 0;
}

void menu() {
	node nod(10);
	for (int i = 9; i >= 0; i--) {
		nod.addToNode(i | (i - 1));
	}
	int b = 0;
	while (b != 5) {
		PrintMenu();
		b = chooseMenu(nod);
	}
}

void PrintMenu() {
	cout << "¬ведите 1,чтобы отсортировать лист методом выбора" << endl;
	cout << "¬ведите 2,чтобы отсортировать лист методом пузырька" << endl;
	cout << "¬ведите 3,чтобы отсортировать лист методом вставки" << endl;
	cout << "¬ведите 4, чтобы вывести св€занный список" << endl;
	cout << "¬ведите 5, чтобы рандомить список" << endl;
	cout << "¬ведите 6, чтобы выйти из программы" << endl;

}

int chooseMenu(node &a) {
	int status = 0;
	cin >> status;
	switch (status) {
		case 1: {a.sortNodeTokenSort();break;}
		case 2: {a.sortNodeBublSort();break;}
		case 3: {insertionsort(a); break;}
		case 4: {a.showList(); break;}
		case 5: {a.deletkelem(6);break;}
		case 6: {return 5; break;}

		default: cout << "¬ведите число заново" << endl;break;
	}
	return 0;
}

void insertionsort(node &a) {
	a.sortNodeBublSort();
}



