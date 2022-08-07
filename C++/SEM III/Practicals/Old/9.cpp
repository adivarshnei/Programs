/*
Q9. Write a function power() to raise a number m to a power n. The
function takes a double value for m and int value for n, and returns the
result correctly. Use a default value of 2 for n to make the function to
calculate squares when this argument is omitted. Write a main that gets
the values of m and n from the to test the function.
*/

#include <iostream.h>
#include <stdlib.h>

typedef int LoopVar;

double power(double, int m = 2);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      double m;
      int n;
      double result;

      int choice;

      cout << "Enter the base: ";
      cin >> m;

      cout << "Do you want to choose exponent? (1 = YES): ";
      cin >> choice;

      if (choice == 1) {
         cout << "Enter exponent: ";
         cin >> n;

         result = power(m, n);

         cout << m << " ^ " << n << " = " << result << endl;
      } else {
         result = power(m);

         cout << m << " ^ 2 = " << result << endl;
      }

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

double power(double m, int n) {
   double result = 1;

   for (LoopVar i = 0; i < n; i++) {
      result *= m;
   }

   return result;
}