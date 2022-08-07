#include<iostream.h>
#include<process.h>

/*********************************************************************/

void insertionSort(int list[], int n) {
	int temp, j;

	for (int i = 0; i < n; i++) {
		temp = list[i];
		j = i - 1;

		while (temp < list[j] && j >= 0) {
			list[j + 1] = list[j];
			j--;
		} //while (temp < list[j] && j >= 0)

		list[j + 1] = temp;
		cout << endl << "After Pass " << i << "\t";

		for (int k = 0; k < n; k++) {
			cout << list[k] << "\t";
		} //for (int k = 0; k < n; k++)

	} //for (int i = 0; i < n; i++)

} //void insertionSort(int list[], int n)

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		int list[20], n;

		cout << "Enter the number of elements: ";
		cin >> n;
		cout << "Enter all elements: ";

		for (int i = 0; i < n; i++) {
			cin >> list[i];
		} //for (i = 0; i < n; i++)

		insertionSort(list, n);

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