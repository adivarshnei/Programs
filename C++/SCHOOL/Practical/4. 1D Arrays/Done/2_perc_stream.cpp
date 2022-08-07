#include<iostream.h>
#include<conio.h>
#include<process.h>

long count = 0;

/*
Write a program to accept marks in three subjects for 3 students.  Calculate total, percentage and store in different arrays. Decide stream of the student according to the following criteria:
Percentage              Stream
Percentage ≥ 80	        Science
Percentage < 80 & ≥ 60	Commerce
Percentage < 60 & ≥ 40	Humanities
Percentage < 40	        No Stream Allotted
Display all information of the student along with stream.
*/

//************************************************************

float perc_tot(float a, float b, float c, float max) {
	float perc;

	perc = (a + b + c) * 100 / (max * 3);

	return perc;
}

//************************************************************

int perc_chk(float a) {
	int s;

	if (a >= 80) {
		s = 1;
	} else if (a < 80 && a >= 60) {
		s = 2;
	} else if (a < 60 && a >= 40) {
		s = 3;
	} else if (a < 40) {
		s = 4;
	}

	return s;
}

//************************************************************

void display(float a[5], float max) {
	cout << "Marks scored in subject one: " << a[0] << "/" << max << endl;
	cout << "Marks scored in subject two: " << a[1] << "/" << max << endl;
	cout << "Marks scored in subject three: " << a[2] << "/" << max << endl;
	cout << "Total marks scored by student: " << a[3] << "/" << max * 3 << endl;
	cout << "Percentage: " << a[4] << endl;

	cout << endl << "Streams Qualified:" << endl;

	switch (perc_chk(a[4])) {

		case 1:
			cout << "Science" << endl;

		case 2:
			cout << "Commerce" << endl;

		case 3:
			cout << "Humanities" << endl;
			break;

		case 4:
			cout << "None" << endl;
			break;

	}

}

//************************************************************

int main(void) {
	int rep = 1;
	int rep2 = 1;

	while (rep == 1) {
		clrscr();

		cout << "Assignment 4" << endl << "Practical 2" << endl << endl;

		float st_1[5], st_2[5], st_3[5];
		float max_marks;
		int st;

		cout << "Enter the maximum marks for the examination" << endl;
		cin >> max_marks;

		cout << endl << "Enter the marks of the first student in three subjects" << endl;

		for (int i = 0; i < 3; i++) {
			cin >> st_1[i];

			if (st_1[i] > max_marks || st_1[i] < 0) {
				cout << "INVALID, enter again" << endl;
				i--;
			}

		}

		cout << endl << "Enter the marks of the second student in three subjects" << endl;

		for (int j = 0; j < 3; j++) {
			cin >> st_2[j];

			if (st_2[j] > max_marks || st_2[j] < 0) {
				cout << "INVALID, enter again" << endl;
				j--;
			}

		}

		cout << endl << "Enter the marks of the third student in three subjects" << endl;

		for (int k = 0; k < 3; k++) {
			cin >> st_3[k];

			if (st_3[k] > max_marks || st_3[k] < 0) {
				cout << "INVALID, enter again" << endl;
				k--;
			}

		}

		st_1[3] = st_2[3] = st_3[3] = 0;

		for (int tot1 = 0; tot1 < 3; tot1++) {
			st_1[3] += st_1[tot1];
		}

		for (int tot2 = 0; tot2 < 3; tot2++) {
			st_2[3] += st_2[tot2];
		}

		for (int tot3 = 0; tot3 < 3; tot3++) {
			st_3[3] += st_3[tot3];
		}

		st_1[4] = perc_tot(st_1[0], st_1[1], st_1[2], max_marks);
		st_2[4] = perc_tot(st_2[0], st_2[1], st_2[2], max_marks);
		st_3[4] = perc_tot(st_3[0], st_3[1], st_3[2], max_marks);

		while (rep2 == 1) {

			cout << endl << "1: Student 1" << endl;
			cout << "2: Student 2" << endl;
			cout << "3: Student 3" << endl;
			cout << "Enter the choice" << endl;
			cin >> st;

			clrscr();

			switch (st) {

				case 1:
					cout << "Student 1: " << endl;

					display(st_1, max_marks);

					break;

				case 2:
					cout << "Student 2: " << endl;

					display(st_2, max_marks);

					break;

				case 3:
					cout << "Student 3: " << endl;

					display(st_2, max_marks);

					break;

			}

			cout << endl << "See the marks of another student? (1=Yes, 2=No)" << endl;
			cin >> rep2;
			count++;

			if (count >= 50) {
				clrscr();

				cout << "Abnormal END" << endl;

				getch();
				exit(0);
			}

		}

		cout << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			clrscr();

			cout << "Abnormal END" << endl;

			getch();
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	getch();
	return 0;
}