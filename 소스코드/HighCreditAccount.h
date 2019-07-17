#ifndef _HIGHCREDITACCOUNT_H__
#define _HIGHCREDITACCOUNT_H__
#include "NormalAccount.h"
#include "Account.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;  // 특별이자
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special)
	{}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);  // 원금과 기본이자추가
		Account::Deposit((int)money * specialRate / 100.0);  // 특별이자 추가 (소수점 아래 무시)
	}
};

#endif // !_HIGHCREDITACCOUNT_H__

