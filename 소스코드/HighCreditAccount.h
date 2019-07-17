#ifndef _HIGHCREDITACCOUNT_H__
#define _HIGHCREDITACCOUNT_H__
#include "NormalAccount.h"
#include "Account.h"

class HighCreditAccount : public NormalAccount
{
private:
	int specialRate;  // Ư������
public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		: NormalAccount(ID, money, name, rate), specialRate(special)
	{}
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);  // ���ݰ� �⺻�����߰�
		Account::Deposit((int)money * specialRate / 100.0);  // Ư������ �߰� (�Ҽ��� �Ʒ� ����)
	}
};

#endif // !_HIGHCREDITACCOUNT_H__

