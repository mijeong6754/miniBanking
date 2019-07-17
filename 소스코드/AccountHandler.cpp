#include <iostream>
#include "AccountHandler.h"
#include "HighCreditAccount.h"
#include "NormalAccount.h"
#include "Account.h"

using namespace std;

// �������� �̸� ����
const int NAME_LEN = 20;

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu() const
{
	cout << "------Menu-------" << endl;
	cout << "1. ���� ����" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount()
{
	int sel;

	cout << "[�������� ����]" << endl;
	cout << "1. ���뿹�ݰ���   ";
	cout << "2. �ſ�ŷڰ���   " << endl;
	cout << "����: "; cin >> sel;

	switch (sel)
	{
	case NORMAL:
		MakeNormalAccount();
		break;
	case CREDIT:
		MakeCreditAccount();
		break;
	}
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate; // ������

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);
}

void AccountHandler::MakeCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int balance;
	int interRate; // ������
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << "������: "; cin >> interRate;
	cout << "�ſ���(A�� 1, B�� 2, C�� 3�� �Է��Ͻÿ�): "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[�Ա�]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			getchar();
			getchar();
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[���]" << endl;
	cout << "���� ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				getchar();
				getchar();
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
		getchar();
		getchar();
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}
