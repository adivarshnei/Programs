#include <iostream>

int
main(void) {
   int t;
   int n;

   std::cin >> t;

   for ( int i = 0; i < t; i++ ) {
      int sum = 0;

      std::cin >> n;

      for ( int j = n; j > 0; j -= 2 ) {
         sum += j * j;
      }

      std::cout << sum << std::endl;
   }

   return 0;
}
