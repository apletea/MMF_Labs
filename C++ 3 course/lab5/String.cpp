#include "stdafx.h"
#include "String.h"
#include <iostream>
#include <cstring>

using namespace std;

String::String()
{
	m_size = 0;
	m_pData = 0;
}

String::String(const char * pStr)
{
	m_size = strlen(pStr);
	m_pData = new char[m_size + 1];
    copy(pStr, pStr + m_size, m_pData);
	m_pData[m_size] = 0;
}

String::String(const String & str)
{
	m_size = str.m_size;
	m_pData = new char[m_size + 1];
	std::copy(str.m_pData, str.m_pData + m_size, m_pData);
	m_pData[m_size] = 0;
}

String::~String()
{
	if (m_pData != 0) {
		delete[] m_pData;
		m_size = 0;
	}
}

int String::length()
{
	return m_size;
}

void String::cleanStr()
{
	if (m_pData != 0) {
		delete[] m_pData;
		m_size = 0;
	}
}