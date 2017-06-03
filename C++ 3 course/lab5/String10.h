#pragma once
#pragma warning(disable: 4996)
#include "String.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <clocale>
class String10 : public String
{
public:
	String10();
	~String10();
	String10(const char * pStr);
	String10(const String10 & pStr);
	bool isPossibleToInt();
	bool isZero();
	long long int toInt64();
	int length();
	void deleteZeros();
	friend long long int operator +(const String10 & str1, const String10 & str2) {
		String10 str3 = str1;
		String10 str4 = str2;
		return str3.toInt64()+str4.toInt64();
	}
	friend bool operator <(const String10 & str1, const String10 & str2) {
		String10 str3 = str1;
		String10 str4 = str2;
		if (str3.toInt64() - str4.toInt64() > 0)
			return true;
		return false;
	}
	friend bool operator >(const String10 & str1, const String10 & str2) {
		String10 str3 = str1;
		String10 str4 = str2;
		if (str3.toInt64() - str4.toInt64() < 0)
			return true;
		return false;
	}
	const String10& operator=(String10 && str)
	{
		if (this != &str)
		{
			m_pData = str.m_pData;
			m_size = str.m_size;

			str.m_pData = nullptr;
			str.m_size = 0;
		}

		return *this;
	}
	char *m_pData;
	int m_size;
};

