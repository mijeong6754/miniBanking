#include <iostream>
#include "Account.h"

using namespace std;

const int NAME_LEN = 20;

Account::Account(int ID, int money, char* name) : accID(ID), balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[NAME_LEN];
	strcpy(cusName, name);
}
Account::Account(const Account& ref) : accID(ref.accID), balance(ref.balance)
{
	int len = strlen(ref.cusName) + 1;
	cusName = new char[NAME_LEN];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const
{
	return accID;
}

int Account::GetBalance(void) const 
{
	return balance;
}


void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂ ID: " << accID << endl;
	cout << "ÀÌ¸§: " << cusName << endl;
	cout << "ÀÜ¾×: " << balance << endl;
}

Account::~Account()
{
	delete[] cusName;
}