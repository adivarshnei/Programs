#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BASE_VALUE 0

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

double logFactorial(double, long int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   long int N;
   double result;

   system("cls");

   printf("Enter N: ");
   scanf("%d", &N);

   result = logFactorial(BASE_VALUE, N);

   (result == -1) ?
      printf("Invalid Value\n") :
      printf("ln(%d!) = %Lf\n", N, result);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

double logFactorial(double lf, long int N) {
   if (N < 0) { return -1; }
   if (N == 0) { return lf; }

   return logFactorial(log(N) + lf, N - 1);
}