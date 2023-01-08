// 1. Write a program to convert a valid infix expression to postfix expression

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Token {
  int which;

  union {
    int  number;
    char other;
  };
};

int  token_append(struct Token *tokens, int tlen, struct Token token);
void token_display(struct Token *tokens, int tlen);
int  tokenize(char *infix, int ilen, struct Token *tokens, int tlen);

int
main(int argc, char **argv) {
  char infix[100] = "(10000+2000)-300*(40/5)";

  struct Token *tokens = ( struct Token * ) malloc(sizeof(struct Token));

  if ( !tokens ) {
    exit(1);
  }

  int tlen = tokenize(infix, strlen(infix), tokens, 0);

  token_display(tokens, tlen);
}

int
token_append(struct Token *tokens, int tlen, struct Token token) {
  tokens = ( struct Token * ) realloc(tokens, ++tlen * sizeof(struct Token));

  if ( !tokens ) {
    exit(1);
  }

  tokens[tlen - 1] = token;

  return tlen;
}

void
token_display(struct Token *tokens, int tlen) {
  for ( int i = 0; i < tlen; i++ ) {
    if ( tokens[i].which == 0 ) {
      printf("%d\n", tokens[i].number);
    } else {
      printf("%c\n", tokens[i].other);
    }
  }

  printf("\n");
}

int
tokenize(char *infix, int ilen, struct Token *tokens, int tlen) {
  char token[ilen];

  for ( int i = 0; i < ilen; i++ ) {
    token[0] = '\0';

    struct Token current;
    current.which = -1;

    if ( isdigit(infix[i]) ) {
      int start    = i;
      int tokenlen = 0;

      while ( isdigit(infix[i + (++tokenlen)]) )
        ;

      strncpy(token, infix + start, tokenlen);
      token[tokenlen] = '\0';

      int tokenint = atoi(token);

      i += (tokenlen - 1);

      current.number = tokenint;
      current.which  = 0;
    } else {
      current.other = infix[i];
      current.which = 1;
    }

    tlen = token_append(tokens, tlen, current);
  }

  return tlen;
}
