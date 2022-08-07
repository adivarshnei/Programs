// Write a menu driven program to perform following operations on 2 matrices: 
// Addition
// Subtraction
// Multiplication

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

void initMatrices(struct Matrix*, struct Matrix*);
void printMatrix(struct Matrix);
void add();
void subtract();
void multiply();

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   LoopVar i;
   int choice;

   system("cls");

   do {
      printf("1. Add two matrices\n");
      printf("2. Subtract two matrices\n");
      printf("3. Multiply two matrices\n");
      printf("4. Exit\n");
      scanf("%d", &choice);

      switch (choice) {
      case 1:
         add();
         break;

      case 2:
         subtract();
         break;

      case 3:
         multiply();
         break;

      case 4:
         break;

      default:
         printf("Wrong Option\n");
         break;
      }
   } while (choice != 4);

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void initMatrices(struct Matrix* m, struct Matrix* n) {
   LoopVar i, j;

   srand(time(NULL));

   for (i = 0; i < m->dimensions.row; i++) {
      for (j = 0; j < m->dimensions.col; j++) {
         m->matrix[i][j] = rand() % ELEM_LIMIT;
      }
   }

   for (i = 0; i < n->dimensions.row; i++) {
      for (j = 0; j < n->dimensions.col; j++) {
         n->matrix[i][j] = rand() % ELEM_LIMIT;
      }
   }
}

void printMatrix(struct Matrix m) {
   LoopVar i, j;

   for (i = 0; i < m.dimensions.row; i++) {
      for (j = 0; j < m.dimensions.col; j++) {
         printf("%d\t", m.matrix[i][j]);
      }

      printf("\n");
   }
}

