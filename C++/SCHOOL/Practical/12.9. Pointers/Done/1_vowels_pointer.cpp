#include<iostream.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		string str[100];
		string * strPointer;
		int vowelCount = 0;

		cout << "Enter a string: ";
		gets(str);

		strPointer = str;

		for (;* strPointer != '\0'; strPointer++) {
			if (tolower( * strPointer) == 'a' ||
				tolower( * strPointer) == 'e' ||
				tolower( * strPointer) == 'i' ||
				tolower( * strPointer) == 'o' ||
				tolower( * strPointer) == 'u') {
				vowelCount++;
			} //End of if clause
		} //for (;* strPointer != '\0'; strPointer++)

		cout << "Number of vowels in the string: " << vowelCount << endl;

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