#ifndef _ACCOUT_H__
#define _ACCOUT_H__

#include "Mystring.h"

class Account
{
private:
	int accID;      // 계좌번호
	int balance;    // 잔    액
	char * cusName; // 고객이름

public:
	// 생성자
	Account(int ID, int money, char * name);
	Account(const Account & ref);

	int GetAccID() const;

	int GetBalance(void) const;



	void Deposit(int money);

	int Withdraw(int money);

	void ShowAccInfo() const;

	~Account();

};

#endif // !_ACCOUT_H__

