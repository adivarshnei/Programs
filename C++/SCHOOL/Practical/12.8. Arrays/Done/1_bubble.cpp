#include<iostream.h>
#include<process.h>

/*********************************************************************/

void bubbleSort(int a[], int n) {
	int temp;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n - i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}//if (a[j] > a[j + 1])
		}//for (int j = 0; j < n - i; j++)

		cout << "\nAfter Pass " << i << "\t";

		for (int k = 0; k < n; k++) {
			cout << a[k] << "\t";
		}//for (int k = 0; k < n; k++)

	}//for (int i = 0; i < n; i++) 

}//void bubbleSort(int a[], int n)

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

		bubbleSort(a, n);

		cout << endl << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}//if (count >= 50)

	}//while (rep == 1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}//int main(void)