#include <iostream>

using namespace std;

class fibonacci {
	private:
		long double a;
		long double b;

	public:
		fibonacci();
		fibonacci(long double, long double);
		void printSequence(unsigned long int);
};

inline fibonacci::fibonacci() {
	a = 0;
	b = 1;
}

inline fibonacci::fibonacci(long double a, long double b) {
	this -> a = a;
	this -> b = b;
}

inline void fibonacci::printSequence(unsigned long int n) {
	cout << endl << "Printing Sequence: " << endl;
	cout << a << '\t';
	long double temp;
	for (long double i = 0; i < n - 1; i++) {
		cout << b << '\t';
		temp = a;
		a = b;
		b = temp + b;
	}
}

unsigned long int count = 0;

int main(int argc, char * argv[]) {
	unsigned int rep = 1;

	while (rep == 1) {
		long double choice;
		long double aInt, bInt;
		unsigned long int noOfDigits;

		cout << "1. Simple Sequence" << endl;
		cout << "2. Spec Values" << endl;
		cin >> choice;

		cout << endl << "Specify Number of Digits: ";
		cin >> noOfDigits;

		if (choice == 1) {
			fibonacci fib;
			fib.printSequence(noOfDigits);
		} else if (choice == 2) {
			cout << "Enter Starting Digits: ";
			cin >> aInt >> bInt;

			fibonacci fib(aInt, bInt);
			fib.printSequence(noOfDigits);
		}

		cout << endl << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			cout << "Abnormal END" << endl;
		}

	}

	cout << "Normal END" << endl;

	return 0;
}