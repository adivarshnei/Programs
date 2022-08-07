// Write a program to reverse a string stack arrays

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 150

typedef char String;
typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void pushStringToStack(String[MAX_LEN], String[MAX_LEN]);
void popStringFromStack(String[MAX_LEN], String[MAX_LEN]);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   String string[MAX_LEN] = {};
   String stack[MAX_LEN] = {};

   system("cls");

   printf("Enter string: ");
   gets(string);

   printf("\n\nInput String: %s", string);

   pushStringToStack(string, stack);
   popStringFromStack(string, stack);

   printf("\nReversed String: %s", string);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void pushStringToStack(String string[MAX_LEN], String stack[MAX_LEN]) {
   int top = -1;
   LoopVar i;

   for (i = 0; i < strlen(string); i++) {
      top++;
      stack[top] = string[i];
   }
}

void popStringFromStack(String string[MAX_LEN], String stack[MAX_LEN]) {
   int top = strlen(stack);
   LoopVar i = 0;

   while (top >= 0) {
      top--;
      string[i] = stack[top];
      i++;
   }
}