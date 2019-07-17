#include <iostream>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "Account.h"

using namespace std;
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		system("cls");
		manager.ShowMenu();
		cout << "¼±ÅÃ: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}

	return 0;
}