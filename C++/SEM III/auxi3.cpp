#include <iostream>
#include <cmath>
#include <string>

typedef int List[50];

void print(const int a, const int b) {
   std::cout << a << std::endl << b << std::endl;
}

int main() {
   string str;
   getline(cin, str);
   List list = {0};
   int a = 5;
   int b = 16;
   float c = sqrt(b);
   std::cout << c << std::endl;

   print(a, b);

   for (int i = 0; i < 10; i++) {
      std::cout << list[i] << std::endl;
   }
}
