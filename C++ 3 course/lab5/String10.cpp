#include "String10.h"
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

String10::String10()
{
	m_size = 0;
	m_pData = 0;
}

String10::String10(const char * pStr)
{
	try {
		m_size = strlen(pStr);
		m_pData = new char[m_size + 1];
		copy(pStr, pStr + m_size, m_pData);
		m_pData[m_size] = 0;
	}
	catch (exception e) {
		printf("OOps, exception");
	}
}

String10::String10(const String10 & str)
{
	m_size = str.m_size;
	m_pData = new char[m_size + 1];
	std::copy(str.m_pData, str.m_pData + m_size, m_pData);
	m_pData[m_size] = 0;
}

String10::~String10()
{
	if (m_pData != 0) {
		m_pData = 0;
		m_size = 0;
	}
}

bool String10::isPossibleToInt() {
	for (int i = 0; i < m_size; ++i) {
		if (*(m_pData + i) <= '9' && *(m_pData + i) >= '0')
			continue;
		return false;
	}
	return true;
}

bool String10::isZero() {
	if (!(this->isPossibleToInt()))
		return false;
	int ans = 0;
	for (int i = 0; i < m_size;++i) {
		ans += *(m_pData + i) - '0';
	}
	return ans == 0;
}

long long int String10::toInt64() {
	if (!(this->isPossibleToInt()))
		return false;
	int ans = 0;
	for (int i = 0; i < m_size; ++i) {
		ans *= 10;
		ans += *(m_pData + i) - '0';
	}
	return ans;
}

void String10::deleteZeros() {
	int qunatity = 0;
	while (qunatity < m_size && *(m_pData + qunatity) == '0') {
		qunatity++;
	}
	for (int i = 0; i < m_size - qunatity; ++i) {
		*(m_pData + i) = *(m_pData + qunatity+i);
	}
	m_size -= qunatity;
	m_pData[m_size] = 0;
}

int String10::length() {
	this->deleteZeros();
	return m_size;
}