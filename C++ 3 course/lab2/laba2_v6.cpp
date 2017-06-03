#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "STACK.h"
#include <fstream>
using namespace std;

void pushToStack(STACK & a);
void popFromStack(STACK & a);
void showStack(STACK & a);
void deleteOddsfromStack(STACK & a);
void PrintMenu();
void menu();
int chooseMenu(STACK & a);

ifstream fin("integers.txt");
int fromFile = 3;

int main()
{
	setlocale(LC_ALL, "Russian");
	menu();
    return 0;
}

void menu() {
	STACK a(10);
	int b = 0;
	while (b!=5) {
		PrintMenu();
		b = chooseMenu(a);
	}
}

void PrintMenu() {
	cout << "Ââåäèòå 1, ÷òîáû  âûïîëíèòü ôóíêöèþ push" << endl;
	cout << "Ââåäèòå 2, ÷òîáû  âûïîëíèòü ôóíêöèþ pop" << endl;
	cout << "Ââåäèòå 3, ÷òîáû  ïðîñìîòðåòü âåñü ñòåê"<< endl;
	cout << "Ââåäèòå 4, ÷òîáû  óäàëèòü íå÷¸òíûå ýëåìåíòû ñòýêà" << endl;
	cout << "Ââåäèòå 5, ÷òîáû âûéòè èç ïðîãðàììû" << endl;
}

int chooseMenu(STACK & a) {
	int status = 0;
	cin >> status;
	switch (status) {
	case 1: {pushToStack(a);  break;}
	case 2: {popFromStack(a);  break;}
	case 3: {showStack(a);  break;}
	case 4: {deleteOddsfromStack(a);  break;}
	case 5: {return 5;  break;}
	default: cout << "Ââåäèòå ÷èñëî çàíîâî" << endl;break;
	}
	return 0;
}

void pushToStack(STACK & a) {
		cout << "Ââåäèòå ÷èñëî êîòîðîå õîòèòå äîáàâèòü â ñòýê" << endl;
		int num;
		cin >> num;
		a.push(num);

}

void popFromStack(STACK & a) {
	cout << a.pop() << endl;
}

void showStack(STACK & a) {
	a.show();
}

void deleteOddsfromStack(STACK & a) {
	a.delOdd();
}

