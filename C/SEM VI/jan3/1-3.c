// 1. Write a program to convert a valid infix expressino to postfix expression

// Included Libraries
#include <ctype.h>    // isdigit()
#include <stdio.h>    // IO and other operations
#include <stdlib.h>   // Memory operations, exit(), and atoi()
#include <string.h>   // String operations

// Mactro Definitions
#define MAX_STR 100   // Maximum string length

// Structure to implement a stack
typedef struct Stack {
  int    size;   // Total stack size
  char **arr;    // Stack element array
  int    top;    // Top of stack
} Stack;

// Function Declarations
int    prec(char const operator);
Stack *stack_init(int const size);
char  *stack_peek(Stack const *stack);
int    stack_empty(Stack const *stack);
void   stack_push(Stack *stack, char const *token);
char  *stack_pop(Stack *stack);
char **tokenize(char const *infix, int const ilen, int *tlen);
void   in_to_post(char const *infix, int const ilen, char *postfix);

int
main(void) {
  char infix[MAX_STR];   // Infix Expression. Eg: (10000/2000)*((300-40)+5)

  // Getting expression from user
  printf("Enter an infix expression: ");
  scanf("%50s", infix);

  // Allocating postfix expression
  char *postfix = ( char * ) malloc(MAX_STR * sizeof(char));
  postfix[0]    = '\0';

  // Converting infix expression to postfix expression
  in_to_post(infix, strnlen(infix, MAX_STR), postfix);
  printf("Infix:   %s\nPostfix: %s\n", infix, postfix);

  // Freeing allocated memory
  free(postfix);

  return 0;
}

// Returns precedence of operator
int
prec(char const operator) {
  if ( operator== '+' || operator== '-' ) {
    return 1;
  } else if ( operator== '*' || operator== '/' ) {
    return 2;
  } else {
    return -1;
  }
}

// Returns stack of given size
Stack *
stack_init(int const size) {
  // Allocation of stack
  Stack *stack = ( Stack * ) malloc(sizeof(Stack));

  // Exit if allocation unsuccessful
  if ( !stack ) {
    exit(1);
  }

  // Allocate and define stack elements for an empty stack
  stack->size = size;
  stack->top  = -1;
  stack->arr  = ( char  **) malloc(stack->size * sizeof(char *));

  return stack;
}

// Returns element at top of stack
char *
stack_peek(Stack const *stack) {
  if ( stack->top == -1 ) {
    // Stack is empty
    return NULL;
  }

  return stack->arr[stack->top];
}

// Checks if stack is empty
int
stack_empty(Stack const *stack) {
  // Checks if element on the top of stack is NULL, which means that the stack
  // is empty
  return (stack_peek(stack) == NULL);
}

// Pushes token to stack
void
stack_push(Stack *stack, char const *token) {
  // Pre-increments the top of stack and adds token to the new top of stack
  stack->arr[++stack->top] = ( char * ) token;
}

// Pops element and returns it from stack
char *
stack_pop(Stack *stack) {
  // If stack is empty, no element is popped
  if ( stack_empty(stack) ) {
    return NULL;
  }

  // Returns element at top of stack and post-decrements the top to the element
  // below it
  return stack->arr[stack->top--];
}

// Tokenizes an infix expression and returns an array of tokens
char **
tokenize(char const *infix, int const ilen, int *tlen) {
  // String holding the infix expression split by using '|' character as a
  // delimiter between tokens
  char tokenstr[ilen * 2];
  // Length of token string
  int  tokenstrlen = 0;
  // Number of tokens found
  *tlen            = 0;

  // Iterate across the infix expression and split it into tokens, append each
  // token to the token string, split by a '|' delimiter.
  for ( int i = 0; i < ilen; i++ ) {
    if ( isdigit(infix[i]) ) {   // If token is an operand, i.e., a number
      tokenstr[tokenstrlen++] = infix[i];

      while ( isdigit(infix[i + 1]) ) {
        tokenstr[tokenstrlen++] = infix[++i];
      }
    } else {   // If token is an operator, '(', or ')'
      tokenstr[tokenstrlen++] = infix[i];
    }

    // Adding delimiter after every token tokens
    tokenstr[tokenstrlen++] = '|';
    (*tlen)++;
  }

  // Terminating the token string
  tokenstr[tokenstrlen] = '\0';

  // Allocating array of strings holding all tokens
  char **tokens = ( char ** ) malloc((*tlen) * sizeof(char *));

  // Exit if allocation unsuccessful
  if ( !tokens ) {
    exit(1);
  }

  for ( int i = 0; i < (*tlen); i++ ) {
    // Allocating each string in token array
    tokens[i] = ( char * ) malloc(ilen * sizeof(char *));

    // Exit if allocation unsuccessful
    if ( !tokens[i] ) {
      exit(1);
    }
  }

  // Number of tokens added to token array
  int token_i = 0;
  // Index of the token array
  int token_j = 0;

  for ( int i = 0; i < tokenstrlen; i++ ) {
    if ( tokenstr[i] == '|' ) {
      // If delimiter is found, terminate current token
      tokens[token_i][token_j] = '\0';
      token_i++;
      token_j = 0;
      continue;
    }

    // Add character to current token
    tokens[token_i][token_j++] = tokenstr[i];
  }

  // tlen is returned to the calling function via pointer as the number of
  // tokens found
  // Token array is returned
  return tokens;
}

// Converts infix expression to postfix expression
void
in_to_post(char const *infix, int const ilen, char *postfix) {
  // Token count which will be obtained from tokenize function
  int    tlen   = 0;
  char **tokens = tokenize(infix, strnlen(infix, MAX_STR), &tlen);
  Stack *stack  = stack_init(tlen);

  // Iterate through the token array for every token
  for ( int i = 0; i < tlen; i++ ) {
    // If token is "(", push it to stack
    if ( strcmp(tokens[i], "(") == 0 ) {
      stack_push(stack, tokens[i]);
    }
    // If token is ")"
    else if ( strcmp(tokens[i], ")") == 0 ) {
      // Pop tokens from stack and append to postfix expression until "(" token
      // is encountered
      while ( !stack_empty(stack) && strcmp(stack_peek(stack), "(") != 0 ) {
        strncat(postfix, stack_pop(stack), MAX_STR);
        strcat(postfix, " ");
      }

      // Pop the stack to remove the "("
      stack_pop(stack);
    }
    // If token is a number, append it to postfix expression
    else if ( isdigit(tokens[i][0]) ) {
      strncat(postfix, tokens[i], MAX_STR);
      strcat(postfix, " ");
    }
    // If token is an operand
    else {
      // If the precedence of the operator in the new token is lesser than the
      // precedence of the operator on stack, all tokens in stack with greater
      // precedence are popped and appended to postfix expression
      while ( !stack_empty(stack)
              && prec(tokens[i][0]) <= prec(stack_peek(stack)[0]) ) {
        strncat(postfix, stack_pop(stack), MAX_STR);
        strcat(postfix, " ");
      }

      // Push new token to stack
      stack_push(stack, tokens[i]);
    }
  }

  // Remove any elements left in stack and append to the postfix expression
  while ( !stack_empty(stack) ) {
    strncat(postfix, stack_pop(stack), MAX_STR);
    strcat(postfix, " ");
  }

  // Terminate the postfix expression
  strcat(postfix, "\0");

  // Free memory allocated to token array and stack
  for ( int i = 0; i < tlen; i++ ) {
    free(tokens[i]);
  }

  free(tokens);
  free(stack->arr);
  free(stack);
}
