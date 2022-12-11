#include <stdio.h>

int
main(void) {
  for ( char i = 'a'; i <= 'z'; i++ ) {
    for ( char j = 'a'; j <= 'z'; j++ ) {
      for ( char k = 'a'; k <= 'z'; k++ ) {
        fprintf(stdout, "%c%c%c\n", i, j, k);
      }
    }
  }
}
