// #include <iostream>

// void foo() {
//    class Test {
//    private:
//       int a;
//       int b;

//    public:
//       Test() : a(0), b(1) {
//          std::cout << this->a << " " << this->b << std::endl;
//       }

//       ~Test() {
//          std::cout << "a = " << this->a << " b = " << this->b << std::endl;
//       }

//       static void disp() { std::cout << "disp" << std::endl; }

//       void increment() { this->a++; }
//    };

//    Test t;
//    t.disp();
//    t.increment();
// }

// int main(void) {
//    foo();

//    return 0;
// }

#include <iostream>
using namespace std;

void fun() {
   class Test {
   public:
      void method();
   };

   void Test::method() {
      { cout << "Local Class method() called"; }
   }

   Test t;
   t.method();
}

int main() {
   fun();

   return 0;
}
