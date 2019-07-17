#include "AccountArray.h"
#include "Account.h"


AccountArray::AccountArray(int len)
{
	accArr = new ACCOUNT_PTR[len];

	arrlen = len;
}

ACCOUNT_PTR& AccountArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen) 
	{
		cout << "�迭�� ������ ������ϴ�" << endl;

		exit(1);
	}

	return accArr[idx];
}

ACCOUNT_PTR AccountArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen) 
	{
		cout << "�迭�� ������ ������ϴ�." << endl;
		exit(1);
	}
}

int AccountArray::GetArrLen() const
{
	return arrlen;
}

AccountArray::~AccountArray()
{
	delete[]accArr;
}