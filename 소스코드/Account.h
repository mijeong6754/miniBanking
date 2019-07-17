#ifndef _ACCOUT_H__
#define _ACCOUT_H__

#include "Mystring.h"

class Account
{
private:
	int accID;      // ���¹�ȣ
	int balance;    // ��    ��
	char * cusName; // ���̸�

public:
	// ������
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

