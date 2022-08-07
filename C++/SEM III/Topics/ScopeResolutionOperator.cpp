#include <iostream>

int x = 10;

int main(void) {
   int x = 20;

   {
      int y = x;
      int x = 30;
      std::cout << x << std::endl;
      std::cout << y << std::endl;
      std::cout << ::x << std::endl;
   }

   std::cout << x << std::endl;
   std::cout << ::x << std::endl;
}
