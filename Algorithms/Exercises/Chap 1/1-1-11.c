#include <stdio.h>
#include <stdlib.h>

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

struct Dimensions {
   int row;
   int col;
};

void printBool(struct Dimensions);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   struct Dimensions dimensions;

   system("cls");

   printf("Enter the dimensions of the array: ");
   scanf("%d%d", &dimensions.row, &dimensions.col);

   printBool(dimensions);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void printBool(struct Dimensions dimensions) {
   enum Bool** matrix;
   LoopVar i, j;
   int randNum;

   matrix = (enum Bool**) malloc(dimensions.row * sizeof(enum Bool*));

   if (matrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < dimensions.row; i++) {
      matrix[i] = (enum Bool*) malloc(dimensions.col * sizeof(enum Bool));

      if (matrix[i] == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }
   }

   for (i = 0; i < dimensions.row; i++) {
      for (j = 0; j < dimensions.col; j++) {
         randNum = rand() % 2;

         if (randNum == 0) {
            matrix[i][j] = TRUE;
         } else {
            matrix[i][j] = FALSE;
         }
      }
   }

   for (i = 0; i < dimensions.row; i++) {
      for (j = 0; j < dimensions.col; j++) {
         if (matrix[i][j] == TRUE) {
            printf("*");
         } else {
            printf(" ");
         }
      }

      printf("\n");
   }

   for (i = 0; i < dimensions.row; i++) {
      free(matrix[i]);
   }

   free(matrix);
}