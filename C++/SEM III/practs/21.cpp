// Wrie a program to read and print employee information with department and PF
// information using hierarchical inheritance

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 30

using namespace std;

typedef char String;

class EmployeeInfo {
protected:
   static String name[MAX_STRING];
   static int age;
   static char gender;
   static String phoneNum[MAX_STRING];

   static int isInit;
   static int isPrinted;

public:
   static void getEmployeeInfo() {
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

      isInit = 1;
   }

   static void showEmployeeInfo() {
      cout << endl << "Personal Details: " << endl;
      cout << "Name:         " << name << endl;
      cout << "Age:          " << age << endl;
      cout << "Gender:       " << gender << endl;
      cout << "Phone Number: " << phoneNum << endl;

      isPrinted = 1;
   }
};

String EmployeeInfo::name[MAX_STRING] = "\0";
int EmployeeInfo::age = 0;
char EmployeeInfo::gender = 0;
String EmployeeInfo::phoneNum[MAX_STRING] = "\0";
int EmployeeInfo::isInit = 0;
int EmployeeInfo::isPrinted = 0;

class DepartmentInfo;
class PFInfo;

class DepartmentInfo : public EmployeeInfo {
private:
   String dept[MAX_STRING];
   String position[MAX_STRING];
   int yearsWorked;

public:
   void getDepartment() {
      if (isInit == 0) {
         getEmployeeInfo();
      }

      cout << endl << "Department Info: " << endl;
      cout << "Enter Department: ";
      cin.getline(dept, MAX_STRING);
      cout << "Enter Position: ";
      cin.getline(position, MAX_STRING);
      cout << "Enter years worked: ";
      cin >> yearsWorked;
      cin.ignore(256, '\n');
   }

   void showDepartment() {
      if (isPrinted == 0) {
         showEmployeeInfo();
      }

      cout << endl << "Department Info: " << endl;
      cout << "Department:   " << dept << endl;
      cout << "Position:     " << position << endl;
      cout << "Years Worked: " << yearsWorked << endl;
   }
};

class PFInfo : public EmployeeInfo {
private:
   int baseSalary;
   int pfAmount;

public:
   void getPFInfo() {
      if (isInit == 0) {
         getEmployeeInfo();
      }

      cout << endl << "PF Information: " << endl;
      cout << "Enter Base Salary: ";
      cin >> baseSalary;
      cout << "Enter PF Amount: ";
      cin >> pfAmount;
   }

   void showPFInfo() {
      if (isPrinted == 0) {
         showEmployeeInfo();
      }

      cout << endl << "PF Information: " << endl;
      cout << "Base Salary:  " << baseSalary << endl;
      cout << "PF Amount:    " << pfAmount << endl;
   }
};

int shouldRepeat;

void getData(DepartmentInfo& department, PFInfo& pf) {
   department.getDepartment();
   pf.getPFInfo();
}

void showData(DepartmentInfo& department, PFInfo& pf) {
   department.showDepartment();
   pf.showPFInfo();
}

int main(void) {
   system("cls");

   while (1) {
      DepartmentInfo department;
      PFInfo pf;

      getData(department, pf);
      showData(department, pf);

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
