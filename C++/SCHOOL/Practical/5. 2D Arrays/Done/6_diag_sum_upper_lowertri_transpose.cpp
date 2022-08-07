#include<iostream.h>
#include<conio.h>
#include<process.h>

//*******************************************************

void upper(int a[50][50], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i < j) {
				cout << a[i][j] << " ";
			} else {
				cout << "  ";
			}

			cout << endl;
		}

	}

}

//*******************************************************

void lower(int a[50][50], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i > j) {
				cout << a[i][j] << " ";
			} else {
				cout << "  ";
			}

			cout << endl;
		}

	}

}

//*******************************************************

long int diagsum(int a[50][50], int n) {
	long int dsum = 0;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i == j) {
				dsum += a[i][j];
			}

		}

	}

	return dsum;
}

//*******************************************************

long count = 0;

//*******************************************************

int main(void) {
	int rep = 1;

	while (rep == 1) {
		clrscr();

		int n;
		int a[50][50], b[50][50];
		long dsum;
		int choice;

		cout << "Enter the number of columns of the matrix" << endl;
		cin >> n;

		if (n > 50) {
			cout << endl << "Overflow" << endl;
			getch();
			exit(0);
		}

		cout << "Enter the matrix elements" << endl;

		for (int i = 0; i < n; i++) {
			cout << "Row " << i + 1 << ": " << endl;

			for (int j = 0; j < n; j++) {
				cout << "Column " << j + 1 << ": ";
				cin >> a[i][j];
			}

		}

		for (int x = 0; x < n; x++) {

			for (int y = 0; y < n; y++) {
				cout << a[x][y] << "\t";
			}

			cout << endl;
		}

		cout << "1.Print sum of both the diagonal elements of a matrix";
		cout << "2.Print upper and lower triangle of a matrix";
		cout << "3.Print transpose of a matrix";
		cin >> choice;

		switch (choice) {
			case 1:
				dsum = diagsum(a, n);
				cout << endl << "Sum of diagonals is " << dsum << endl;
				break;

			case 2:
				cout << "Upper triangle: " << endl;
				upper(a, n);

				cout << "Lower triangle: " << endl;
				lower(a, n);
				break;

			case 3:
				for (int k = 0; k < n; k++) {

					for (int l = 0; l < n; l++) {
						b[l][k] = a[k][l];
					}
					
				}

				cout << "Transposed Matrix:";

				for (int p = 0; p < n; p++) {

					for (int q = 0; q < n; q++) {
						cout << a[p][q] << "\t";
					}

					cout << endl;
				}

				break;

		}

		cout << "Repeat Program?" << endl;
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