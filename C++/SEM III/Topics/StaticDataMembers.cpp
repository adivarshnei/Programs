#include <iostream>

class A {
private:
   static int count;
   int x;

public:
   A() : x(0) { this->count++; }

   static void fun1() { std::cout << count; }

   void fun2() { std::cout << this->x << " " << this->count; }
};

int A::count = 0;

int main(void) {
   A a1;

   a1.fun1();
   std::cout << " ";
   a1.fun2();

   std::cout << std::endl;

   A a2;

   a2.fun1();
   std::cout << " ";
   a2.fun2();

   return 0;
}
