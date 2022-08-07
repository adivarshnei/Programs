// Wrong Answer (I don't know why)

#include <iostream>
#include <cmath>

int
main(void) {
   int T;
   int N;

   std::cin >> T;

   while ( T-- ) {
      long double pow = 1;

      std::cin >> N;
      std::cout << pow << " " << pow;

      for ( int i = 1; i < N; i++ ) {
         pow *= 2;
         std::cout << " " << pow;
      }

      std::cout << std::endl;
   }

   return 0;
}
