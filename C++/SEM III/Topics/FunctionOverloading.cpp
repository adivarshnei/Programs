#include <iostream>

int sum(int a, int b) {
   return a + b;
}

int sum(int a, int b, int c) {
   return a + b + c;
}

float sum(float a, float b) {
   return a + b;
}

int main(void) {
   std::cout << "5 + 6 = " << sum(5, 6) << std::endl;
   std::cout << "5 + 6 + 7 = " << sum(5, 6, 7) << std::endl;
   std::cout << "5.5 + 6.6 = " << sum((float) 5.5, (float) 6.6) << std::endl;
   return 0;
}
