#include<fstream.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

void change() {
	ifstream oldInFile;
	oldInFile.open("p2.txt", ios:: in );

	ofstream newOutFile;
	newOutFile.open("p2New.txt", ios::out);

	char ch;

	while (!oldInFile.eof()) {
		oldInFile.get(ch);

		if (ch == 'z') {
			ch = 'a';
		} else if (ch == '9') {
			ch = '0';
		} else if (ch == 'Z') {
			ch = 'A';
		} else {
			ch++;
		} //End of extended if clause

		newOutFile << ch;
	} //while (!oldInFile.eof())

	oldInFile.close();
	newOutFile.close();
} //void change()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		string inputString[50];

		ofstream oldOutFile;
		oldOutFile.open("p2.txt", ios::out);

		cout << "Enter line to enter into file: ";
		gets(inputString);

		oldOutFile << inputString;

		oldOutFile.close();

		change();

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