// Write a program to implement a stack that stores names of students of a class.
// Perform all operations, i.e. Push, Pop, Display

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 20
#define MAX_SIZE 5

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef char String;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

BufferClear temp;
enum Bool shouldRepeat;

void printNames(String* stack[MAX_SIZE], int top) {
   LoopVar i;

   printf("Stack Status:\t");

   if (top == -1) {
      printf("");
      return;
   }

   for (i = 0; i <= top; i++) {
      printf("%s\t", stack[i]);
   }
}

void push(String* stack[MAX_SIZE], int* top) {
   String temp[MAX_SIZE];

   if (*top >= MAX_SIZE - 1) {
      printf("Stack Overflow\n");
      return;
   }

   *top = *top + 1;

   printf("Enter name: ");
   scanf("%[^\n]%*c", temp);
   stack[*top] = (String*) malloc(strlen(temp) * sizeof(char));

   strcpy(stack[*top], temp);

   printf("%s pushed into stack\n", stack[*top]);

   strcpy(temp, "");

   return;
}

void pop(String* stack[MAX_SIZE], int* top) {
   if (*top == -1) {
      printf("Stack Underflow\n");
      return;
   }

   printf("%s popped from stack\n", stack[*top]);

   *top = *top - 1;

   return;
}

int main(void) {
   static String* stack[MAX_SIZE];
   int top = -1;
   int choice;

   system("cls");

   do {
      printf("\n1. Push\n");
      printf("2. Pop\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);
      scanf("%c", &temp);

      // system("cls");

      switch (choice) {
      case 1:
         push(stack, &top);
         printNames(stack, top);
         break;

      case 2:
         pop(stack, &top);
         printNames(stack, top);
         break;

      case 3:
         break;

      default:
         printf("Wrong Option\n");
         break;
      }
   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
