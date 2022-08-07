// Write a program to implement virtual functions

#include <iostream>
#include <stdlib.h>

using namespace std;

class A {
private:
   int a;

public:
   A() : a(0) { }
   A(int a) : a(a) { }

   virtual int returnVal() const { return a; }
};

class B : public A {
private:
   int b;

public:
   B() : b(0) { }
   B(int b) : b(b) { }

   int returnVal() const { return b; }
};

class C : public A {
private:
   int c;

public:
   C() : c(0) { }
   C(int c) : c(c) { }

   int returnVal() const { return c; }
};

class D : public A {
private:
   int d;

public:
   D() : d(0) { }
   D(int d) : d(d) { }

   int returnVal() const { return d; }
};

int shouldRepeat;

inline void printVal(A* a) {
   cout << "Value: " << a->returnVal() << endl;
}

int main(void) {
   system("cls");

   while (1) {
      A* ptr;

      ptr = new A(5);
      printVal(ptr);

      ptr = new B(6);
      printVal(ptr);

      ptr = new C(7);
      printVal(ptr);

      ptr = new D(8);
      printVal(ptr);

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
