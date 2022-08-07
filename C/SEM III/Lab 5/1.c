// Write a program to check parentheses of an expression using stacks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef char String;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void push(String stack[MAX_SIZE], int* top) {
   *top = *top + 1;

   stack[*top] = '(';

   return;
}

void pop(String stack[MAX_SIZE], int* top) {
   *top = *top - 1;

   return;
}

void paranthesesChecker(String string[MAX_SIZE]) {
   int top = -1;
   String stack[MAX_SIZE];
   LoopVar i;

   for (i = 0; i < strlen(string); i++) {
      if (string[i] == '(') {
         if (top >= MAX_SIZE - 1) {
            printf("Stack Overflow\n");
            return;
         }

         push(stack, &top);
      } else if (string[i] == ')') {
         if (top == -1) {
            printf("Parantheses do not match\n");
            return;
         }

         pop(stack, &top);
      }
   }

   if (top != -1) {
      printf("Parantheses do not match\n");
   } else {
      printf("Parantheses are valid\n");
   }
}

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   String string[MAX_SIZE];

   system("cls");

   printf("Enter a string: ");
   scanf("%[^\n]%*c", string);

   paranthesesChecker(string);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
