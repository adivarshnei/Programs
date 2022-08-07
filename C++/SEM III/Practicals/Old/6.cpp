/*
Q6. The effect of a default argument can be alternatively achieved by
overloading. Discuss with an example.
*/

#include <iostream.h>
#include <stdlib.h>

enum Bool {
   YES = 1,
   NO = 2
};

void displayNums(int, int, int);
void displayNums(int, int);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int num1, num2, num3;

      cout << "Enter three integers: ";
      cin >> num1 >> num2 >> num3;

      displayNums(num1, num2, num3);
      displayNums(num1, num2);

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

void displayNums(int num1, int num2, int num3) {
   // This function can be used when all values are available
   cout << endl << "Function taking all three arguments" << endl;
   cout << "Number 1: " << num1 << endl;
   cout << "Number 2: " << num2 << endl;
   cout << "Number 3: " << num3 << endl;
}

void displayNums(int num1, int num2) {
   // This function can be used when two values are available and the third
   // one can be initialized within the function itself, acting like a default
   // argument

   int num3 = 5;

   cout << endl << "Function taking only two arguments" << endl;
   cout << "Number 1: " << num1 << endl;
   cout << "Number 2: " << num2 << endl;
   cout << "Number 3: " << num3 << endl;
}