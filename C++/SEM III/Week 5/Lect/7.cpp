#include <iostream>

class A { // base class
protected:
   int x;

public:
   A() {
      x = 0;
   }

   A(int c) {
      x = c;
   }

   int get() {
      return x;
   }
};

class B : public A { // derived class
public:
   void input() {
      std::cin >> x;
   }

   void factorial() {
      int fact = 1;

      for (int i = 1; i <= x; i++) {
         fact = fact * i;
      }

      std::cout << fact << std::endl;
   }
};

int main(void) {
   A a1;
   B b1;
   std::cout << a1.get() << std::endl;
   std::cout << b1.get() << std::endl;
   b1.input();
   b1.factorial();

   return 0;
}