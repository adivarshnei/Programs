#include<iostream.h>
#include<process.h>

/*************************************************************/

class fib {
	private:
		unsigned long int first;
		unsigned long int second;
		unsigned int n;

	public:
		fib();
		fib(unsigned long int, unsigned long int, unsigned int);
		~fib();
		void genFib();
}; //class fib

/*************************************************************/

inline fib::fib() {
	first = 0;
	second = 1;
	n = 10;
} //inline fib::fib()

/*************************************************************/

inline fib::fib(unsigned long int inputFirst, unsigned long int inputSecond, unsigned int inputN) {
	first = inputFirst;
	second = inputSecond;
	n = inputN;
} //inline fib::fib(unsigned long int, unsigned long int, unsigned int)

/*************************************************************/

inline fib::~fib(){
	cout<<endl<<"Destructing Object"<<endl;
}

/*************************************************************/

void fib::genFib() {
	unsigned long int third;

	cout << endl << "The series is: " << first << '\t' << second << '\t';

	for (unsigned int i = 0; i < n - 2; i++) {
		third = first + second;

		first = second;
		second = third;

		cout << second << '\t';
	}

	cout << endl << endl;
} // void fib::getFib()

/*************************************************************/

unsigned long int count = 0;

/*************************************************************/

int main(void) {
	unsigned int rep = 1;
	unsigned int choice;

	while (rep == 1) {
		system("cls");
		unsigned long int inputFirst, inputSecond;
		unsigned int inputN;

		do {
			cout << "1. Use default values to define fibonacci series (First Value=0, Second Value=1, upto 10 terms)" << endl;
			cout << "2. Use custom values to define fibonacci series" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					fib f1;
					f1.genFib();
					break;

				case 2:
					cout << endl << "Enter first value: ";
					cin >> inputFirst;
					cout << "Enter second value: ";
					cin >> inputSecond;
					cout << "Enter no of terms: ";
					cin >> inputN;

					fib f2(inputFirst, inputSecond, inputN);
					f2.genFib();
					break;

				case 3:
					goto exitLoop;

				default:
					cout << "Wrong Choice" << endl;
					break;
			} //switch (choice)

		} while (1);

		exitLoop:
		cout << endl << endl << "Repeat Program?" << endl;
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