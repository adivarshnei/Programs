#include <iostream>

using namespace std;

void fun() {
   class Test {
   private:
      int x;
      int y;

   public:
      Test() {
         x = 5;
         y = 10;
      }

      void add() {
         cout << "x + y = " << x + y << endl;
      }
   };

   Test t1;

   t1.add();

   return;
}

int main(void) {
   // Test t2;
   // t2.add();

   fun();

   return 0;
}
