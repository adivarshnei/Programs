#include<fstream.h>
#include<process.h>
#include<ctype.h>
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

		ofstream oldOutFile;
		oldOutFile.open("p4.txt", ios::out);

		cout << "Enter line to enter into file: ";
		gets(inputString);

		oldOutFile << inputString;

		oldOutFile.close();

		fstream oldInFile;
		oldInFile.open("p4.txt", ios:: in );

		fstream newOutFile;
		newOutFile.open("p4New.txt", ios::out);

		char ch2, ch;

		while (!oldInFile.eof()) {
			oldInFile.get(ch);
			ch2 = toupper(ch);
			newOutFile.put(ch2);
		} //while(!oldInFile.eof())

		long pos = newOutFile.tellp();
		newOutFile.seekp(pos - 1);
		newOutFile.put(" ");

		oldInFile.close();
		newOutFile.close();

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