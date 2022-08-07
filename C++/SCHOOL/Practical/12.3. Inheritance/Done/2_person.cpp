#include<iostream.h>
#include<process.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class person {
	protected:
		string name[20];
		string address[50];
		unsigned int age;

	public:
		void getData();
		void showData();
}; //class person

/*********************************************************************/

class employee: protected person {
	protected: 
		unsigned int employeeNumber;
		unsigned long int basic;
		unsigned long int allowances;
		unsigned long int grossSalary;

	public: 
		void getEmployeeData();
		void showEmployeeData();
}; //class employee: protected person

/*********************************************************************/

class manager: public employee {
	private: 
		string department[20];
		unsigned int noOfEmployees;
		string designation[20];

	public:
		~manager();
		void getManagerData();
		void showManagerData();
}; //class manager: public employee

/*********************************************************************/

inline void person::getData() {
	cout << "Enter name of the person: ";
	gets(name);
	cout << "Enter the address of the person: ";
	gets(address);
	cout << "Enter the age of the person: ";
	cin >> age;
} //inline void person::getData()

/*********************************************************************/

inline void person::showData() {
	cout << "Person name: ";
	puts(name);
	cout << "Person address: ";
	puts(address);
	cout << "Person age: " << age << endl;
} //inline void person::showData()

/*********************************************************************/

inline void employee::getEmployeeData() {
	getData();

	cout << "Enter employee number: ";
	cin >> employeeNumber;
	cout << "Enter basic: ";
	cin >> basic;
	cout << "Enter allowances: ";
	cin >> allowances;
} //inline void employee::getEmployeeData()

/*********************************************************************/

inline void employee::showEmployeeData() {
	getData();

	cout << "Employee number: " << employeeNumber << endl;
	cout << "Basic salary: " << basic << endl;
	cout << "Allowances: " << allowances << endl;

	grossSalary = basic + allowances;
	cout << "Gross salary: " << grossSalary << endl;
} //inline void employee::showEmployeeData()

/*********************************************************************/

inline manager::~manager() {
	cout << "Destructing Object" << endl;
} //inline manager::~manager()

/*********************************************************************/

inline void manager::getManagerData() {
	getEmployeeData();

	cout << "Enter the manager department: ";
	gets(department);
	cout << "Enter the number of employees: ";
	cin >> noOfEmployees;
	cout << "Enter the designation: ";
	gets(designation);
} //inline void manager::getManagerData()

/*********************************************************************/

inline void manager::showManagerData() {
	showEmployeeData();

	cout << "Manager department: ";
	puts(department);
	cout << "Number of employees: " << noOfEmployees << endl;
	cout << "Manager designation: ";
	puts(designation);
} //inline void manager::showManagerData()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		manager m1;

		m1.getManagerData();
		cout << endl << "Show Data?" << endl;
		system("pause");
		cout << endl << endl;
		m1.showManagerData();

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