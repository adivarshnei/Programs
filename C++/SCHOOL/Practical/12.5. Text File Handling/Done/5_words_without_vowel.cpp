#include<fstream.h>
#include<process.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		string inputString[50];

		fstream outFileText1;
		outFileText1.open("text1.txt", ios::out);

		cout << "Enter line to enter into file: ";
		gets(inputString);

		outFileText1 << inputString;

		outFileText1.close();

		fstream inFileText1;
		inFileText1.open("text1.txt", ios:: in );

		fstream outFileText2;
		outFileText2.open("text2.txt", ios::out);

		string word[40];

		while (!inFileText1.eof()) {
			inFileText1 >> word;

			if (word[0] == 'a' ||
				word[0] == 'e' ||
				word[0] == 'i' ||
				word[0] == 'o' ||
				word[0] == 'u') {
				cout << "";
			} else {
				outFileText2 << word << "     ";
			} //End of extended if clause
		} //while(!inFileText1.eof())

		outFileText2.close();
		inFileText1.close();

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