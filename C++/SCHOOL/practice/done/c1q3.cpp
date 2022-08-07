#include<iostream.h>
#include<process.h>
#include<ctype.h>

class fibonacci {
	private:
		long int a;
		long int b;
		long int sum;
		unsigned long int n;
		unsigned int lineBreak;

	public:
		fibonacci();
		void getValue(int, int);
		void printSeries();

};

fibonacci::fibonacci() {
	a = 0;
	b = 1;
	lineBreak = 0;
}

inline void fibonacci::getValue(int inputA, int inputB) {
	a = inputA;
	b = inputB;
	lineBreak = 0;
}

inline void fibonacci::printSeries() {
	cout << "Enter the number of terms in the series: ";
	cin >> n;

	cout << a << "\t";
	lineBreak++;
	cout << b << "\t";
	lineBreak++;

	for (int i = 1; i <= n - 2; i++) {
		sum = a + b;
		cout << sum << "\t";

		lineBreak++;
		lineBreak %= 4;

		if (lineBreak == 0) {
			cout << endl;
		}

		a = b;
		b = sum;
	}
}

unsigned long int count = 0;

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		char option;
		int a, b;
		fibonacci f;

		choice:
			cout << "Enter first digits? (Y/N): ";
		cin >> option;

		switch (tolower(option)) {
			case 'y':
				cout << endl << "Enter first two digits: ";
				cin >> a >> b;

				f.getValue(a, b);
				break;

			case 'n':
				break;

			default:
				goto choice;
				break;

		}

		f.printSeries();

		cout << endl << "Repeat Program?" << endl;
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