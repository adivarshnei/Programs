#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

void createNewFile() {
	fstream oldFileIn;
	oldFileIn.open("p3.txt", ios:: in );

	fstream newFileOut;
	newFileOut.open("p3New.txt", ios::out);

	string outputString[50];

	while (!oldFileIn.eof()) {
		oldFileIn.getline(outputString, 50);

		if (outputString[0] == 'A' ||
			outputString[0] == 'E' ||
			outputString[0] == 'I' ||
			outputString[0] == 'O' ||
			outputString[0] == 'U') {
			newFileOut << outputString << "\n";
		} //End of if clause

	} //while(!oldFileIn.eof())

	oldFileIn.close();
	newFileOut.close();
} //void createNewFile()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		char lineEntryChoice;

		string inputString[50];

		fstream oldOutFile;
		oldOutFile.open("p3.txt", ios::out);

		cout << "Enter lines to enter into the file: " << endl;

		do {
			gets(inputString);
			oldOutFile << inputString << '\n';
			cout << endl << "Continue?(Y/N): ";
			cin >> lineEntryChoice;
		} while (tolower(lineEntryChoice) == 'y');

		oldOutFile.close();

		createNewFile();

		cout << "Repeat Program?" << endl;
		cin >> rep;
		count++;

		if (count >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		} //if(count>=50)

	} //while(rep==1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
} //int main(void)