// Write a program to demonstrate exception handling to throw an error when
// dividing by zero

#include <iostream>
#include <stdlib.h>

#define DIV_ZERO_ERR -1

using namespace std;

float calcQuotient(float numerator, float denominator) {
   if (denominator == 0) {
      throw DIV_ZERO_ERR;
   }

   return numerator / denominator;
}

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      float numerator, denominator, quotient;

      cout << "Enter numerator: ";
      cin >> numerator;

      cout << "Enter denominator: ";
      cin >> denominator;

      try {
         quotient = calcQuotient(numerator, denominator);
      } catch (int errCode) {
         if (errCode == DIV_ZERO_ERR) {
            cerr << "Divide by zero error" << endl;
            goto END;
         }
      }

      cout << numerator << " / " << denominator << " = " << quotient << endl;

   END:
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
