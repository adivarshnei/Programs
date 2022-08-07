#include<iostream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

//*************************************************************************

typedef char string;

//*************************************************************************

struct pr {
	string lastName[20];
	string firstName[20];
};

//*************************************************************************

class country {
	private:
		int countryID;
		string countryName[20];
		string capitalName[20];
		pr president;
		long int population;

	public:
		void getData();
		void showData();
		long int getPopulation();
		string * getCountryName();
};

//*************************************************************************

inline string * country::getCountryName() {
	return countryName;
}

//*************************************************************************

inline long int country::getPopulation() {
	return population;
}

//*************************************************************************

inline void country::getData() {
	cout << "Enter country ID: ";
	cin >> countryID;

	cout << "Enter country name: ";
	gets(countryName);

	cout << "Enter capital name: ";
	gets(capitalName);

	cout << "Enter first name of the president: ";
	gets(president.firstName);

	cout << "Enter last name of the president: ";
	gets(president.lastName);

	cout << "Enter the population: ";
	cin >> population;
}

//*************************************************************************

inline void country::showData() {
	cout << "Country ID: " << countryID << endl;
	cout << "Country Name: ";
	puts(countryName);
	cout << "Capital: ";
	puts(capitalName);
	cout << "President Name: " << endl;
	puts(president.firstName);
	cout << "\b";
	puts(president.lastName);
	cout << "Population: " << population;
}

//*************************************************************************

void search(string searchName[], country c[]) {

	for (int i = 0; i < 4; i++) {

		if (strcmp(searchName, c[i].getCountryName()) == 0) {
			c[i].showData();
		}

	}

}

//*************************************************************************

int count(long searchPopulation, country c[]) {
	int number = 0;

	for (int i = 0; i < 4; i++) {

		if (c[i].getPopulation() > searchPopulation) {
			cout << endl << "Country Found: " << endl;
			number++;
		}

	}

	return number;
}

//*************************************************************************

long counter = 0;

//*************************************************************************

int main(void) {
	int rep = 1;
	int choice, no;
	string searchName[20];
	long int searchPopulation;
	country c[4];

	while (rep == 1) {
		system("cls");

		cout << "Enter data for 4 countries: " << endl;

		for (int i = 0; i < 4; i++) {
			c[i].getData();
		}

		system("cls");

		choiceLocation:
		cout << endl << "1. Search by name" << endl;
		cout << "2. List by population" << endl;
		cout << "3. Exit" << endl;
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter the country name to be searched: ";
				gets(searchName);
				search(searchName, c);
				break;

			case 2:
				cout << "Enter the population to be searched: ";
				cin >> searchPopulation;
				no = count(searchPopulation, c);
				cout << "Number of countries with population greater than " << searchPopulation << " is " << no;
				break;

			case 3:
				break;

			default:
				cout << "Wrong Choice" << endl;
				goto choiceLocation;

		}

		cout << endl << endl << "Repeat Program?" << endl;
		cin >> rep;
		counter++;

		if (counter >= 50) {
			system("cls");

			cout << "Abnormal END" << endl;

			system("pause");
			exit(0);
		}

	}

	cout << "Normal END" << endl;

	system("pause");
	return 0;
}