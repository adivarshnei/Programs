// Write a program to show the effect of call by value and call by reference

#include <iostream>
#include <stdlib.h>

using namespace std;

int shouldRepeat;

void callByVal(int a1, int b1) {
   cout << endl << "Calling by Value" << endl;
   a1 *= 10;
   b1 += 20;

   cout << "Within Function: " << endl;
   cout << "a1 = " << a1 << endl;
   cout << "b1 = " << b1 << endl;
}

void callByRef(int& a2, int& b2) {
   cout << endl << "Calling by Reference" << endl;

   a2 *= 10;
   b2 += 20;

   cout << "Within Function: " << endl;
   cout << "a2 = " << a2 << endl;
   cout << "b2 = " << b2 << endl;
}

int main(void) {
   system("cls");

   while (1) {
      int a1, b1;
      int a2, b2;

      a1 = a2 = 5;
      b1 = b2 = 10;

      callByVal(a1, b1);

      cout << "Outside Function: " << endl;
      cout << "a1 = " << a1 << endl;
      cout << "b1 = " << b1 << endl;

      callByRef(a2, b2);

      cout << "Outside Function: " << endl;
      cout << "a2 = " << a2 << endl;
      cout << "b2 = " << b2 << endl;

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
