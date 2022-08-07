#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<ctype.h>
#include<string.h>

/*********************************************************************/

typedef char string;
typedef int counter;

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		string inputString[100];
		char inputChoice;
		counter theLineCount = 0;

		fstream outFile;
		outFile.open("p6.txt", ios::out);

		do {
			cout << "Enter line to input into file: ";
			gets(inputString);
			outFile << inputString << endl;

			cout << "Continue?: ";
			cin >> inputChoice;
		} while (tolower(inputChoice) == 'y');

		outFile.close();

		string line[100];
		string compString[5];

		fstream inFile;
		inFile.open("p6.txt", ios:: in );

		while (!inFile.eof()) {
			inFile.getline(line, 100);

			if (tolower(line[0]) == 't' &&
				tolower(line[1]) == 'h' &&
				tolower(line[2]) == 'e') {
				theLineCount++;
			} //End of if clause

		} //while(!inFile.eof())

		cout << "Number of lines that start with \"the\": " << theLineCount << endl;

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