#include <stdio.h>
#include <stdlib.h>

typedef int LoopVar;
typedef char BufferClear;

enum Bool { TRUE = 1, FALSE = 0 };

// Enumerations

// Structures

BufferClear temp;
enum Bool shouldRepeat;

// Function Definitions

int main(void) {
   int x = 10;

   system("cls");

   if (x = 20) {
      printf("%d", x);
   }

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
