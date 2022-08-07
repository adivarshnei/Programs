/*
Q10. Write a function that performs the same operation as that of Q9 but
takes an int value for m. Both the functions should have the same name.
Write a main that calls both the functions. Use the concept of function
overloading.
*/

#include <iostream.h>
#include <stdlib.h>

typedef int LoopVar;

double power(double, int = 2);
double power(int, int = 2);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int mInteger;
      double mDecimal;
      int n;
      double resultInteger, resultDecimal;

      int choice;

      cout << "Enter the integer base: ";
      cin >> mInteger;

      cout << "Enter the decimal base: ";
      cin >> mDecimal;

      cout << "Do you want to choose exponent? (1 = YES): ";
      cin >> choice;

      if (choice == 1) {
         cout << "Enter exponent: ";
         cin >> n;

         resultInteger = power(mInteger, n);
         resultDecimal = power(mDecimal, n);

         cout << mInteger << " ^ " << n << " = " << resultInteger << endl;
         cout << mDecimal << " ^ " << n << " = " << resultDecimal << endl;
      } else {
         resultInteger = power(mInteger);
         resultDecimal = power(mDecimal);

         cout << mInteger << " ^ 2 = " << resultInteger << endl;
         cout << mDecimal << " ^ 2 = " << resultDecimal << endl;
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

double power(int m, int n) {
   double result = 1;

   for (LoopVar i = 0; i < n; i++) {
      result *= m;
   }

   return result;
}