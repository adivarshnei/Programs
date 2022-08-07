#include <stdio.h>
#include <string.h>

#define TEST_STRING "AEIOUaeiou"

int main(void) {
   char s[] = "the quick brown fox jumped over the lazy dog";
   int count = 0, i = 0;

   while (s[i]) {
      if(strrchr(TEST_STRING, s[i])){
         count++;
      }

      i++;
   }

   printf("Count: %d\n", count);

   return 0;
}