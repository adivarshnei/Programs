// Program to show default arguments

#include <iostream.h>
#include <stdlib.h>

int sum(int x = 10, int y = 5);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      cout << "both def: " << endl;
      sum();
      cout << "one def: " << endl;
      sum(15);
      cout << "no def: " << endl;
      sum(3, 7);

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

int sum(int x, int y) {
   cout << "Arg 1: " << x << endl;
   cout << "Arg 2: " << y << endl;
   cout << "Sum: " << x + y << endl;
}