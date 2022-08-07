// Write a program to transpose a matrix

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 50

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef int IntArr;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

struct Dimensions {
   int row;
   int col;
};

struct Matrix {
   struct Dimensions dimensions;
   IntArr** matrix;
};

void initMatrix(struct Matrix*);
void printMatrix(struct Matrix);
void transpose(struct Matrix*, struct Matrix);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   LoopVar i;

   struct Matrix original;
   struct Matrix transposed;

   system("cls");

   printf("Enter the dimensions of the matrix (rows columns): ");
   scanf("%d%d", &original.dimensions.row, &original.dimensions.col);

   transposed.dimensions.row = original.dimensions.col;
   transposed.dimensions.col = original.dimensions.row;

   original.matrix = (IntArr**) malloc(original.dimensions.row * sizeof(IntArr*));
   transposed.matrix = (IntArr**) malloc(transposed.dimensions.row * sizeof(IntArr*));

   if (original.matrix == NULL || transposed.matrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < original.dimensions.row; i++) {
      original.matrix[i] = (int*) malloc(original.dimensions.col * sizeof(int));

      if (original.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   for (i = 0; i < transposed.dimensions.row; i++) {
      transposed.matrix[i] = (int*) malloc(transposed.dimensions.col * sizeof(int));

      if (transposed.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   initMatrix(&original);

   transpose(&transposed, original);

   printf("Original Matrix: \n");
   printMatrix(original);

   printf("\nTransposed Matrix: \n");
   printMatrix(transposed);

   for (i = 0; i < original.dimensions.row; i++) {
      free(original.matrix[i]);
   }

   for (i = 0; i < transposed.dimensions.row; i++) {
      free(transposed.matrix[i]);
   }

   free(original.matrix);
   free(transposed.matrix);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initMatrix(struct Matrix* m) {
   LoopVar i, j;

   srand(time(NULL));

   for (i = 0; i < m->dimensions.row; i++) {
      for (j = 0; j < m->dimensions.col; j++) {
         m->matrix[i][j] = rand() % ELEM_LIMIT;
      }
   }
}

void printMatrix(struct Matrix m) {
   LoopVar i, j;

   for (i = 0; i < m.dimensions.row; i++) {
      for (j = 0; j < m.dimensions.col; j++) {
         printf("%4d", m.matrix[i][j]);
      }

      printf("\n");
   }
}

void transpose(struct Matrix* transposed, struct Matrix original) {
   LoopVar i, j;

   for (i = 0; i < original.dimensions.row; i++) {
      for (j = 0; j < original.dimensions.col; j++) {
         transposed->matrix[j][i] = original.matrix[i][j];
      }
   }
}