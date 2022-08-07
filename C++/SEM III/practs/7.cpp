// Write a macro that obtains the largest of three numbers

#include <iostream>
#include <stdlib.h>

#define LARGEST_NUM(a, b, c) (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c)

using namespace std;

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int num1, num2, num3;
      int largest;

      cout << "Enter three numbers: ";
      cin >> num1 >> num2 >> num3;

      largest = LARGEST_NUM(num1, num2, num3);

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
