#pragma once
#include <fstream>
using namespace std;
class STACK
{
public:
	int *s;
	int N;
	int maxN;
	STACK(int maxN);
	int empty() const;
	int pop();
	void push(int item);
	void show();
	void delElem(int n);
	void delOdd();
	friend ostream& operator << (ostream& out,  STACK& T);
	friend istream& operator >> (istream& in,   STACK& T);

};

