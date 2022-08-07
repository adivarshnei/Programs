// Program to swap two nums calling by reference

#include <iostream.h>
#include <stdlib.h>

void swapValues(int&, int&);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int x, y;

      cout << "Enter the values: ";
      cin >> x >> y;

      swapValues(x, y);

      cout << "Swapped Values: " << x << ", " << y << endl;

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END";
         break;
      }
   }

   system("pause");
   return 0;
}

void swapValues(int& x, int& y) {
   int temp = x;
   x = y;
   y = temp;
}