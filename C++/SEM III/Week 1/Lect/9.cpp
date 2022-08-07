// Program to calculate factorial via function

#include <iostream.h>
#include <stdlib.h>

enum Type {
   RECURSIVE = 1,
   NORMAL = 2
};

typedef int LoopVar;

long int factorial(long int, Type);
long int factorialNORM(long int);
long int factorialREC(long int);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      long int num, fact;

      cout << "Enter the number: ";
      cin >> num;

      fact = factorial(num, RECURSIVE);

      cout << num << "! = " << fact << endl;

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

long int factorial(long int num, Type type) {
   if (type == RECURSIVE) {
      return factorialREC(num);
   } else if (type == NORMAL) {
      return factorialNORM(num);
   }
}

long int factorialNORM(long int num) {
   long int result = 1;

   for (LoopVar i = num; i >= 1; i++) {
      result *= num;
   }

   return result;
}

long int factorialREC(long int num) {
   if (num == 1) {
      return 1;
   } else {
      return num * factorialREC(num - 1);
   }
}