void add() {
   LoopVar i, j;

   struct Matrix first;
   struct Matrix second;
   struct Matrix result;

   printf("Enter the dimensions of the matrices (rows columns): ");
   scanf("%d%d", &first.dimensions.row, &first.dimensions.col);

   second.dimensions = first.dimensions;
   result.dimensions = first.dimensions;

   first.matrix = (IntArr**) malloc(first.dimensions.row * sizeof(IntArr*));
   second.matrix = (IntArr**) malloc(second.dimensions.row * sizeof(IntArr*));
   result.matrix = (IntArr**) malloc(result.dimensions.row * sizeof(IntArr*));

   if (first.matrix == NULL || second.matrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < first.dimensions.row; i++) {
      first.matrix[i] = (int*) malloc(first.dimensions.col * sizeof(int));
      second.matrix[i] = (int*) malloc(second.dimensions.col * sizeof(int));
      result.matrix[i] = (int*) malloc(result.dimensions.col * sizeof(int));

      if (first.matrix[i] == NULL || second.matrix[i] == NULL || result.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   initMatrices(&first, &second);

   for (i = 0; i < result.dimensions.row; i++) {
      for (j = 0; j < result.dimensions.col; j++) {
         result.matrix[i][j] = first.matrix[i][j] + second.matrix[i][j];
      }
   }

   printf("Matrix 1: \n");
   printMatrix(first);

   printf("\nMatrix 2: \n");
   printMatrix(second);

   printf("\nResult matrix: \n");
   printMatrix(result);

   printf("\n");

   for (i = 0; i < first.dimensions.row; i++) {
      free(first.matrix[i]);
      free(second.matrix[i]);
      free(result.matrix[i]);
   }

   free(first.matrix);
   free(second.matrix);
   free(result.matrix);
}

void subtract() {
   LoopVar i, j;

   struct Matrix first;
   struct Matrix second;
   struct Matrix result;

   printf("Enter the dimensions of the matrix (rows columns): ");
   scanf("%d%d", &first.dimensions.row, &first.dimensions.col);

   second.dimensions = first.dimensions;
   result.dimensions = first.dimensions;

   first.matrix = (IntArr**) malloc(first.dimensions.row * sizeof(IntArr*));
   second.matrix = (IntArr**) malloc(second.dimensions.row * sizeof(IntArr*));
   result.matrix = (IntArr**) malloc(result.dimensions.row * sizeof(IntArr*));

   if (first.matrix == NULL || second.matrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < first.dimensions.row; i++) {
      first.matrix[i] = (int*) malloc(first.dimensions.col * sizeof(int));
      second.matrix[i] = (int*) malloc(second.dimensions.col * sizeof(int));
      result.matrix[i] = (int*) malloc(result.dimensions.col * sizeof(int));

      if (first.matrix[i] == NULL || second.matrix[i] == NULL || result.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   initMatrices(&first, &second);

   for (i = 0; i < result.dimensions.row; i++) {
      for (j = 0; j < result.dimensions.col; j++) {
         result.matrix[i][j] = first.matrix[i][j] - second.matrix[i][j];
      }
   }

   printf("Matrix 1: \n");
   printMatrix(first);

   printf("\nMatrix 2: \n");
   printMatrix(second);

   printf("\nResult matrix: \n");
   printMatrix(result);

   printf("\n");

   for (i = 0; i < first.dimensions.row; i++) {
      free(first.matrix[i]);
      free(second.matrix[i]);
      free(result.matrix[i]);
   }

   free(first.matrix);
   free(second.matrix);
   free(result.matrix);
}


void multiply() {
   LoopVar i, j, k, l;

   struct Matrix first;
   struct Matrix second;
   struct Matrix result;

   printf("Enter the number of rows in first matrix: ");
   scanf("%d", &first.dimensions.row);

   printf("Enter the number of columns in first matrix (equal to rows in second matrix): ");
   scanf("%d", &first.dimensions.col);

   printf("Enter the number of columns in second matrix: ");
   scanf("%d", &second.dimensions.col);

   second.dimensions.row = first.dimensions.col;
   result.dimensions.row = first.dimensions.row;
   result.dimensions.col = second.dimensions.col;

   first.matrix = (IntArr**) malloc(first.dimensions.row * sizeof(IntArr*));
   second.matrix = (IntArr**) malloc(second.dimensions.row * sizeof(IntArr*));
   result.matrix = (IntArr**) malloc(result.dimensions.row * sizeof(IntArr*));

   if (first.matrix == NULL || second.matrix == NULL || result.matrix == NULL) {
      printf("Data allocation failed\n");

      exit(0);
   }

   for (i = 0; i < first.dimensions.row; i++) {
      first.matrix[i] = (int*) malloc(first.dimensions.col * sizeof(int));

      if (first.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   for (i = 0; i < second.dimensions.row; i++) {
      second.matrix[i] = (int*) malloc(second.dimensions.col * sizeof(int));

      if (second.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   for (i = 0; i < result.dimensions.row; i++) {
      result.matrix[i] = (int*) malloc(result.dimensions.col * sizeof(int));

      if (result.matrix[i] == NULL) {
         printf("Data allocation failed\n");

         exit(0);
      }
   }

   initMatrices(&first, &second);

   for (i = 0; i < result.dimensions.row; i++) {
      for (j = 0; j < result.dimensions.col; j++) {
         result.matrix[i][j] = 0;
      }
   }

   for (i = 0; i < first.dimensions.row; i++) {
      for (j = 0; j < second.dimensions.col; j++) {
         for (k = 0, l = 0;
              k < first.dimensions.col || l < second.dimensions.row;
              k++, l++) {
            result.matrix[i][j] += first.matrix[i][k] * second.matrix[l][j];
         }
      }
   }

   printf("Matrix 1: \n");
   printMatrix(first);

   printf("\nMatrix 2: \n");
   printMatrix(second);

   printf("\nResult matrix: \n");
   printMatrix(result);

   printf("\n");

   for (i = 0; i < first.dimensions.row; i++) {
      free(first.matrix[i]);
      free(second.matrix[i]);
      free(result.matrix[i]);
   }

   free(first.matrix);
   free(second.matrix);
   free(result.matrix);
}
