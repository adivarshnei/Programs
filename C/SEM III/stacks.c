#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20
#define ELEM_LIMIT 20

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void push(int[MAX_SIZE], int*);
void pop(int[MAX_SIZE], int*);
void printArray(int[MAX_SIZE], int);
void barGraph(int[MAX_SIZE], int);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   static int stack[MAX_SIZE];
   int top = -1;
   int choice;

   system("cls");

   do {
      printf("1. Push\n");
      printf("2. Pop\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      system("cls");

      switch (choice) {
      case 1:
         push(stack, &top);
         // printArray(stack, top);
         break;

      case 2:
         pop(stack, &top);
         // printArray(stack, top);
         break;

      case 3:
         break;

      default:
         printf("Wrong Option\n");
         break;
      }

      barGraph(stack, top);
   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void push(int stack[MAX_SIZE], int* top) {
   if (*top >= MAX_SIZE - 1) {
      printf("Stack Overflow\n");
      return;
   }

   srand(time(NULL));

   *top = *top + 1;

   stack[*top] = rand() % (ELEM_LIMIT - 1) + 1;

   printf("%d pushed into stack\n", stack[*top]);

   return;
}

void pop(int stack[MAX_SIZE], int* top) {
   if (*top == -1) {
      printf("Stack Underflow\n");
      return;
   }

   printf("%d popped from stack\n", stack[*top]);

   *top = *top - 1;

   return;
}

void printArray(int stack[MAX_SIZE], int top) {
   LoopVar i;

   for (i = 0; i <= top; i++) {
      printf("%-4d", stack[i]);
   }
}

void barGraph(int stack[MAX_SIZE], int top) {
   int max;
   LoopVar i, j;

   for (i = 0; i < ELEM_LIMIT; i++) {
      for (j = top + 1; j > 0; j--) {
         if (stack[j - 1] >= ELEM_LIMIT - i) {
            printf("*");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }
}
