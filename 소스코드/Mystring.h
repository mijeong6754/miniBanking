#ifndef _MYSTRING_H__
#define _MYSTRING_H__

#include <iostream>
#include <cstring>

#define NumOfUser	100

#define STR_MAX 1000

using namespace std;

class Mystring
{
private:
	char *mystring_con;	
	int mystring_len;		
public:
	
	// �� ���� ������
	Mystring();
	// ���ڿ� ������
	Mystring(const char *str);
	// ���ڿ� ������
	Mystring(Mystring &ref);
	// ���ڿ� ���� ��ȯ
	int GetLen(void) const;
	// ���ڿ� ��ȯ
	char *GetStr(void) const;
	// �Ҹ���
	~Mystring();

	// "=" ������ �����ε�
	Mystring &operator =(const Mystring &ref);

	// "==" ������ �����ε�
	// strcmp() ���
	int operator ==(Mystring &ref) const;

	// "<<" ������ �����ε�
	friend ostream &operator <<(ostream &os, const Mystring &str);
	// ">>" ������ �����ε�
	friend istream &operator >>(istream &is, Mystring &str);


};


#endif // !_MYSTRING_H__

