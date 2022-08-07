// Rewrite Experiment 7 using inline function.

#include <iostream>
#include <stdlib.h>

using namespace std;

int shouldRepeat;

inline int largestNumber(int num1, int num2, int num3) {
   return (num1 > num2) ? ((num1 > num3) ? num1 : num3)
                        : ((num2 > num3) ? num2 : num3);
}

int main(void) {
   system("cls");

   while (1) {
      int num1, num2, num3;
      int largest;

      cout << "Enter three numbers: ";
      cin >> num1 >> num2 >> num3;

      largest = largestNumber(num1, num2, num3);

      cout << endl << "Largest Number is: " << largest << endl;

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
