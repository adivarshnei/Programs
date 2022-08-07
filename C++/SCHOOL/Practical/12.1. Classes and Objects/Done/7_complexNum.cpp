#include<iostream.h>
#include<process.h>

//*************************************************************************

class complexNum {
	private:
		int real;
		int imaginary;

	public:
		void readData();
		void display();
		complexNum addComplex(complexNum);
		complexNum subComplex(complexNum);
};

//*************************************************************************

inline void complexNum::readData() {
	cout << "Enter complex number: " << endl;
	cout << "Real part: ";
	cin >> real;
	cout << "Imaginary part: ";
	cin >> imaginary;
}

//*************************************************************************

inline void complexNum::display() {
	cout << "Complex Number: " << endl;
	cout << real << " + " << imaginary << "i" << endl;
}

//*************************************************************************

inline complexNum complexNum::addComplex(complexNum n2) {
	complexNum n3;
	n3.real = real + n2.real;
	n3.imaginary = imaginary + n2.imaginary;

	return n3;
}

//*************************************************************************

inline complexNum complexNum::subComplex(complexNum n2) {
	complexNum n3;
	n3.real = real - n2.real;
	n3.imaginary = imaginary - n2.imaginary;

	return n3;
}

//*************************************************************************

long count = 0;

//*************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		system("cls");

		int choice;
		complexNum c1, c2, c3;

		choiceLocation:
		cout << "1. Initialize singular complex number" << endl;
		cout << "2. Add two complex numbers" << endl;
		cout << "3. Subtract two complex numbers" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				c1.readData();
				c1.display();
				goto choiceLocation;
				break;

			case 2:
				cout << "C1" << endl;
				c1.readData();
				cout << "C2" << endl;
				c2.readData();

				c3 = c1.addComplex(c2);
				cout << "C1+C2" << endl;
				c3.display();

				goto choiceLocation;
				break;

			case 3:
				cout << "C1" << endl;
				c1.readData();
				cout << "C2" << endl;
				c2.readData();

				c3 = c1.subComplex(c2);
				cout << "C1-C2" << endl;
				c3.display();

				goto choiceLocation;
				break;

			case 4:
				break;

			default:
				cout << "Wrong Choice" << endl;
				goto choiceLocation;
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