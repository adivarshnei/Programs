#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

enum withdrawlPossibility {
	possible = 1,
	impossible = 2
}; //enum withdrawlPossibility

/*********************************************************************/

typedef struct history {
	string overall[100];
	string temp[20];
}; //typedef struct history 

/*********************************************************************/

class account {
	protected:
		unsigned long int accountNumber;
		unsigned long int balance;
		string name[20];
}; //class account

/*********************************************************************/

class transaction: private account {
	private: 
		unsigned int type;
		withdrawlPossibility possibility;
		unsigned long int amount;
		history transactionHistory;

	public:
		~transaction();
		void getData();
		void showData();
		withdrawlPossibility amountCheck();
		void getTransactionData();
		void conductTransaction();
}; //class transaction: private account

/*********************************************************************/

inline transaction::~transaction() {
	cout << "Destructing Object" << endl;
} //inline transaction::~transaction()

/*********************************************************************/

inline void transaction::getData() {
	cout << "Enter account number: ";
	cin >> accountNumber;
	cout << "Enter name of the account holder: ";
	gets(name);
	cout << "Enter account balance: ";
	cin >> balance;

	strcpy(transactionHistory.overall, '\0');
} //inline void transaction::getData()

/*********************************************************************/

inline void transaction::showData() {
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Holder: ";
	puts(name);
	cout << "Balance: " << balance << endl;
	cout << "Transaction History: " << endl;
	puts(transactionHistory.overall);
} //inline void transaction::showData()

/*********************************************************************/

inline void transaction::getTransactionData() {
	cout << "Enter transaction type (1=Deposit, 2=Withdrawl): ";
	cin >> type;
	cout << "Amount of transaction: ";
	cin >> amount;
} //inline void transaction::getTransactionData() 

/*********************************************************************/

inline withdrawlPossibility transaction::amountCheck() {
	if (amount > balance) {
		return impossible;
	} else if (amount <= balance) {
		return possible;
	} //End of extended if clause
} //inline withdrawlPossibility transaction::amountCheck()

/*********************************************************************/

inline void transaction::conductTransaction() {
	if (type == 2) {
		possibility = amountCheck();

		if (possibility == possible) {
			balance -= amount;

			gcvt(amount, 10, transactionHistory.temp);

			strcat(transactionHistory.overall, "-");
			strcat(transactionHistory.overall, transactionHistory.temp);
			strcat(transactionHistory.overall, "\n");
		} else if (possibility == impossible) {
			cout << "Transaction Impossible" << endl;
		} //End of extended if clause

	} else if (type == 1) {
		balance += amount;

		gcvt(amount, 10, transactionHistory.temp);

		strcat(transactionHistory.overall, "+");
		strcat(transactionHistory.overall, transactionHistory.temp);
		strcat(transactionHistory.overall, "\n");
	} else {
		cout << "Wrong Choice" << endl;
	} //End of extended if clause
} //inline void transaction::conductTransaction()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;
	unsigned int choice;

	while (rep == 1) {
		system("cls");

		transaction t1;
		t1.getData();

		do {
			cout << "1. Perform transaction" << endl;
			cout << "2. Display account statement" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					t1.getTransactionData();
					t1.conductTransaction();
					break;

				case 2:
					t1.showData();
					break;

				case 3:
					goto exitLoop;
					break;
			} //switch (choice)

		} while (1);

		exitLoop:

		cout << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		} //if (count >= 50)

	} //while (rep == 1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
} //int main(void)