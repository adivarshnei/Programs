#include <iostream>
#include <stdlib.h>

int
main(void) {
   int T;
   std::cin >> T;

   for ( int i = 0; i < T; i++ ) {
      long int* arr;
      long int  N;

      std::cin >> N;

      arr = (long int*) malloc(N * sizeof(long int));

      for ( long int j = 0; j < N; j++ ) {
         std::cin >> arr[j];
      }

      long int a = 0;
      long int b = 0;

      for ( long int l = 0; l < N; l++ ) {
         if ( arr[l] > 2 ) {
            a++;
         } else if ( arr[l] == 2 ) {
            b++;
         }
      }

      long int count = a * b + (a * (a - 1)) / 2;

      std::cout << count << std::endl;
   }

   return 0;
}
