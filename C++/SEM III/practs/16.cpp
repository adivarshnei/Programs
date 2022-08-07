// Write a program to read and print student's information using two classes
// and simple inheritance

#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define MAX_SIZE 50

using namespace std;

typedef char String;

class StudentData {
protected:
   int rollNO;
   String name[MAX_SIZE];
   int age;
   String course[MAX_SIZE];
   char gender;
};

class StudentMethods : private StudentData {
public:
   void getData() {
      cout << "Enter the roll no of the student: ";
      cin >> rollNO;
      cin.ignore(256, '\n');
      cout << "Enter the name of the student: ";
      cin.getline(name, MAX_SIZE);
      cout << "Enter the age of the student: ";
      cin >> age;
      cin.ignore(256, '\n');
      cout << "Enter the course: ";
      cin.getline(course, MAX_SIZE);
      cout << "Enter the gender: ";
      cin >> gender;
      cin.ignore(256, '\n');
   }

   void showData() const {
      cout << "Roll No.:     " << rollNO << endl;
      cout << "Name:         " << name << endl;
      cout << "Age:          " << age << endl;
      cout << "Course:       " << course << endl;
      cout << "Gender:       " << gender << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      StudentMethods methods;

      methods.getData();
      methods.showData();

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

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
