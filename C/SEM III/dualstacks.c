#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 20
#define ELEM_LIMIT 20

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void push(int[MAX_SIZE], int*, int*, int);
void pop(int[MAX_SIZE], int*, int*, int);
void printArray(int[MAX_SIZE]);
void barGraph(int[MAX_SIZE], int, int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   static int stack[MAX_SIZE];
   int topA = -1;
   int topB = MAX_SIZE;
   int choice;

   system("cls");

   barGraph(stack, topA, topB);

   do {
      printf("\n1. PushA\n");
      printf("2. PushB\n");
      printf("3. PopA\n");
      printf("4. PopB\n");
      printf("5. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      system("cls");

      switch (choice) {
      case 1:
         push(stack, &topA, &topB, 1);
         // printArray(stack, top);
         break;

      case 2:
         push(stack, &topA, &topB, 2);
         break;

      case 3:
         pop(stack, &topA, &topB, 1);
         // printArray(stack, top);
         break;

      case 4:
         pop(stack, &topA, &topB, 2);
         break;

      case 5:
         break;

      default:
         printf("Wrong Option\n");
         break;
      }

      barGraph(stack, topA, topB);
      // printArray(stack);
   } while (choice != 5);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void push(int stack[MAX_SIZE], int* topA, int* topB, int type) {
   if (abs(*topA - *topB) <= 1) {
      printf("Stack Overflow\n");
      return;
   }

   srand(time(NULL));

   if (type == 1) {
      *topA = *topA + 1;

      stack[*topA] = rand() % (ELEM_LIMIT - 1) + 1;

      printf("%d pushed into stack A\n", stack[*topA]);
   } else {
      *topB = *topB - 1;

      stack[*topB] = rand() % (ELEM_LIMIT - 1) + 1;

      printf("%d pushed into stack B\n", stack[*topB]);
   }
   return;
}

void pop(int stack[MAX_SIZE], int* topA, int* topB, int type) {
   if (type == 1) {
      if (*topA == -1) {
         printf("Stack A Underflow\n");
         return;
      }

      printf("%d popped from stack A\n", stack[*topA]);

      *topA = *topA - 1;
   } else {
      if (*topB == MAX_SIZE) {
         printf("Stack B Underflow\n");
         return;
      }

      printf("%d popped from stack B\n", stack[*topB]);

      *topB = *topB + 1;
   }
   return;
}

void printArray(int stack[MAX_SIZE]) {
   LoopVar i;

   for (i = 0; i < MAX_SIZE; i++) {
      printf("%-4d", stack[i]);
   }
}

void barGraph(int stack[MAX_SIZE], int topA, int topB) {
   int max;
   LoopVar i, j;

   for (i = 0; i < ELEM_LIMIT; i++) {
      for (j = 0; j < MAX_SIZE; j++) {
         if ((j <= topA && topA != -1) || (j >= topB && topB != 20)) {
            if (stack[j] >= ELEM_LIMIT - i) {
               printf("*");
            } else {
               printf(" ");
            }
         // } else if (j >= topB && topB != 20) {
         //    if (stack[j] >= ELEM_LIMIT - i) {
         //       printf("*");
         //    } else {
         //       printf(" ");
         //    }
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   printf("topA: %2d, topb: %2d\n", topA, topB);
}
