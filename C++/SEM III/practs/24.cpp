// Write a program to demonstrate operator overloading

#include <iostream>
#include <stdlib.h>

using namespace std;

class Operators {
private:
   int x;
   int y;
   int opNo;
   static int counter;

public:
   Operators() : x(0), y(0), opNo(counter) { counter++; }

   Operators(int _x, int _y) : x(_x), y(_y), opNo(counter) { counter++; }

   void operator++() {
      x++;
      y++;
   }

   void operator>(Operators& op) {
      if (x > op.x) {
         cout << "Operator " << opNo << " has larger x" << endl;
      } else {
         cout << "Operator " << opNo << " does not have larger x" << endl;
      }

      if (y > op.y) {
         cout << "Operator " << opNo << " has larger y" << endl;
      } else {
         cout << "Operator " << opNo << " does not have larger y" << endl;
      }
   }

   void display() const {
      cout << "Operator " << opNo << endl;
      cout << "X: " << x << endl;
      cout << "Y: " << y << endl;
   }
};

int Operators::counter = 1;

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Operators op1 = Operators(6, 7);
      Operators op2 = Operators(5, 10);

      op1.display();
      op2.display();

      ++op1;

      cout << endl << "After ++ operation: " << endl;

      op1.display();

      cout << endl;

      op1 > op2;

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
