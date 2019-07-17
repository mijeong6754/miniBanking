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
	
	// 한 문자 생성자
	Mystring();
	// 문자열 생성자
	Mystring(const char *str);
	// 문자열 복사자
	Mystring(Mystring &ref);
	// 문자열 길이 반환
	int GetLen(void) const;
	// 문자열 반환
	char *GetStr(void) const;
	// 소멸자
	~Mystring();

	// "=" 연산자 오버로딩
	Mystring &operator =(const Mystring &ref);

	// "==" 연산자 오버로딩
	// strcmp() 기능
	int operator ==(Mystring &ref) const;

	// "<<" 연산자 오버로딩
	friend ostream &operator <<(ostream &os, const Mystring &str);
	// ">>" 연산자 오버로딩
	friend istream &operator >>(istream &is, Mystring &str);


};


#endif // !_MYSTRING_H__

