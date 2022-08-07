// Program to find sum of first 10 even numbers

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

typedef int LoopVar;

int shouldRepeat;

int main(void) {
   system("cls");

   int sum;
   LoopVar numCounter = 0, number = 1;

   while (1) {
      sum = 0;

      while (numCounter < 10) {
         if (number % 2 == 0) {
            sum += number;
            numCounter++;
         }

         number++;
      }

      cout << "Sum of first 10 even integers = " << sum << endl;

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