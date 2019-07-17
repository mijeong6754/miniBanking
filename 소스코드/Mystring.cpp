#include "Mystring.h"

Mystring::Mystring()
{
	mystring_con = NULL;
	mystring_len = 0;
}

Mystring::Mystring(const char *str)
{
	mystring_len = strlen(str) + 1;
	mystring_con = new char[mystring_len];
	strcpy(mystring_con, str);
}

Mystring::Mystring(Mystring &ref)
{
	this->mystring_len = strlen(ref.mystring_con) + 1;
	this->mystring_con = new char[mystring_len];
	strcpy(this->mystring_con, ref.mystring_con);
}

int Mystring::GetLen(void) const
{
	return mystring_len;
}

char *Mystring::GetStr(void) const
{
	return mystring_con;
}

Mystring::~Mystring() 
{
	delete[]mystring_con;
}

Mystring& Mystring:: operator=(const Mystring &ref) 
{

	if (mystring_con != NULL)
		delete[]mystring_con;

	mystring_len = ref.mystring_len;
	mystring_con = new char[mystring_len];
	strcpy(mystring_con, ref.mystring_con);

	return *this;

}

int Mystring::operator==(Mystring &ref) const {
	if (strcmp(this->mystring_con, ref.mystring_con))
		return 1;
	else
		return -1;
}

ostream& operator<<(ostream& out, const Mystring &str) {

	out << str.mystring_con;

	return out;
}

istream& operator>>(istream& in, Mystring &str) {
	char *tmp = new char[STR_MAX];
	in >> tmp;

	delete[]str.mystring_con;

	str.mystring_len = strlen(tmp) + 1;
	str.mystring_con = new char[str.mystring_len];
	strcpy(str.mystring_con, tmp);

	delete[]tmp;

	return in;
}


