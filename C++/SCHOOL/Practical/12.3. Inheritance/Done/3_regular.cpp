#include<iostream.h>
#include<process.h>
#include<stdio.h>

/*********************************************************************/

typedef char string;

/*********************************************************************/

class Regular {
	protected:
		unsigned int schoolCode;
		string schoolName[20];
		string schoolAddress[50];
		unsigned int noOfRegularStudents;

	public:
		void getRegularData();
		void showRegularData();
}; //class Regular

/*********************************************************************/

class Correspondence {
	protected:
		unsigned int centerCode;
		string centerName[20];
		unsigned int noOfCorrespondenceStudents;

	public:
		void getCorrespondenceData();
		void showCorrespondenceData();
}; //class Correspondence

/*********************************************************************/

class Course: public Regular, private Correspondence {
	private: 
		unsigned int courseCode;
		unsigned long int courseFees;
		unsigned int courseDuration;
		unsigned int courseChoice;

	public:
		~Course();
		void haveData();
		void display();
}; //class Course: public Regular, private Correspondence

/*********************************************************************/

inline void Regular::getRegularData() {
	cout << "Enter the school code: ";
	cin >> schoolCode;
	cout << "Enter the school name: ";
	gets(schoolName);
	cout << "Enter the school address: ";
	gets(schoolAddress);
	cout << "Enter the number of regular students: ";
	cin >> noOfRegularStudents;
} //inline void Regular::getRegularData()

/*********************************************************************/

inline void Regular::showRegularData() {
	cout << "School code: " << schoolCode << endl;
	cout << "School name: ";
	puts(schoolName);
	cout << "School address: ";
	puts(schoolAddress);
	cout << "Number of regular students: " << noOfRegularStudents << endl;
} //inline void Regular::showRegularData()

/*********************************************************************/

inline void Correspondence::getCorrespondenceData() {
	cout << "Enter center code: ";
	cin >> centerCode;
	cout << "Enter center name: ";
	gets(centerName);
	cout << "Enter number of correspondence students: ";
	cin >> noOfCorrespondenceStudents;
} //inline void Correspondence::getCorrespondenceData()

/*********************************************************************/

inline void Correspondence::showCorrespondenceData() {
	cout << "Center code: " << centerCode << endl;
	cout << "Enter center name: ";
	puts(centerName);
	cout << "Enter number of correspondence students: " << noOfCorrespondenceStudents << endl;
} //inline void Correspondence::showCorrespondenceData()

/*********************************************************************/

inline Course::~Course() {
	cout << "Destructing Object" << endl;
} //inline Course::~Course()

/*********************************************************************/

void Course::haveData() {

	do {
		cout << "Enter course type(1=Regular, 2=Correspondence): ";
		cin >> courseChoice;

		switch (courseChoice) {
			case 1:
				getRegularData();
				goto fxExitLoop;
				break;

			case 2:
				getCorrespondenceData();
				goto fxExitLoop;
				break;

			default:
				cout << "Wrong Choice: " << endl;
				break;
		} //switch (courseChoice)

	} while (1);

	fxExitLoop:
	cout << "Enter course code: ";
	cin >> courseCode;
	cout << "Enter course duration(in months): ";
	cin >> courseDuration;

	if (courseDuration >= 12) {
		courseFees = 10000;
	} else if (courseDuration < 12 && courseDuration >= 6) {
		courseFees = 8000;
	} else if (courseDuration < 6) {
		courseFees = 5000;
	} //End of extended if clause

} //void Course::haveData()

/*********************************************************************/

inline void Course::display() {

	if (courseChoice == 1) {
		showRegularData();
	} else if (courseChoice == 2) {
		showCorrespondenceData();
	} //End of extended if clause

	cout << "Course code: " << courseCode << endl;
	cout << "Course duration: " << courseDuration << endl;
	cout << "Course fees per person: " << courseFees << endl;

	if (courseChoice == 1) {
		cout << "Total course fees: " << courseFees * noOfRegularStudents << endl;
	} else if (courseChoice == 2) {
		cout << "Total course fees: " << courseFees * noOfCorrespondenceStudents << endl;
	} //End of extended if clause

} //inline void Course::display()

/*********************************************************************/

unsigned long int count = 0;

/*********************************************************************/

int main(void) {
	unsigned int rep = 1;

	while (rep == 1) {
		system("cls");

		Course c1;

		c1.haveData();
		cout << endl << "Show Data?" << endl;
		system("pause");
		cout << endl << endl;
		c1.display();

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