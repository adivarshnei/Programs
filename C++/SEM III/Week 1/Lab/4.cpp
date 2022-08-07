// Program to check whether a year is leap year

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

enum Bool {
   YES = 1,
   NO = 0
};

int shouldRepeat;

int main(void) {
   system("cls");

   int year;
   Bool isLeap;

   while (1) {
      cout << "Enter the year: ";
      cin >> year;

      if (year % 4 == 0) {
         isLeap = YES;

         if (year % 100 == 0) {
            isLeap = NO;
         }
         if (year % 400 == 0) {
            isLeap = YES;
         }
      }

      if (isLeap == YES) {
         cout << year << " is a leap year" << endl;
      } else {
         cout << year << " is not a leap year" << endl;
      }

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

      if (shouldRepeat == 1) {
         continue;
      } else {
         break;
      }
   }

   system("pause");
   return 0;
}