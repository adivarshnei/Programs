// Program to find whether number is even or odd

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

int shouldRepeat;

int main(void) {
   system("cls");

   int number;

   while (1) {
      cout << "Enter the number: ";
      cin >> number;

      if (number % 2 == 0) {
         cout << number << " is even" << endl;
      } else {
         cout << number << " is odd" << endl;
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