#include <iostream>

class aClass {
private:
   int alpha;

public:
   aClass() {
      conFunc();
   }

   void nonFunc() {
      conFunc();
   }

   void conFunc2() const{
      std::cout<< 99; // Constant member function
   }

   void conFunc() const { // Constant member function
      // alpha = 99; // Not Allowed
      conFunc2();
   }
};

int main(void) {
   aClass a;
}