#include<iostream.h>
#include<process.h>
#include<stdio.h>

//*************************************************************************

typedef char string;

//*************************************************************************

class Student {
	private:
		int admno;
		string sname[20];
		float mark[5];
		float total;

		float calculate() {
			float ave = (total / 5);

			return ave;
		}

	public:
		float takedata();
		void showdata();
};

//*************************************************************************

float Student::takedata() {
	cout << "Enter admission number: ";
	cin >> admno;
	cout << "Enter name of the student: ";
	gets(sname);
	cout << "Enter marks: " << endl;
	total = 0;

	for (int i = 0; i < 5; i++) {
		cout << "Subject " << i + 1 << ": ";
		cin >> mark[i];
		total += mark[i];
	}

	return calculate();
}

//*************************************************************************

void Student::showdata() {
	cout << endl << endl << "Admission Number: " << admno << endl;
	cout << "Student Name: ";
	puts(sname);

	for (int i = 0; i < 5; i++) {
		cout << "Marks in subject " << i + 1 << ": " << mark[i] << endl;
	}

	cout << "Total marks: " << total << endl;
	cout << "Average marks: " << calculate() << endl;
}

//*************************************************************************

long count = 0;

//*************************************************************************

int main(void) {
	int rep = 1;
	Student s;

	while (rep == 1) {
		system("cls");

		s.takedata();

		cout << "Show Data? " << endl;
		system("pause");

		s.showdata();

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