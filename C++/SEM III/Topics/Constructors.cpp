#include <iostream>

class A {
private:
   int a;
   int b;
   int c;

public:
   A() : a(0), b(1), c(3) { }
   A(int a, int b, int c) : a(a), b(b), c(c) { }
   A(A& obj) {
      this->a = obj.a;
      this->b = obj.b;
      this->c = obj.c;
   }

   void display() { std::cout << a << " " << b << " " << c << std::endl; }
};

int main(void) {
   A a1;
   A a2(5, 6, 7);
   A a3(a2);

   a1.display();
   a2.display();
   a3.display();
}
