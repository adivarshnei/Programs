// 1. Write a program to convert a valid infix expression to postfix expression

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
  int   size;
  char *arr;
  int   top;
};

struct Stack *stack_init(int size);
void          stack_push(struct Stack *stack, char elem);
char          stack_pop(struct Stack *stack);
char          stack_peek(struct Stack *stack);
int           postfix_conv(char *infix, int ilen, char *postfix);

int
main(int argc, char **argv) {
  char infix[100] = "a+b*c/d";
  char postfix[100];

  int plen = postfix_conv(infix, strlen(infix), postfix);

  printf("ifix: %s\n", infix);
  printf("pfix: %s (len = %d)\n", postfix, plen);

  return 0;
}

struct Stack *
stack_init(int size) {
  struct Stack *stack = ( struct Stack * ) malloc(sizeof(struct Stack));

  if ( !stack ) {
    return NULL;
  }

  stack->size = size;
  stack->top  = -1;
  stack->arr  = ( char  *) malloc(stack->size * sizeof(char));

  return stack;
}

void
stack_push(struct Stack *stack, char elem) {
  stack->top++;
  stack->arr[stack->top] = elem;
}

char
stack_pop(struct Stack *stack) {
  if ( stack_peek(stack) == '\0' ) {
    return '!';
  }

  return stack->arr[stack->top--];
}

char
stack_peek(struct Stack *stack) {
  if ( stack->top == -1 ) {
    return '\0';
  }

  return stack->arr[stack->top];
}

int
postfix_conv(char *infix, int ilen, char *postfix) {
  int plen = 0;

  for ( int i = 0; i < ilen; i++ ) {
    if ( isalpha(infix[i]) ) {
      postfix[plen++] = infix[i];
    }
  }

  postfix[plen] = '\0';

  return plen;
}