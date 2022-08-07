#include<iostream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>

/*************************************************************/

typedef char string;

/*************************************************************/

class address {
	private:
		string name[20];
		int houseNo;
		string street[15];
		string city[20];
		string country[15];

	public:
		address();
		address(string[], int, string[]);
		~address();
		void displayData();
};//class address

/*************************************************************/

inline address::address() {
	strcpy(name, '\0');
	houseNo = 0;
	strcpy(street, '\0');
	strcpy(city, '\0');
	strcpy(country, '\0');
}//inline address::address()

/*************************************************************/

inline address::address(string inputName[], int inputHouseNumber, string inputStreet[]) {
	strcpy(name, inputName);
	houseNo = inputHouseNumber;
	strcpy(street, inputStreet);
	strcpy(city, "Delhi");
	strcpy(country, "India");
}//inline address::address(string inputName[], int inputHouseNumber, string inputStreet[]) 

/*************************************************************/

inline address::~address() {
	cout << "Destructing Object" << endl;
}//inline address::~address()

/*************************************************************/

inline void address::displayData() {
	cout << endl << "Name: ";
	puts(name);
	cout << "House Number: " << houseNo << endl;
	cout << "Street: ";
	puts(street);
	cout << "City: ";
	puts(city);
	cout << "Country: ";
	puts(country);
	cout << endl;
}//inline void address::displayData()

/*************************************************************/

unsigned long int count = 0;

/*************************************************************/

int main(void) {
	unsigned int rep = 1;
	unsigned int choice;

	while (rep == 1) {
		system("cls");

		string inputName[20], inputStreet[15];
		int inputHouseNumber;

		do {
			cout << "1. Use default constructor" << endl;
			cout << "2. Use parameterized constructor" << endl;
			cout << "3. Exit" << endl;
			cin >> choice;

			switch (choice) {
				case 1:
					address a1;
					a1.displayData();
					break;

				case 2:
					cout << "Enter name: ";
					gets(inputName);
					cout << "Enter house number: ";
					cin >> inputHouseNumber;
					cout << "Enter street name: ";
					gets(inputStreet);

					address a2(inputName, inputHouseNumber, inputStreet);
					a2.displayData();
					break;

				case 3:
					goto exitLoop;
					break;

				default:
					cout << "Wrong Choice" << endl;
					break;

			}//switch (choice)

		} while (1);

		exitLoop:
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