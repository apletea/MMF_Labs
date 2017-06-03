#pragma once
#pragma warning(disable: 4996)

class String
{
public:
	String();
	String(const char * pStr);
	String(const String & pStr);
	virtual int length();
	virtual void cleanStr();
	~String();
	char *m_pData;
	int m_size;
};


