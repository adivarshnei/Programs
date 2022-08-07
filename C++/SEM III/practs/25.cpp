// Write a program to demonstrate operator overloading using friend function

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

   friend void operator-(Operators&);

   friend Operators operator+(Operators&, Operators&);

   void display() const {
      cout << "Operator " << opNo << endl;
      cout << "X: " << x << endl;
      cout << "Y: " << y << endl;
   }
};

int Operators::counter = 1;

void operator-(Operators& op) {
   op.x = -op.x;
   op.y = -op.y;
}

Operators operator+(Operators& op1, Operators& op2) {
   Operators op3;

   op3.x = op1.x + op2.x;
   op3.y = op1.y + op2.y;

   return op3;
}

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Operators op1 = Operators(6, 7);
      Operators op2 = Operators(5, 10);

      op1.display();
      op2.display();

      -op1;

      op1.display();

      Operators op3 = op1 + op2;

      op3.display();

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
