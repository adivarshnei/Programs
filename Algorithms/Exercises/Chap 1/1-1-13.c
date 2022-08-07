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

void transpose(struct Dimensions, int**, int**);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   struct Dimensions dimensions;
   int** matrix;
   int** trMatrix;
   LoopVar i, j;

   // system("cls");

   printf("Enter the dimensions of the matrix: ");
   scanf("%d%d", &dimensions.row, &dimensions.col);

   matrix = (int**) malloc(dimensions.row * sizeof(int*));
   trMatrix = (int**) malloc(dimensions.col * sizeof(int*));

   if (matrix == NULL || trMatrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < dimensions.row; i++) {
      matrix[i] = (int*) malloc(dimensions.col * sizeof(int));

      if (matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   for (i = 0; i < dimensions.col; i++) {
      trMatrix[i] = (int*) malloc(dimensions.row * sizeof(int));

      if (trMatrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   transpose(dimensions, matrix, trMatrix);

   printf("Original Matrix: \n");

   for (i = 0; i < dimensions.row; i++) {
      for (j = 0; j < dimensions.col; j++) {
         printf("%d ", matrix[i][j]);
      }

      printf("\n");
   }

   printf("\nTransposed Matrix: \n");

   for (i = 0; i < dimensions.col; i++) {
      for (j = 0; j < dimensions.row; j++) {
         printf("%d ", trMatrix[i][j]);
      }

      printf("\n");
   }

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void transpose(struct Dimensions dimensions, int** matrix, int** trMatrix) {
   LoopVar i, j;

   for (i = 0; i < dimensions.row; i++) {
      for (j = 0; j < dimensions.col; j++) {
         matrix[i][j] = rand() % 10;
      }
   }

   for (i = 0; i < dimensions.row; i++) {
      for (j = 0; j < dimensions.col; j++) {
         trMatrix[j][i] = matrix[i][j];
      }
   }
}