#include<iostream.h>
#include<process.h>

unsigned long int count = 0;

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		int n;

		cout << "Enter total number of elements in array: ";
		cin >> n;

		int * arrPtr = new int[n];

		cout << "Enter the numbers: ";

		for (int i = 0; i < n; i++) {
			cin >> * (arrPtr + i);
		} //for (int i = 0; i < n; i++)

		int minNumber = * arrPtr;

		cout << "Array is: ";

		for (int j = 0; j < n; j++) {
			cout << * (arrPtr + j) << "\t";

			if ( * (arrPtr + j) < minNumber) {
				minNumber = * (arrPtr + j);
			} //if ( * (arrPtr + j) < minNumber)

			delete(arrPtr + j - 1);
		} //for (int j = 0; j < n; j++)

		cout << endl << endl << "Least number from the array is: " << minNumber << endl << endl;

		cout << "Repeat Program?" << endl;
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