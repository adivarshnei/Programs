// Program to calculate square of a number

#include <iostream.h>
#include <stdlib.h>

enum Bool {
   YES = 1,
   NO = 0
};

enum Bool shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      float num, numSq;

      cout << "Enter a number: ";
      cin >> num;

      numSq = num * num;

      cout << num << " ^ 2 = " << numSq << endl;

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

      if (shouldRepeat == YES) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}