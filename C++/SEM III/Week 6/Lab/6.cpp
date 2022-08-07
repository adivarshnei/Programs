// C++ program to read and print employee information using multiple inheritance

#include <iostream>
#include <stdlib.h>

#define MAX_STRING 50

using namespace std;

typedef char String;

class PersonalDetails {
private:
   String name[MAX_STRING];
   int age;
   char gender;
   String phoneNum[MAX_STRING];

public:
   void getPersonalDetails() {
      cout << endl << "Personal Details: " << endl;
      cout << "Enter name: ";
      cin.getline(name, MAX_STRING);
      cout << "Enter age: ";
      cin >> age;
      cin.ignore(256, '\n');
      cout << "Enter gender: ";
      cin >> gender;
      cin.ignore(256, '\n');
      cout << "Enter the phone number: ";
      cin.getline(phoneNum, MAX_STRING);
   }

   void showPersonalDetails() const {
      cout << endl << "Personal Details: " << endl;
      cout << "Name:           " << name << endl;
      cout << "Age:            " << age << endl;
      cout << "Gender:         " << gender << endl;
      cout << "Phone Number:   " << phoneNum << endl;
   }
};

class ProfessionalDetails {
private:
   String position[MAX_STRING];
   int yearsExperience;
   unsigned long int salary;
   int employeeCode;

   static int employeeNum;

public:
   ProfessionalDetails() {
      employeeNum++;
   }

   void getProfessionalDetails() {
      employeeCode = employeeNum;

      cout << endl << "Professional Details" << endl;
      cout << "Enter position: ";
      cin.getline(position, MAX_STRING);
      cout << "Enter years worked: ";
      cin >> yearsExperience;
      cin.ignore(256, '\n');
      cout << "Enter salary drawn: ";
      cin >> salary;
      cin.ignore(256, '\n');
   }

   void showProfessionalDetails() const {
      cout << endl << "Professional Details" << endl;
      cout << "Employee Code:  " << employeeCode << endl;
      cout << "Postion:        " << position << endl;
      cout << "Years Worked:   " << yearsExperience << endl;
      cout << "Salary Drawn:   " << salary << endl;
   }
};

int ProfessionalDetails::employeeNum = 0;

class EmployeeMethods : private PersonalDetails, private ProfessionalDetails {
public:
   void getData() {
      getPersonalDetails();
      getProfessionalDetails();
   }

   void showData() const {
      showPersonalDetails();
      showProfessionalDetails();
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      EmployeeMethods em1;

      em1.getData();
      system("pause");
      em1.showData();

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}
