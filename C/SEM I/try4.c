// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define MAX_STRING 50

// typedef char String;
// typedef int LoopVar;

// struct Pair {
//    int open;
//    int close;
//    int nestLevel;
// };

// void printIndexBrackets(String*);

// int main(void) {
//    String string[MAX_STRING];
//    scanf("%[^\n]%*c", string);

//    printIndexBrackets(string);
// }

// void printIndexBrackets(String* string) {
//    struct Pair* bracketIndices;
//    int bracketCount = 0;
//    int bracketStatus = 0;
//    int nestLevel = 0;
//    LoopVar i, j;
//    LoopVar index;

//    for (i = 0; i < strlen(string); i++) {
//       if (string[i] == '(') {
//          bracketCount++;
//          bracketStatus++;
//       } else if (string[i] == ')') {
//          bracketStatus--;
//       }

//       if (bracketStatus < 0) {
//          printf("Invalid");
//          return;
//       }
//    }

//    if (bracketStatus != 0) {
//       printf("Invalid");
//       return;
//    }

//    bracketIndices = (struct Pair*) malloc(bracketCount * sizeof(struct Pair));

//    for (i = 0; i < bracketCount; i++) {
//       bracketIndices[i].open = 0;
//       bracketIndices[i].close = 0;
//    }

//    for (i = 0, index = 0; i < strlen(string); i++) {
//       if (string[i] == '(') {
//          bracketIndices[index].open = i;
//          bracketIndices[index].nestLevel = nestLevel;
//          nestLevel++;
//          index++;
//       } else if (string[i] == ')') {
//          nestLevel--;

//          for (j = 0; j < bracketCount; j++) {
//             if (bracketIndices[j].nestLevel == nestLevel) {
//                bracketIndices[j].nestLevel = -1;
//                bracketIndices[j].close = i;
//             }
//          }
//       }
//    }

//    for (i = 0; i < bracketCount; i++) {
//       printf("%-3d %-3d\n", bracketIndices[i].open, bracketIndices[i].close);
//    }
// }

#define N 10

void
multiply(int A[][N], int B[][N], int C[][N]) {
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < N; j++ ) {
            C[i][j] = 0;

            for ( int k = 0; k < N; k++ ) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}