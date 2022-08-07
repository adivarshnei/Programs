// Write a function that performs the same operation as that of Experiment 9 but
// takes on an integer value for m. Both the functions should have the same
// name. Write a main that calls both the functions.

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int LoopVar;

int shouldRepeat;

double power(double m, int n = 2) {
   double result = 1;

   for (LoopVar i = 0; i < n; i++) {
      result *= m;
   }

   return result;
}

double power(int m, int n = 2) {
   double result = 1;

   for (LoopVar i = 0; i < n; i++) {
      result *= m;
   }

   return result;
}

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
