#include <iostream>

using namespace std;

class A {
public:
   A() {
      cout << "A" << endl;
   }
};

class B {
public:
   B() {
      cout << "B" << endl;
   }
};

class C : public A, B {
public:
   C() : A(), B() {
      cout << "C" << endl;
   }
};

int main(void) {
   cout << "C                        lass A" << endl;
   A a1;
   cout << "Class B" << endl;
   B b1;
   cout << "Class C" << endl;
   C c1;

   return 0;
}