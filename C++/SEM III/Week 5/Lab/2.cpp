// Create a class Date having day, month, and year. Use the concept of
// constructor overloading to initilize the values.

#include <iostream.h>
#include <stdlib.h>

// Enumerations

// Structures

class Date {
private:
   int x;
   int y;
};

// Function Declarations

// Inline Functions

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      // Program Body

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

// Function Definitions