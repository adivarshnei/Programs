#include <iostream>

class A {
private:
   int a;
   int b;
   int c;
   int objNo;
   static int count;

public:
   A() : a(0), b(1), c(3), objNo(count) { this->count++; }
   A(int a, int b, int c) : a(a), b(b), c(c), objNo(count) { this->count++; }
   A(A& obj) {
      this->a = obj.a;
      this->b = obj.b;
      this->c = obj.c;
      this->objNo = this->count;
      this->count++;
   }

   ~A() { std::cout << "Destructing Object " << this->objNo << std::endl; }

   void display() {
      std::cout << this->a << " " << this->b << " " << this->c << " "
                << this->objNo << std::endl;
   }
};

int A::count = 0;

int main(void) {
   A a1;
   A a2(5, 6, 7);
   A a3(a2);

   a1.display();
   a2.display();
   a3.display();
}
