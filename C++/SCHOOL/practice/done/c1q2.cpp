#include<iostream.h>
#include<process.h>

unsigned long int count = 0;

unsigned long int calcComRate(unsigned long int sale) {
	if (sale >= 0 && sale <= 5000) {
		return 0;
	} else if (sale >= 5001 && sale <= 12000) {
		return 3;
	} else if (sale >= 12001 && sale <= 22000) {
		return 7;
	} else if (sale >= 22001 && sale <= 30000) {
		return 10;
	} else if (sale >= 30001) {
		return 15;
	}
}

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		unsigned long int sale;

		cout << "Enter sales: ";
		cin >> sale;

		cout << "Commission: " << calcComRate(sale) << "%" << endl;

		cout << "Repeat Program?" << endl;
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