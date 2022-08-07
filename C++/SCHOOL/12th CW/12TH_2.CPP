//Date: March 14th, 2019

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>

//************************************************************************************************

typedef char string;

//************************************************************************************************

class employee {
	private:
		int employee_no;
		string employee_name[20];
		float basic;
		float hra;
		float da;
		float net_pay;

		float calculate() {
			float net;
			net = basic + hra + da;
			return net;
		}

	public:
		void have_data();
		void display_data();
};

//************************************************************************************************

inline void employee::have_data() {
	cout << "Enter employee number: ";
	cin >> employee_no;

	cout << "Enter employee name: ";
	gets(employee_name);

	cout << "Enter basic salary, HRA and DA respectively: " << endl;
	cin >> basic >> hra >> da;

	net_pay = calculate();
}

//************************************************************************************************

inline void employee::display_data() {
	cout << endl << "Employee Number: " << employee_no << endl;

	cout << "Employee Name: ";
	puts(employee_name);

	cout << "Net Pay: " << net_pay << endl;
}

//************************************************************************************************

long count = 0;

//************************************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		clrscr();

		employee emp;

		cout << "Enter employee data: " << endl;
		emp.have_data();

		cout << endl << endl << "Display data?" << endl;
		system("pause");

		emp.display_data();

		cout << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			clrscr();
			cout << "Abnormal END" << endl;
			system("pause");
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}