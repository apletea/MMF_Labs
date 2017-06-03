
#include "stdafx.h"
#include "String.h"
#include "String10.h"
#include <iostream>
#include <cstring>
String10  a("001234");
String10 d("004321");
String c("004321");
using namespace std;

int main()
{
	scanf("%s", &a);
	scanf("%s", &d);
	scanf("%s", &c);
	printf("%d \n", a.isPossibleToInt());
	printf("%d \n", a.isZero());
	printf("%lld \n", a.toInt64());
	a.deleteZeros();
	printf("%s \n", a.m_pData);
	printf("%lld \n", a+d);
	printf("%d \n", c.length());
	printf("%d \n", d.length());
	printf("%d \n", a < d);


	int b;
	scanf("%d", &b);
}

