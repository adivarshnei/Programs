#include <iostream>

int
main(void) {
   int T;

   std::cin >> T;

   while ( T-- ) {
      long int N;
      std::cin >> N;

      long int* a = (long int*) malloc(N * sizeof(long int));
      double*   x = (double*) malloc(N * sizeof(double));

      for ( int i = 0; i < N; i++ ) {
         std::cin >> a[i];
         x[i] = 0;
      }

      for ( int j = 0; j < N; j++ ) {
         for ( int k = 0; k < N; k++ ) {
            x[j] += (j == k) ? ((double) a[k] * (-(double) (N - 2)))
                             : ((double) a[k]);
         }

         x[j] /= (double) (N - 1);
      }

      for ( int l = 0; l < N; l++ ) {
         std::cout << x[l] << " ";
      }

      std::cout << std::endl;
   }
}
