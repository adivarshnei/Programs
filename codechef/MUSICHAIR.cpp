#include <iostream>

long int
mod(long int val, long int mod) {
   return val >= mod ? val % mod : val;
}

int
main(void) {
   int T;
   std::cin >> T;

   while ( T-- ) {
      long long int N;
      int           count = 0;

      std::cin >> N;
      N--;

      for ( long long int i = 1; i * i <= N; i++ ) {
         count += (N % i == 0) ? ((i * i != N) ? 2 : 1) : 0;
      }

      std::cout << count << std::endl;
   }
   return 0;
}
