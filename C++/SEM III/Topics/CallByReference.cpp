#include <iostream>

void fun(int m) {
   m = m + 10;
}

void fun2(int& m) {
   m = m + 10;
}

int main(void) {
   int m = 10;
   fun(m);
   std::cout << m << std::endl;
   fun2(m);
   std::cout << m << std::endl;
   return 0;
}
