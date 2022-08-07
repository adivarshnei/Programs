#include <stdio.h>
#include <stdlib.h>

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void rangeChk(double, double);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   double num1, num2;

   system("cls");

   printf("Enter the two numbers: ");
   scanf("%lf%lf", &num1, &num2);

   rangeChk(num1, num2);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void rangeChk(double num1, double num2) {
   if ((num1 <= 0.0 || num1 >= 1.0) ||
       (num2 <= 0.0 || num2 >= 1.0)) {
      printf("false");
   } else {
      printf("true");
   }
}