// Write a program to evaluate an expression using stacks

// INPUTS:
// POSTFIX: 5 6 3 * + 55 6 + 3 * + ;
// PREFIX: + + 55 * 6 3 * + 5 6 3 ;


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef char String;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void printStack(int stack[MAX_SIZE], int* top) {
   LoopVar i;

   for (i = 0; i <= *top; i++) {
      printf("%d ", stack[i]);
   }
}

enum Bool isOperator(char c) {
   if (c == '+' || c == '-' || c == '*' || c == '/') {
      return TRUE;
   } else {
      return FALSE;
   }
}

void push(int stack[MAX_SIZE], int* top, int pushedElement) {
   if (*top >= MAX_SIZE - 1) {
      printf("Stack Overflow\n");
      return;
   }

   *top = *top + 1;

   stack[*top] = pushedElement;
   return;
}

int pop(int stack[MAX_SIZE], int* top) {
   int poppedElement;

   if (*top == -1) {
      printf("Stack Underflow\n");
      return 0;
   }

   poppedElement = stack[*top];
   *top = *top - 1;

   return poppedElement;
}

void postfixEvaluation(String postfix[2 * MAX_SIZE]) {
   int top = -1;
   int stack[MAX_SIZE];
   int op1, op2;
   int pushedVal;
   int element = 0;
   LoopVar i;

   for (i = 0; i < strlen(postfix); i++) {
      if (postfix[i] == ',') {
         printf("");
      } else if (isOperator(postfix[i]) == FALSE) {
         while (postfix[i] != ',') {
            element *= 10;
            element += (int) (postfix[i] - '0');
            i++;
         }
         push(stack, &top, element);

         element = 0;
      } else {
         if (top == -1 || top == 0) {
            printf("Invalid Expression. (Too many operators in expression)\n");
            return;
         }

         op1 = pop(stack, &top);
         op2 = pop(stack, &top);

         switch (postfix[i]) {
         case '+':
            pushedVal = op2 + op1;
            push(stack, &top, pushedVal);
            break;

         case '-':
            pushedVal = op2 - op1;
            push(stack, &top, pushedVal);
            break;

         case '*':
            pushedVal = op2 * op1;
            push(stack, &top, pushedVal);
            break;

         case '/':
            if (op1 == 0) {
               printf("Invalid Expression. (Divide by Zero Error)\n");
               return;
            }

            pushedVal = op2 / op1;
            push(stack, &top, pushedVal);
            break;
         }
      }

      printf("Stack status: ");
      printStack(stack, &top);
      printf("\n");
   }

   if (top != 0) {
      printf("Invalid Expression. (Number of Operands is not enough)\n");
      return;
   }

   printf("Expression evaluates to: %d", pop(stack, &top));

   return;
}

void prefixEvaluation(String prefix[2 * MAX_SIZE]) {
   int top = -1;
   int stack[MAX_SIZE];
   int op1, op2;
   int pushedVal;
   int element = 0;
   LoopVar i;

   printf("\n%s\n", prefix);

   for (i = (strlen(prefix) - 1); i > 0; i--) {
      printf("prefix[%d] = %c\n", i, prefix[strlen(prefix) - i - 1]);
      if (i <= 0) {
         // break;
      }
   }
}

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   String element[MAX_SIZE];
   String expression[2 * MAX_SIZE] = {};
   LoopVar i;
   int choice;

   do {
      printf("\n1. Postfix Evaluation\n");
      printf("2. Prefix Evaluation\n");
      printf("3. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         printf("Enter postfix expression via space-separated elements "
                "(Use only postive digits) (Use ; to end): ");
         scanf("%s", element);

         for (i = 0; i < MAX_SIZE; i++) {
            if (strcmp(element, ";") == 0) {
               expression[strlen(expression) - 1] = '\0';
               break;
            } else {
               strcat(expression, element);
               strcat(expression, ",");
               scanf("%s", element);
            }
         }

         postfixEvaluation(expression);
         break;

      case 2:
         printf("Enter prefix expression via space-separated elements "
                "(Use only postive digits) (Use ; to end): ");
         scanf("%s", element);

         for (i = 0; i < MAX_SIZE; i++) {
            if (strcmp(element, ";") == 0) {
               expression[strlen(expression) - 1] = '\0';
               break;
            } else {
               strcat(expression, element);
               strcat(expression, ",");
               scanf("%s", element);
            }
         }

         prefixEvaluation(expression);
         break;

      case 3:
         break;

      default:
         printf("Wrong Option\n");
         break;
      }

      strcpy(expression, "");
   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
