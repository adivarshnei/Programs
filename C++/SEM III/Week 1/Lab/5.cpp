// Program to find sum of first 10 numbers

#include <iostream.h>
#include <stdlib.h>
#include <math.h>

typedef int LoopVar;

int shouldRepeat;

int main(void) {
   system("cls");

   int sum;

   while (1) {
      sum = 0;

      for (LoopVar i = 1; i <= 10; i++) {
         sum += i;
      }

      cout << "Sum of first 10 integers = " << sum << endl;

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