// Create a class Date having day, month, and year. Use the concept of
// constructor overloading to initilize the value. Create object of class Date

#include <iostream>
#include <stdlib.h>

using namespace std;

class Date {
private:
   unsigned int day;
   unsigned int month;
   unsigned int year;

public:
   Date() : day(1), month(1), year(2000) { this->showData(); }

   Date(unsigned int day, unsigned int month, unsigned int year) {
      this->year = year;

      this->month = month;

      if (this->month > 12) {
         cout << "Invalid Date" << endl;
         return;
      }

      this->day = day;

      int isLeap = this->leapChecker();

      if (isLeap == 0 && this->month == 2 && this->day > 29) {
         cout << "Invalid Date" << endl;
         return;
      } else if (isLeap == 1 && this->month == 2 && this->day > 28) {
         cout << "Invalid Date" << endl;
         return;
      } else if (this->month == 1 || this->month == 3 || this->month == 5 ||
                 this->month == 6 || this->month == 8 || this->month == 10 ||
                 this->month == 12) {
         if (this->day > 31) {
            cout << "Invalid Date" << endl;
            return;
         }
      } else {
         if (this->day > 30) {
            cout << "Invalid Date" << endl;
            return;
         }
      }

      this->showData();
   }

   int leapChecker() {
      int leapCheck;

      if (this->year % 4 == 0) {
         if (this->year % 100 == 0) {
            if (this->year % 400 == 0) {
               leapCheck = 1;
            } else {
               leapCheck = 0;
            }
         } else {
            leapCheck = 1;
         }
      } else {
         leapCheck = 0;
      }

      return leapCheck;
   }

   void showData() const {
      cout << "Date is " << this->day << "/" << this->month << "/" << this->year
           << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Date d1;
      Date d2 = Date(29, 2, 2004);
      Date d3 = Date(29, 2, 2005);

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