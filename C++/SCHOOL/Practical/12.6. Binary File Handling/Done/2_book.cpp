#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class book {
	private:
		int bookID;
		string name[20];
		int noOfPages;
		int noInFile;

	public:
		~book();
		void getData();
		void showData();
		int returnBookID();
}; //class book

/*********************************************************************/

inline book::~book() {
	cout << endl << "Destructing Object" << endl;
} //inline book::~book()

/*********************************************************************/

inline void book::getData() {
	cout << "Enter book ID: ";
	cin >> bookID;
	cout << "Enter book name: ";
	gets(name);
	cout << "Enter number of pages: ";
	cin >> noOfPages;
} //inline void book::getData()

/*********************************************************************/

inline void book::showData() {
	cout << "Book ID: " << bookID << endl;
	cout << "Book Name: ";
	puts(name);
	cout << "Number of Pages: " << noOfPages << endl;
} //inline void book::showData()

/*********************************************************************/

inline int book::returnBookID() {
	return bookID;
} //inline int book::returnBookID()

/*********************************************************************/

book b, b1;
fstream inFile, outFile, tempFile;

/*********************************************************************/

void createFile() {
	int i = 1;
	char createChoice;
	outFile.open("p2.dat", ios::binary | ios::out);

	do {
		b.getData();
		i++;

		outFile.write((char * ) & b, sizeof(b));

		cout << "Enter more records? (Y/N): ";
		cin >> createChoice;
	} while (tolower(createChoice) == 'y');

	outFile.close();
} //void createFile()

/*********************************************************************/

void editRecord() {
	inFile.open("p2.dat", ios::binary | ios:: in );
	tempFile.open("tempFile.dat", ios::binary | ios::out);

	int recordNumber;
	int recordCounter = 0;

	cout << "Enter record number to edit: ";
	cin >> recordNumber;

	while (inFile.read((char * ) & b1, sizeof(b1))) {
		recordCounter++;

		if (recordNumber == recordCounter) {
			cout << "Enter new record: " << endl;
			b.getData();
			tempFile.write((char * ) & b, sizeof(b));
		} else {
			tempFile.write((char * ) & b1, sizeof(b1));
		} //End of extended if clause

	}//while (inFile.read((char * ) & b1, sizeof(b1)))

	inFile.close();
	tempFile.close();
	remove("p2.dat");
	rename("tempFile.dat", "p2.dat");
}//void editRecord()

/*********************************************************************/

void insertRecord() {
	inFile.open("p2.dat", ios::binary | ios:: in );
	tempFile.open("tempFile.dat", ios::binary | ios::out);

	int recordNumber;
	int recordCounter = 0;

	cout << "Enter record number to insert record at: ";
	cin >> recordNumber;

	while (inFile.read((char * ) & b1, sizeof(b1))) {
		recordCounter++;

		if (recordNumber == recordCounter) {
			cout << "Enter new record: " << endl;
			b.getData();
			tempFile.write((char * ) & b, sizeof(b));
		}//if (recordNumber == recordCounter)

		tempFile.write((char * ) & b1, sizeof(b1));
	}//while (inFile.read((char * ) & b1, sizeof(b1)))

	inFile.close();
	tempFile.close();
	remove("p2.dat");
	rename("tempFile.dat", "p2.dat");
}//void insertRecord()

/*********************************************************************/

void insertRecordAfterBookID() {
	inFile.open("p2.dat", ios::binary | ios:: in );
	tempFile.open("tempFile.dat", ios::binary | ios::out);

	int bookIDInput;
	int recordCounter = 0;

	cout << "Enter book ID to insert after at: ";
	cin >> bookIDInput;

	while (inFile.read((char * ) & b1, sizeof(b1))) {
		recordCounter++;
		tempFile.write((char * ) & b1, sizeof(b1));

		if (bookIDInput == b1.returnBookID()) {
			cout << "Enter new record: " << endl;
			b.getData();
			tempFile.write((char * ) & b, sizeof(b));
		}//if (bookIDInput == b1.returnBookID())

	}//while (inFile.read((char * ) & b1, sizeof(b1)))

	inFile.close();
	tempFile.close();
	remove("p2.dat");
	rename("tempFile.dat", "p2.dat");
}//void insertRecordAfterBookID()

/*********************************************************************/

void showAllRecords() {
	inFile.open("p2.dat", ios::binary | ios:: in );

	cout << "Records: " << endl << endl;

	while (inFile.read((char * ) & b, sizeof(b))) {
		b.showData();
		system("pause");
		cout << endl << endl;
	}//while (inFile.read((char * ) & b, sizeof(b)))

	inFile.close();
}//void showAllRecords()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		unsigned int switchChoice;
		char repeatChoice;

		createFile();

		switchChoice:
		cout << endl << endl;
		cout << "1. Edit a record of the user's choice" << endl;
		cout << "2. Insert a record at a position of the user's choice" << endl;
		cout << "3. Insert a record after a specific book ID" << endl;
		cout << "4. Display all records" << endl;
		cin >> switchChoice;

		switch (switchChoice) {
			case 1:
				editRecord();
				break;

			case 2:
				insertRecord();
				break;

			case 3:
				insertRecordAfterBookID();
				break;

			case 4:
				showAllRecords();
				break;

			default:
				goto switchChoice;
				break;
		}//switch (switchChoice)

		cout << "Go back to menu?(Y/N): ";
		cin >> repeatChoice;

		if (tolower(repeatChoice) == 'y') {
			goto switchChoice;
		}//if (tolower(repeatChoice) == 'y')

		cout << "Repeat Program?" << endl;
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