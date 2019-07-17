#ifndef _NORMALACCOUNT_H__
#define _NORMALACCOUNT_H__
#include "Account.h"

class NormalAccount : public Account
{
private:
	int interRate;  // 이자율 %단위
public:
	NormalAccount(int ID, int money, char* name, int rate) : Account(ID, money, name), interRate(rate)
	{}
	virtual void Deposit(int money)
	{
		Account::Deposit(money);  // 원금추가
		Account::Deposit((int)(money * interRate / 100.0));  // 기본이자추가 (소수점 아래는 무시)
	}
};

#endif // !_NORMALACCOUNT_H__

