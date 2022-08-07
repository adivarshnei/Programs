#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class floppyBox {
	private:
		unsigned long int floppyId;
		string name[20];
		unsigned int size;

	public:
		void getData();
		unsigned long int returnFloppyId();
		string * returnName();
		void showData();
}; //class floppyBox

/*********************************************************************/

inline void floppyBox::getData() {
	cout << "Enter floppy ID: ";
	cin >> floppyId;
	cout << "Enter floppy name: ";
	gets(name);
	cout << "Enter floppy size: ";
	cin >> size;
} //inline void floppyBox::getData()

/*********************************************************************/

inline unsigned long int floppyBox::returnFloppyId() {
	return floppyId;
} //inline unsigned long int floppyBox::returnFloppyId()

/*********************************************************************/

inline string * floppyBox::returnName() {
	return name;
} //inline string * floppyBox::returnName()

/*********************************************************************/

inline void floppyBox::showData() {
	cout << "Floppy ID: " << floppyId << endl;
	cout << "Floppy Name: ";
	puts(name);
	cout << "Floppy Size: " << size << endl;
} //inline void floppyBox::showData()

/*********************************************************************/

unsigned int create() {
	unsigned int i = 0;
	char createChoice;

	ofstream outFile("p1.dat", ios::binary | ios::trunc);

	do {
		floppyBox f;
		f.getData();
		outFile.write((char * ) & f, sizeof(f));
		i++;

		cout << "Enter more objects?(Y/N): ";
		cin >> createChoice;
	} while (tolower(createChoice) == 'y');

	outFile.close();

	return i;
} //unsigned int create()

/*********************************************************************/

void searchByName() {
	floppyBox f;
	char flag = 'n';
	ifstream inFile("p1.dat", ios::binary);
	int ctr;
	string n[20];

	cout << "Enter name to be searched: ";
	gets(n);

	while (!inFile.eof()) {
		inFile.read((char * ) & f, sizeof(f));

		if (strcmp(f.returnName(), n) == 0) {
			flag = 'y';
			f.showData();
			system("pause");
			break;
		} //if (strcmp(f.returnName(), n) == 0)

	} //while (!inFile.eof()

	if (flag == 'n') {
		cout << "Name not found." << endl;
	} //if (flag == 'n')

	inFile.close();
} //void searchByName()

/*********************************************************************/

void searchByNumber() {
	floppyBox f;
	char flag = 'n';
	ifstream inFile("p1.dat", ios::binary);
	int ctr;
	unsigned int ID;

	cout << "Enter ID to be searched: ";
	cin >> ID;

	while (!inFile.eof()) {
		inFile.read((char * ) & f, sizeof(f));

		if (f.returnFloppyId() == ID) {
			flag = 'y';
			f.showData();
			system("pause");
			break;
		} //if (f.returnFloppyId() == ID) 

	} //while (!inFile.eof())

	if (flag == 'n') {
		cout << "Number not found." << endl;
	} //if (flag == 'n')

	inFile.close();
} //void searchByNumber()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		unsigned int numberOfRecords;
		unsigned int switchChoice;
		char repeatChoice;

		numberOfRecords = create();

		switchChoice:
		cout << endl << endl;
		cout << "1. Find total no of records" << endl;
		cout << "2. Search and display floppy by name" << endl;
		cout << "3. Search and display floppy by ID" << endl;
		cin >> switchChoice;

		switch (switchChoice) {
			case 1:
				cout << "Number of records are: " << numberOfRecords << endl;
				break;

			case 2:
				searchByName();
				break;

			case 3:
				searchByNumber();
				break;

			default:
				goto switchChoice;
				break;
		} //switch (switchChoice)

		cout << "Go back to menu?(Y/N): ";
		cin >> repeatChoice;

		if (tolower(repeatChoice) == 'y') {
			goto switchChoice;
		} //if (tolower(repeatChoice) == 'y')

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