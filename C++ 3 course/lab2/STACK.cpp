#include "stdafx.h"
#include <iostream>
#include <clocale>
#include "STACK.h"
#include <fstream>
using namespace std;


STACK::STACK(int maxN){
	try{
		s = new int[maxN];
	}
	catch(exception e){
		cout << "Íå äîñòàòî÷íî ïàìÿòè" << endl;
	}
	N = 0;
}


int STACK::empty() const {
	return N == 0;
}



void STACK::push(int item) {
	if (maxN < N + 1) {
		s[N++] = item;
	}
	else {
		STACK b(2 * maxN);
		for (int i = 0;i < N; i++) 
			b.push(s[i]);
		b.push(item);
		s = b.s;
	}
}


int STACK::pop() {
	if (N == 0) {
		cout << "ââåäèòå ýëåìåíòîâ" << endl;
		return 0;
	}
	else {
		return s[--N];
	}
}

void STACK::delOdd() {
	int cur = 0;
	int tmp = N % 2;
	for (int i = 0; i < N / 2 ;i++, cur++) {
		s[i] = s[i + cur+tmp];
	}
	N = N / 2 ;
}

void STACK::show() {
	for (int i = N - 1; i >= 0; i--) {
		cout << s[i] << endl;
	}
}

ostream& operator << (ostream& out,  STACK& T) {
	cout << T.pop();
	return out;
}


istream& operator >> (istream& in,  STACK& T){
	int a;
	cin >> a;
	T.push(a);
	return in;
}




