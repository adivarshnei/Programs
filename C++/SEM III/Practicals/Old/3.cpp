/*
Q3. Write a program to perform following operations on matrix using
functions and switch case:
(a) Addition (b) subtraction (c) multiplication (d) transpose
*/

#include <iostream.h>
#include <stdlib.h>

#define MAX_SIZE 15

enum Bool {
   YES = 1,
   NO = 2
};

typedef int LoopVar;

typedef struct MatrixSize {
   int rows;
   int cols;
};

typedef struct Matrix {
   int** matrix;
   MatrixSize size;
};

void initMatrix(Matrix&);
void printMatrix(Matrix&);
void addMatrix();
void subMatrix();
void multMatrix();
void transMatrix();

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int choice;
      Bool isCompleted = NO;

      do {
         cout << "1. Addition" << endl;
         cout << "2. Subtraction" << endl;
         cout << "3. Multiplication" << endl;
         cout << "4. Transpose" << endl;
         cout << "5. Exit" << endl;
         cout << "Enter option: ";
         cin >> choice;

         switch (choice) {
         case 1:
            addMatrix();
            isCompleted = YES;
            break;

         case 2:
            subMatrix();
            isCompleted = YES;
            break;

         case 3:
            multMatrix();
            isCompleted = YES;
            break;

         case 4:
            transMatrix();
            isCompleted = YES;
            break;

         case 5:
            isCompleted = YES;
            break;

         default:
            cout << "Wrong Option Entered" << endl;
            break;
         }
      } while (isCompleted == NO);

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;

      if (shouldRepeat == 1) {
         continue;
      } else {
         cout << endl << "END" << endl;
         break;
      }
   }

   system("pause");
   return 0;
}

void initMatrix(Matrix& m) {
   randomize();

   for (LoopVar i = 0; i < m.size.rows; i++) {
      for (LoopVar j = 0; j < m.size.cols; j++) {
         m.matrix[i][j] = random(MAX_SIZE);
      }
   }
}

void printMatrix(Matrix& m) {
   for (LoopVar i = 0; i < m.size.rows; i++) {
      for (LoopVar j = 0; j < m.size.cols; j++) {
         cout << m.matrix[i][j] << "\t";
      }

      cout << endl;
   }
}

void addMatrix() {
   int rows, cols;
   Matrix m1, m2;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   m1.size.rows = rows;
   m1.size.cols = cols;
   m2.size = m1.size;
   result.size = m1.size;

   m1.matrix = new int* [m1.size.rows];
   m2.matrix = new int* [m2.size.rows];
   result.matrix = new int* [result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      m1.matrix[i] = new int[m1.size.cols];
      m2.matrix[i] = new int[m2.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }

   randomize();
   initMatrix(m1);
   cout << "Matrix 1:" << endl;
   printMatrix(m1);

   system("pause");

   randomize();
   initMatrix(m2);
   cout << "Matrix 2:" << endl;
   printMatrix(m2);

   system("pause");

   for (i = 0; i < m1.size.rows; i++) {
      for (LoopVar j = 0; j < m1.size.cols; j++) {
         result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete* m1.matrix;
   delete* m2.matrix;
   delete* result.matrix;
}

void subMatrix() {
   int rows, cols;
   Matrix m1, m2;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   m1.size.rows = rows;
   m1.size.cols = cols;
   m2.size = m1.size;
   result.size = m1.size;

   m1.matrix = new int* [m1.size.rows];
   m2.matrix = new int* [m2.size.rows];
   result.matrix = new int* [result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      m1.matrix[i] = new int[m1.size.cols];
      m2.matrix[i] = new int[m2.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }

   randomize();
   initMatrix(m1);
   cout << "Matrix 1:" << endl;
   printMatrix(m1);

   system("pause");

   randomize();
   initMatrix(m2);
   cout << "Matrix 2:" << endl;
   printMatrix(m2);

   system("pause");

   for (i = 0; i < m1.size.rows; i++) {
      for (LoopVar j = 0; j < m1.size.cols; j++) {
         result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete* m1.matrix;
   delete* m2.matrix;
   delete* result.matrix;
}

void multMatrix() {
   int rows1, cols1rows2, cols2;
   Matrix m1, m2;
   Matrix result;

   cout << "Enter number of rows of first matrix: ";
   cin >> rows1;
   cout << "Enter number of columns of first matrix (will be taken as " <<
      "number of rows of second matrix): ";
   cin >> cols1rows2;

   cout << "Enter number of columns of second matrix: ";
   cin >> cols2;

   m1.size.rows = rows1;
   m1.size.cols = cols1rows2;
   m2.size.rows = cols1rows2;
   m2.size.cols = cols2;
   result.size.rows = rows1;
   result.size.cols = cols2;

   m1.matrix = new int* [m1.size.rows];
   m2.matrix = new int* [m2.size.rows];
   result.matrix = new int* [result.size.rows];

   for (LoopVar i = 0; i < m1.size.rows; i++) {
      m1.matrix[i] = new int[m1.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }
   for (i = 0; i < m2.size.rows; i++) {
      m2.matrix[i] = new int[m2.size.cols];
   }

   randomize();
   initMatrix(m1);
   cout << "Matrix 1:" << endl;
   printMatrix(m1);

   system("pause");

   randomize();
   initMatrix(m2);
   cout << "Matrix 2:" << endl;
   printMatrix(m2);

   system("pause");

   for (i = 0; i < m1.size.rows; i++) {
      for (LoopVar j = 0; j < m1.size.cols; j++) {
         result.matrix[i][j] = 0;
      }
   }

   for (i = 0; i < m1.size.rows; i++) {
      for (LoopVar j = 0; j < m2.size.cols; j++) {
         for (LoopVar k = 0; k < m2.size.rows; k++) {
            result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
         }
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete* m1.matrix;
   delete* m2.matrix;
   delete* result.matrix;
}

void transMatrix() {
   int rows, cols;
   Matrix m1;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   m1.size.rows = rows;
   m1.size.cols = cols;
   result.size.rows = cols;
   result.size.cols = rows;

   m1.matrix = new int* [m1.size.rows];
   result.matrix = new int* [result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      m1.matrix[i] = new int[m1.size.cols];
   }

   for (i = 0; i < cols; i++) {
      result.matrix[i] = new int[result.size.cols];
   }

   randomize();
   initMatrix(m1);
   cout << "Matrix 1:" << endl;
   printMatrix(m1);

   system("pause");

   for (i = 0; i < m1.size.rows; i++) {
      for (LoopVar j = 0; j < m1.size.cols; j++) {
         result.matrix[j][i] = m1.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete* m1.matrix;
   delete* result.matrix;
}