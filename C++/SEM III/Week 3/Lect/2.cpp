#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef char String;

class Student {
private:
   String name[20];
   int age;
   String gender[10];
   float percentage;
   int feePaid;

public:
   void getData() {
      cout << "Enter name: ";
      // gets(name);
      cin >> name;
      cout << "Enter age: ";
      cin >> age;
      cout << "Enter gender: ";
      // gets(gender);
      cin >> gender;
      cout << "Enter percentage: ";
      cin >> percentage;

      initialize();
   }

   void showData() {
      cout << "Name: " << name << endl;
      cout << "Age: " << age << endl;
      cout << "Gender: " << gender << endl;
      cout << "Percentage: " << percentage << endl;
      cout << "Fee Paid: " << feePaid << endl;
   }

   void initialize() {
      feePaid = 150000;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Student s1, s2;

      cout << "Student 1: " << endl;
      s1.getData();
      s1.showData();

      // cout << endl << "Student 2: " << endl;
      // s2.getData();
      // s2.showData();

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

// Function Definitions