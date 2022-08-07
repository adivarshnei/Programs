#include<iostream.h>
#include<process.h>

/*********************************************************************/

int binarySearch(int a[], int n, int val) {
	int mid, i;
	int flag = 0;
	int low = 0;
	int high = n - 1;

	while (low <= high && flag == 0) {
		mid = (low + high) / 2;

		if (val == a[mid]) {
			flag = mid;
			return flag;
		} else if (val > a[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		} //End of extended if clause

	} //while (low <= high && flag == 0)

	return -1;
} //int binarySearch(int a[], int n, int val)

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		int a[20], n, index, i, val;

		cout << "Enter the number of elements: ";
		cin >> n;
		cout << "Enter all elements: ";

		for (i = 0; i < n; i++) {
			cin >> a[i];
		} //for (i = 0; i < n; i++)

		cout << "Enter element to be searched: ";
		cin >> val;

		index = binarySearch(a, n, val);

		if (index > -1) {
			cout << "Element found at index " << index << " and at position " << index + 1;
		} else {
			cout << "Unsuccessful Search";
		} //End of extended if clause

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