#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

typedef char string;

class account {
	private:
		string name[20];
		double balanceAmount;

	public:
		double accountNumber;
		void getData();
		void showData();
		int transaction(char, double);
		double withdrawCount(double);
		double depositCount(double);
		int withdrawSum;
		int depositSum;
};

inline void account::getData() {
	cout << "Enter the account number: ";
	cin >> accountNumber;
	cout << "Enter the account holder's name: ";
	gets(name);
	cout << "Enter the amount in the account: ";
	cin >> balanceAmount;

	int withdrawSum = 0;
	int depositSum = 0;
}

inline void account::showData() {
	cout << "Account number: " << accountNumber << endl;
	cout << "Account holder's name: " << name << endl;
	cout << "Account balance: " << balanceAmount << endl;
	cout << "Amount withdrawn: " << withdrawSum << endl;
	cout << "Amount deposited: " << depositSum << endl;
}

inline double account::withdrawCount(double inputWithdrawAmount) {
	withdrawSum += inputWithdrawAmount;
	return withdrawSum;
}

inline double account::depositCount(double inputDepositAmount) {
	depositSum += inputDepositAmount;
	return inputDepositAmount;
}

inline int account::transaction(char transactionType, double inputTransactionAmount) {

	if (tolower(transactionType) == 'd') {
		balanceAmount += inputTransactionAmount;
		depositCount(inputTransactionAmount);

		cout << "Transaction Successful" << endl;

		return 1;
	} else if (tolower(transactionType) == 'w') {

		if (balanceAmount - inputTransactionAmount < 1000) {
			cout << "Transaction unsuccessful" << endl;
			return 0;
		} else if (balanceAmount - inputTransactionAmount >= 1000) {
			balanceAmount -= inputTransactionAmount;
			withdrawCount(inputTransactionAmount);

			cout << "Transaction Successful" << endl;

			return 1;
		}

	}

}

long count = 0;

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		account a[5];
		int choice, i;
		int inputAccountNumber, inputTransactionAmount;
		char transactionType;

		for (i = 0; i < 5; i++) {
			a[i].getData();
		}

		choiceLocation:
		cout << "1. Update Account" << endl;
		cout << "2. Display Account Information" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter account number: ";
				cin >> inputAccountNumber;

				for (i = 0; i < 5; i++) {

					if (inputAccountNumber == a[i].accountNumber) {
						cout << "Withdraw (w)" << endl << "Deposit (d): ";
						cin >> transactionType;
						cout << "Enter the amount: ";
						cin >> inputTransactionAmount;

						int x = a[i].transaction(transactionType, inputTransactionAmount);

						if (x == 0) {
							cout << "Transaction Unsuccesful" << endl;
						} else if (x == 1) {
							cout << "Transaction Successful" << endl;
						}

					}
					break;

				}
				
				goto choiceLocation;
				break;

			case 2:
				cout << "Enter account number: " << endl;
				cin >> inputAccountNumber;

				for (i = 0; i < 5; i++) {

					if (inputAccountNumber == a[i].accountNumber) {
						a[i].showData();
					} else {
						cout << "Account not found" << endl;
					}

				}
				goto choiceLocation;
				break;

			case 3:
				break;

			default:
				cout << "Wrong Choice" << endl;
		}


		cout << endl << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}