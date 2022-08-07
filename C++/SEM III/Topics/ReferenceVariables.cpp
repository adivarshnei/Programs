#include <iostream>

int main(void){
   int total = 100;
   int& totalRef = total;

   std::cout << total << std::endl;
   std::cout << totalRef << std::endl;
   
   return 0;
}
