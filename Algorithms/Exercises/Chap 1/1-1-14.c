#include <stdio.h>
#include <stdlib.h>

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

long int lg(int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   int N;
   long int result;

   system("cls");

   printf("Enter the number: ");
   scanf("%d", &N);

   result = lg(N);

   if (result != -1) {
      printf("Largest integer smaller than base 2 logarithm of N = %ld", result);
   } else {
      printf("Invalid value");
   }

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

long int lg(int N) {
   int result = -1, powterm = 1;

   if (N <= 0) {
      return -1;
   }

   while (powterm <= N) {
      powterm <<= 1;
      result++;
   }

   return result;
}