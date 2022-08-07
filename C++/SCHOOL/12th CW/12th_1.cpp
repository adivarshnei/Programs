//Date: March 12th, 2019

#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<dos.h>

//************************************************************************************************

typedef char string;

//************************************************************************************************

class student {
	private:
		string name[30];
		int age;
		float marks[3];
		float max_marks;
		float percentage;

	public:
		float perc_calc();
		int age_chk(int);
		int name_chk(string[]);
		int perc_chk(float);
		void get_data();
		void display_data();
};

//************************************************************************************************

float student::perc_calc() {
	float total = 0;
	float perc;

	for (int i = 0; i < 3; i++) {
		total += marks[i];
	}

	perc = (total * 100) / (3 * max_marks);

	return perc;
}

//************************************************************************************************

void student::get_data() {
	cout << "Enter name of the student: ";
	gets(name);

	cout << "Enter age of the student: ";
	cin >> age;

	for (int i = 0; i < 3; i++) {
		cout << "Enter marks of student in Subject " << i + 1 << ": ";
		cin >> marks[i];
	}

	cout << "Enter maximum marks: ";
	cin >> max_marks;
}

//************************************************************************************************

void student::display_data() {
	cout << "Name of the student: ";
	puts(name);

	cout << "Age of the student: " << age << endl;

	for (int i = 0; i < 3; i++) {
		cout << "Marks of the student in Subject " << i + 1 << ": " << marks[i] << endl;
	}

	percentage = perc_calc();

	cout << "Percentage of the student: " << percentage << endl;
}

//************************************************************************************************

int student::age_chk(int input_age) {
	int flag;

	if (input_age < age) {
		flag = 1;
	} else {
		flag = 0;
	}

	return flag;
}

//************************************************************************************************

int student::name_chk(string input_name[]) {
	int flag;

	if (strcmp(input_name, name) == 0) {
		flag = 1;
	} else {
		flag = 0;
	}

	return flag;
}

//************************************************************************************************

int student::perc_chk(float perc) {
	int flag;

	if (perc < percentage) {
		flag = 1;
	} else {
		flag = 0;
	}

	return flag;
}

//************************************************************************************************

long count = 0;

//************************************************************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		clrscr();

		student s[3];
		string search_name[30];
		int search_age, flag, choice;
		float search_perc;
		int i, datafound = 0;

		for (int j = 0; j < 3; j++) {
			cout << "Student " << j + 1 << ": \n";
			s[j].get_data();
		}

		choice_location:

		cout << "1. Search by name" << endl;
		cout << "2. Search by age" << endl;
		cout << "3. Search by percentage" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter name to search: ";
				gets(search_name);

				for (i = 0; i < 3; i++) {
					flag = s[i].name_chk(search_name);

					if (flag == 1) {
						cout << "Data found" << endl;

						delay(2);
						s[i].display_data();
					} else {
						cout << "Data not found at position " << i + 1 << endl;
					}

				}

				break;

			case 2:
				cout << "Enter age to search: ";
				cin >> search_age;

				for (i = 0; i < 3; i++) {
					flag = s[i].age_chk(search_age);

					if (flag == 1) {
						datafound++;
					} else {
						continue;
					}

				}

				cout << "Number of people with age greater than " << search_age << " = " << datafound << endl << endl;
				break;

			case 3:
				cout << "Enter percentage to search: ";
				cin >> search_perc;

				for (i = 0; i < 3; i++) {
					flag = s[i].perc_chk(search_perc);

					if (flag == 1) {
						datafound++;
					} else {
						continue;
					}

				}

				cout << "Number of people with percentage greater than " << search_perc << " = " << datafound << endl << endl;
				break;

			case 4:
				break;

			default:
				cout << "Wrong Choice" << endl;
				system("pause");
				goto choice_location;
		}

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