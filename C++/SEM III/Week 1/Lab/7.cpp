// Program to calculate factorial of a number

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

typedef int LoopVar;

int shouldRepeat;

int main(void) {
   system("cls");

   int number, temp;
   long int factorial;

   while (1) {
      factorial = 1;

      cout << "Enter the number: ";
      cin >> number;

      temp = number;

      while (temp > 0) {
         factorial *= temp;

         temp--;
      }

      cout << number << "! = " << factorial << endl;

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