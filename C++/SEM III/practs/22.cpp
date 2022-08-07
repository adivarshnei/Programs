// Design three classes: Student, Exam and Result. The Student class has data
// members such as roll number, name etc. Create a class Exam by inheriting the
// Student class. The Exam class adds data members representing the marks scored
// in six subjects. Derive the Result from class Exam and it has its own members
// such as total marks. Write an interactive program to model this relationship.

#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20

using namespace std;

typedef char String;

struct Marks {
   int math;
   int deco;
   int bee;
   int dsa;
   int oop;
   int fren;
};

class Student {
protected:
   int rollNo;
   String name[MAX_STRING];

public:
   Student() {
      cout << "Data Entry: " << endl;
      cout << "Enter Name: ";
      cin.getline(this->name, MAX_STRING);
      cout << "Enter Roll No: ";
      cin >> this->rollNo;
      cin.ignore(256, '\n');
   }

   void showStudent() const {
      cout << "Roll No: " << this->rollNo << endl;
      cout << "Name: " << this->name << endl;
   }
};

class Exam : public Student {
protected:
   Marks marks;

public:
   Exam() : Student() {
      cout << endl << "Enter Marks (Out of 100): " << endl;
      cout << "Enter Mathematics marks: ";
      cin >> this->marks.math;
      cin.ignore(256, '\n');
      cout << "Enter Digital Electronics marks: ";
      cin >> this->marks.deco;
      cin.ignore(256, '\n');
      cout << "Enter Electronics Engineering marks: ";
      cin >> this->marks.bee;
      cin.ignore(256, '\n');
      cout << "Enter Data Structures marks: ";
      cin >> this->marks.dsa;
      cin.ignore(256, '\n');
      cout << "Enter Object Oriented Programming marks: ";
      cin >> this->marks.oop;
      cin.ignore(256, '\n');
      cout << "Enter French marks: ";
      cin >> this->marks.fren;
      cin.ignore(256, '\n');

      this->checkValidity();
   }

   void checkValidity() {
      if (this->marks.math > 100 || this->marks.math < 0) {
         cout << "Mathematics Marks Invalid. Enter Again: ";
         cin >> this->marks.math;
         cin.ignore(256, '\n');

         this->checkValidity();
      }

      if (this->marks.deco > 100 || this->marks.deco < 0) {
         cout << "Digital Electronics Marks Invalid. Enter Again: ";
         cin >> this->marks.deco;
         cin.ignore(256, '\n');

         this->checkValidity();
      }

      if (this->marks.bee > 100 || this->marks.bee < 0) {
         cout << "Electronics Engineering Marks Invalid. Enter Again: ";
         cin >> this->marks.bee;
         cin.ignore(256, '\n');

         this->checkValidity();
      }

      if (this->marks.dsa > 100 || this->marks.dsa < 0) {
         cout << "Data Structures Marks Invalid. Enter Again: ";
         cin >> this->marks.dsa;
         cin.ignore(256, '\n');

         this->checkValidity();
      }

      if (this->marks.oop > 100 || this->marks.oop < 0) {
         cout << "Object Oriented Programming Marks Invalid. Enter Again: ";
         cin >> this->marks.oop;
         cin.ignore(256, '\n');

         this->checkValidity();
      }

      if (this->marks.fren > 100 || this->marks.fren < 0) {
         cout << "French Marks Invalid. Enter Again: ";
         cin >> this->marks.fren;
         cin.ignore(256, '\n');

         this->checkValidity();
      }
   }

   void showExam() const {
      this->showStudent();

      cout << "Marks: " << endl;
      cout << "Mathematics: " << this->marks.math << endl;
      cout << "Digital Electronics: " << this->marks.deco << endl;
      cout << "Electronics Engineering: " << this->marks.bee << endl;
      cout << "Data Structures: " << this->marks.dsa << endl;
      cout << "Object Oriented Programming: " << this->marks.oop << endl;
      cout << "French: " << this->marks.fren << endl;
   }
};

class Result : public Exam {
private:
   int totMarks;
   float avgMarks;

public:
   Result() : Exam() { calcMarks(); }

   void calcMarks() {
      this->totMarks = this->marks.bee + this->marks.deco + this->marks.dsa +
                       this->marks.fren + this->marks.math + this->marks.oop;
      this->avgMarks = this->totMarks / 6;
   }

   void showResult() const {
      showExam();

      cout << endl << "Total Marks: " << this->totMarks << endl;
      cout << "Average Marks: " << this->avgMarks << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int choice;

      Result* R;

      do {
         cout << endl << "1. Enter and Show Student Details" << endl;
         cout << "2. Exit" << endl;
         cout << "Enter Choice: ";
         cin >> choice;
         cin.ignore(256, '\n');

         switch (choice) {
         case 1:
            R = new Result();
            R->showResult();
            break;

         case 2:
            break;

         default:
            cout << endl << "Wrong Choice" << endl;
            break;
         }

      } while (choice != 2);

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
