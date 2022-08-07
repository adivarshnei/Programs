// Write a program to implement the comcept of virtual functions

#include <iostream>
#include <stdlib.h>

using namespace std;

class Base {
protected:
   int a;

public:
   Base(int a) : a(a) { }

   virtual void disp() const {
      cout << "Base Class" << endl;
      cout << "a = " << a << endl;
   }
};

class Derived : public Base {
protected:
   int b;

public:
   Derived(int b) : b(b), Base(b - 10) { }

   void disp() const {
      cout << "Derived Class" << endl;
      cout << "a = " << a << endl;
      cout << "b = " << b << endl;
   }
};

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      Base* ptr;

      ptr = new Base(5);
      ptr->disp();

      ptr = new Derived(7);
      ptr->disp();

      delete ptr;

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