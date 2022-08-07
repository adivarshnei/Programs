#include <iostream>

using namespace std;

class A {
public:
  A() { cout << "Inside A" << endl; }
  A(int c) { cout << c << endl; }
};

class B : public A {
public:
  B() : A() { cout << "Inside B" << endl; }

  B(int d) : A(d) { cout << d << endl; }
};

int main(void) {
  A a1, a2(5);
  cout << "Class B" << endl;
  B b1, b2(50);
  return 0;
}
