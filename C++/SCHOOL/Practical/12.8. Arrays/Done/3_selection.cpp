#include<iostream.h>
#include<process.h>

/*********************************************************************/

void selectionSort(int a[], int n) {
	int small, pos, temp;

	for (int i = 0; i < n; i++) {
		int j;

		small = a[i];
		pos = i;

		for (j = i + 1; j < n; j++) {
			if (a[j] < small) {
				small = a[j];
				pos = j;
			} //if (a[j] < small)
		} //for (j = i + 1; j < n; j++)

		temp = a[i];
		a[i] = a[pos];
		a[pos] = temp;

		cout << endl << "After Pass " << i + 1 << "\t";

		for (j = 0; j < n; j++) {
			cout << a[j] << "\t";
		} //for (j = 0; j < n; j++)

	} //for (int i = 0; i < n; i++)

} //void selectionSort(int a[], int n)

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		int a[20], n;

		cout << "Enter the number of elements: ";
		cin >> n;
		cout << "Enter all elements: ";

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		} //for (i = 0; i < n; i++)

		selectionSort(a, n);

		cout << endl << "Repeat Program?" << endl;
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