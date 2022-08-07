#include <iostream>

void aFunc(int& a, const int& b);

int main() {
   int alpha = 7;
   int beta = 11;

   aFunc(alpha, beta);

   std::cout << alpha << std::endl << beta;

   return 0;
}

void aFunc(int& a, const int& b) {
   a = 107;
   // b = 117;  // Not possible, b is const
}