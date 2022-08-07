#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 20

typedef int LoopVar;
typedef char BufferClear;
typedef char String;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

union Component {
   int operand;
   char operator;
};

struct Expression {
   union Component part;
   enum Bool isOperator;
   enum Bool isUsed;
};

void emptyExpression(struct Expression expression[MAX_SIZE]) {
   LoopVar i;

   for (i = 0; i < MAX_SIZE; i++) {
      expression[i].isUsed = FALSE;
   }
}

void printStack(int stack[MAX_SIZE], int top) {
   LoopVar i;

   for (i = 0; i <= top; i++) {
      printf("%d ", stack[i]);
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

void postfixEvaluation(struct Expression postfix[MAX_SIZE]) {
   int top = -1;
   int stack[MAX_SIZE];
   int op1, op2;
   int pushedVal;
   LoopVar i;

   for (i = 0; i < MAX_SIZE; i++) {
      if (postfix[i].isUsed == FALSE) {
         break;
      }

      if (postfix[i].isOperator == FALSE) {
         push(stack, &top, postfix[i].part.operand);
      } else {
         if (top == -1 || top == 0) {
            printf("Invalid Expression\n");
            return;
         }

         op1 = pop(stack, &top);
         op2 = pop(stack, &top);

         switch (postfix[i].part.operator) {
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
      printStack(stack, top);
      printf("\n");
   }
}

void prefixEvaluation(struct Expression prefix[MAX_SIZE]) {
   int top = -1;
   int stack[MAX_SIZE];
   int op1, op2;
   int pushedVal;
   LoopVar i;

   for (i = MAX_SIZE - 1; i >= 0; i--) {
      if (prefix[i].isUsed == FALSE) {
         continue;
      }

      if (prefix[i].isOperator == FALSE) {
         push(stack, &top, prefix[i].part.operand);
      } else {
         if (top == -1 || top == 0) {
            printf("Invalid Expression\n");
            return;
         }

         op1 = pop(stack, &top);
         op2 = pop(stack, &top);

         switch (prefix[i].part.operator) {
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
      printStack(stack, top);
      printf("\n");
   }
}

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   String element[MAX_SIZE];
   struct Expression expression[MAX_SIZE];
   LoopVar i, index;
   int choice;

   // system("cls");

   do {
      emptyExpression(expression);

      printf("1. Postfix Evaluation\n");
      printf("2. Prefix Evaluation\n");
      printf("3. Exit\n");
      printf("Enter Choice: ");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         index = 0;

         printf("Enter postfix expression via space separated elements "
                "(Use only positive digits) (Use ; to end): ");
         scanf("%s", element);

         for (i = 0; i < MAX_SIZE; i++) {
            if (strcmp(element, ";") == 0) {
               break;
            } else {
               if (isdigit(element[0]) == 0) {
                  expression[index].part.operator = element[0];
                  expression[index].isOperator = TRUE;
               } else {
                  expression[index].part.operand = atoi(element);
                  expression[index].isOperator = FALSE;
               }

               expression[index].isUsed = TRUE;
               index++;

               scanf("%s", element);
            }
         }

         postfixEvaluation(expression);
         break;

      case 2:
         index = 0;

         printf("Enter prefix expression via space separated elements "
                "(Use only positive digits) (Use ; to end): ");
         scanf("%s", element);

         for (i = 0; i < MAX_SIZE; i++) {
            if (strcmp(element, ";") == 0) {
               break;
            } else {
               if (isdigit(element[0]) == 0) {
                  expression[index].part.operator = element[0];
                  expression[index].isOperator = TRUE;
               } else {
                  expression[index].part.operand = atoi(element);
                  expression[index].isOperator = FALSE;
               }

               expression[index].isUsed = TRUE;
               index++;

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


   } while (choice != 3);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}
