#include<fstream.h>
#include<process.h>
#include<stdio.h>
#include<ctype.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class employee {
	private:
		int employeeNumber;
		string employeeName[20];
		double salary;

	public:
		~employee();
		void getData();
		void showData();
};//class employee

/*********************************************************************/

inline employee::~employee() {
	cout << "Destructing Object" << endl;
}//inline employee::~employee()

/*********************************************************************/

inline void employee::getData() {
	cout << "Enter employee number: ";
	cin >> employeeNumber;
	cout << "Enter employee name: ";
	gets(employeeName);
	cout << "Enter employee salary: ";
	cin >> salary;
}//inline void employee::getData()

/*********************************************************************/

inline void employee::showData() {
	cout << "Employee Number: " << employeeNumber << endl;
	cout << "Employee Name: ";
	puts(employeeName);
	cout << "Employee Salary: " << salary << endl;
}//inline void employee::showData()

/*********************************************************************/

employee e, e1;
fstream inFile, outFile, tempFile;

/*********************************************************************/

int createFile() {
	int i = 0;
	char createChoice;
	outFile.open("p3.dat", ios::binary | ios::out);

	do {
		e.getData();
		i++;

		outFile.write((char * ) & e, sizeof(e));

		cout << "Enter more records? (Y/N): ";
		cin >> createChoice;
	} while (tolower(createChoice) == 'y');

	outFile.close();
	return i;
}//int createFile()

/*********************************************************************/

void deleteRecord() {
	inFile.open("p3.dat", ios::binary | ios:: in );
	tempFile.open("tempFile.dat", ios::binary | ios::out);

	int recordCounter = 1;
	int recordNumber;

	cout << "Enter record number to be deleted: ";
	cin >> recordNumber;

	while (inFile.read((char * ) & e1, sizeof(e1))) {
		if (recordNumber != recordCounter) {
			tempFile.write((char * ) & e1, sizeof(e1));
			recordCounter++;
		}//if (recordNumber != recordCounter)
	}//while (inFile.read((char * ) & e1, sizeof(e1)))

	tempFile.close();
	inFile.close();
	remove("p3.dat");
	rename("tempFile.dat", "p3.dat");
}//void deleteRecord()

/*********************************************************************/

void deleteLastRecord(int numberOfRecords) {
	inFile.open("p3.dat", ios::binary | ios:: in );
	tempFile.open("tempFile.dat", ios::binary | ios::out);

	int recordCounter = 1;
	int recordNumber = numberOfRecords;

	while (inFile.read((char * ) & e1, sizeof(e1))) {
		if (recordNumber != recordCounter) {
			tempFile.write((char * ) & e1, sizeof(e1));
			recordCounter++;
		}//if (recordNumber != recordCounter)
	}//while (inFile.read((char * ) & e1, sizeof(e1)))

	tempFile.close();
	inFile.close();
	remove("p3.dat");
	rename("tempFile.dat", "p3.dat");
}//void deleteLastRecord(int numberOfRecords)

/*********************************************************************/

void showAllRecords() {
	inFile.open("p3.dat", ios::binary | ios:: in );

	cout << "Records: " << endl << endl;

	while (inFile.read((char * ) & e, sizeof(e))) {
		e.showData();
		system("pause");
		cout << endl << endl;
	}//while (inFile.read((char * ) & e, sizeof(e)))

	inFile.close();
}//void showAllRecords()

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

		numberOfRecords = createFile();

		switchChoice:
		cout << endl << endl;
		cout << "1. Find total no of records" << endl;
		cout << "2. Delete a record of the user's choice" << endl;
		cout << "3. Delete last record" << endl;
		cout << "4. Show all records" << endl;
		cin >> switchChoice;

		switch (switchChoice) {
			case 1:
				cout << "Number of records are: " << numberOfRecords << endl;
				break;

			case 2:
				deleteRecord();
				break;

			case 3:
				deleteLastRecord(numberOfRecords);
				break;

			case 4:
				showAllRecords();
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
		}//if (count >= 50)

	}//while (rep == 1)

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}//int main(void)