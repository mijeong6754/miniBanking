#ifndef  _ACOUNTARRAY_H__
#define _ACOUNTARRAY_H__

#include "Account.h"

#define NumOfUser 100

typedef Account *ACCOUNT_PTR;

class AccountArray
{
private:
	ACCOUNT_PTR *accArr;
	int arrlen;

	AccountArray(const AccountArray &arr) {}
	AccountArray& operator=(const AccountArray &arr) {}

public:
	AccountArray(int len = NumOfUser);

	ACCOUNT_PTR& operator[](int idx);

	ACCOUNT_PTR operator[](int idx) const;

	int GetArrLen() const;

	~AccountArray();


};



#endif // ! _ACOUNTARRAY_H__

