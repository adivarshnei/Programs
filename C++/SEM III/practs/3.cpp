// Write a program to perform matrix algebra operations: Addition, Subtraction,
// Multiplication, Transpose.

#include <iostream>
#include <stdlib.h>
#include <time.h>

#define ELEM_LIMIT 20

using namespace std;

typedef int LoopVar;

enum Bool { YES = 1, NO = 2 };

struct MatrixSize {
   int rows;
   int cols;
};

struct Matrix {
   int** matrix;
   MatrixSize size;
};

int shouldRepeat;

void initMatrix(Matrix& m) {
   for (LoopVar i = 0; i < m.size.rows; i++) {
      for (LoopVar j = 0; j < m.size.cols; j++) {
         m.matrix[i][j] = rand() % ELEM_LIMIT;
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
   Matrix matrix1, matrix2;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   matrix1.size = matrix2.size = result.size = {rows, cols};

   matrix1.matrix = new int*[matrix1.size.rows];
   matrix2.matrix = new int*[matrix2.size.rows];
   result.matrix = new int*[result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      matrix1.matrix[i] = new int[matrix1.size.cols];
      matrix2.matrix[i] = new int[matrix2.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }

   initMatrix(matrix1);
   cout << "Matrix 1: " << endl;
   printMatrix(matrix1);

   system("pause");

   initMatrix(matrix2);
   cout << "Matrix 2: " << endl;
   printMatrix(matrix2);

   system("pause");

   for (LoopVar i = 0; i < matrix1.size.rows; i++) {
      for (LoopVar j = 0; j < matrix1.size.cols; j++) {
         result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete *matrix1.matrix;
   delete *matrix2.matrix;
   delete *result.matrix;
}

void subMatrix() {
   int rows, cols;
   Matrix matrix1, matrix2;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   matrix1.size = matrix2.size = result.size = {rows, cols};

   matrix1.matrix = new int*[matrix1.size.rows];
   matrix2.matrix = new int*[matrix2.size.rows];
   result.matrix = new int*[result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      matrix1.matrix[i] = new int[matrix1.size.cols];
      matrix2.matrix[i] = new int[matrix2.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }

   initMatrix(matrix1);
   cout << "Matrix 1:" << endl;
   printMatrix(matrix1);

   system("pause");

   initMatrix(matrix2);
   cout << "Matrix 2:" << endl;
   printMatrix(matrix2);

   system("pause");

   for (LoopVar i = 0; i < matrix1.size.rows; i++) {
      for (LoopVar j = 0; j < matrix1.size.cols; j++) {
         result.matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete *matrix1.matrix;
   delete *matrix2.matrix;
   delete *result.matrix;
}

void multMatrix() {
   int rows1, cols1rows2, cols2;
   Matrix matrix1, matrix2;
   Matrix result;

   cout << "Enter number of rows of first matrix: ";
   cin >> rows1;
   cout << "Enter number of columns of first matrix (will be taken as number "
        << "of rows of second matrix): ";
   cin >> cols1rows2;

   cout << "Enter number of columns of second matrix: ";
   cin >> cols2;

   matrix1.size = {rows1, cols1rows2};
   matrix2.size = {cols1rows2, cols2};
   result.size = {rows1, cols2};

   matrix1.matrix = new int*[matrix1.size.rows];
   matrix2.matrix = new int*[matrix2.size.rows];
   result.matrix = new int*[result.size.rows];

   for (LoopVar i = 0; i < matrix1.size.rows; i++) {
      matrix1.matrix[i] = new int[matrix1.size.cols];
      result.matrix[i] = new int[result.size.cols];
   }

   for (LoopVar i = 0; i < matrix2.size.rows; i++) {
      matrix2.matrix[i] = new int[matrix2.size.cols];
   }

   initMatrix(matrix1);
   cout << "Matrix 1: " << endl;
   printMatrix(matrix1);

   system("pause");

   initMatrix(matrix2);
   cout << "Matrix 2" << endl;
   printMatrix(matrix2);

   system("pause");

   for (LoopVar i = 0; i < result.size.rows; i++) {
      for (LoopVar j = 0; j < result.size.cols; j++) {
         result.matrix[i][j] = 0;
      }
   }

   for (LoopVar i = 0; i < matrix1.size.rows; i++) {
      for (LoopVar j = 0; j < matrix2.size.cols; j++) {
         for (LoopVar k = 0; k < matrix2.size.rows; k++) {
            result.matrix[i][j] += matrix1.matrix[i][k] * matrix2.matrix[k][j];
         }
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete *matrix1.matrix;
   delete *matrix2.matrix;
   delete *result.matrix;
}

void transMatrix() {
   int rows, cols;
   Matrix matrix;
   Matrix result;

   cout << "Enter number of rows of matrix: ";
   cin >> rows;
   cout << "Enter number of columns of matrix: ";
   cin >> cols;

   matrix.size = {rows, cols};
   result.size = {cols, rows};

   matrix.matrix = new int*[matrix.size.rows];
   result.matrix = new int*[result.size.rows];

   for (LoopVar i = 0; i < rows; i++) {
      matrix.matrix[i] = new int[matrix.size.cols];
   }

   for (LoopVar i = 0; i < cols; i++) {
      result.matrix[i] = new int[matrix.size.cols];
   }

   initMatrix(matrix);
   cout << "Matrix: " << endl;
   printMatrix(matrix);

   system("pause");

   for (LoopVar i = 0; i < matrix.size.rows; i++) {
      for (LoopVar j = 0; j < matrix.size.cols; j++) {
         result.matrix[j][i] = matrix.matrix[i][j];
      }
   }

   cout << "Result: " << endl;
   printMatrix(result);

   delete *matrix.matrix;
   delete *result.matrix;
}

int main(void) {
   system("cls");
   srand(time(NULL));

   while (1) {
      int choice;

      do {
         cout << "1. Addition" << endl;
         cout << "2. Subtraction" << endl;
         cout << "3. Multiplication" << endl;
         cout << "4. Transpose" << endl;
         cout << "5. Exit" << endl;
         cout << "Enter Choice: ";
         cin >> choice;

         switch (choice) {
         case 1:
            addMatrix();
            break;

         case 2:
            subMatrix();
            break;

         case 3:
            multMatrix();
            break;

         case 4:
            transMatrix();
            break;

         case 5:
            break;

         default:
            cout << "Wrong Option Entered" << endl;
            break;
         }
      } while (choice != 5);

      cout << endl << "Repeat Program? (1 = YES): ";
      cin >> shouldRepeat;
      cin.ignore(256, '\n');

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
