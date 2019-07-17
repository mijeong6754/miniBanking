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
	void MakeNormalAccount(void);  // 보통예금 계좌 만들기
	void MakeCreditAccount(void);  // 신용예금 계좌 만들기
};

#endif // !_ACCOUNTHANDLER_H__
