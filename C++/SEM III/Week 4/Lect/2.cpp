#include <iostream>

using namespace std;

class A {
private:
  static int count;
  int x;

public:
  A() {
    x = 0;
    count++;
  }

  static void fun1() { cout << count; }

  void fun2() { cout << count; }
};

int A::count = 0;

int main(void) {
  // cout << A::count; // Not possible

  A a1;
  // a1.x = 5; // Not possible

  a1.fun1();
  a1.fun2();
  // cout << a1.count; // Not possible
}
