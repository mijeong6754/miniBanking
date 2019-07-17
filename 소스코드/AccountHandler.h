#ifndef _ACCOUNTHANDLER_H__
#define _ACCOUNTHANDLER_H__
#include "Account.h"

class AccountHandler
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount(void);  // ���뿹�� ���� �����
	void MakeCreditAccount(void);  // �ſ뿹�� ���� �����
};

#endif // !_ACCOUNTHANDLER_H__
