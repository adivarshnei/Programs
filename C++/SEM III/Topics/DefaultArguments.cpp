#include <iostream>

void displayNumbers(float a, float b = 3.0, float c = 0.15) {
   std::cout << a << " ";
   std::cout << b << " ";
   std::cout << c << std::endl;
}

int main(void){
   displayNumbers(5.0);
   displayNumbers(5.0, 3.8);
   displayNumbers(5.0, 3.8, 9.6);
}
