/*
Q5. Rewrite the program of Q4. to make the row parameter of the matrix as a
default argument.
*/

#include <iostream.h>
#include <stdlib.h>

typedef int LoopVar;

void matrixFunctions(int**, int, int m = 3);
void inputMatrix(int**, int, int);
void printMatrix(int**, int, int);

int shouldRepeat;

int main(void) {
   system("cls");

   while (1) {
      int m, n;
      int** matrix;

      int choice;

      cout << "Enter number of columns of matrix: ";
      cin >> n;

      cout << "Do you want to enter rows of matrix? (1 = YES): ";
      cin >> choice;

      if (choice == 1) {
         cout << "Enter number of rows of matrix: ";
         cin >> m;

         matrixFunctions(matrix, n, m);
      } else {
         matrixFunctions(matrix, n);
      }

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

void matrixFunctions(int** matrix, int n, int m) {
   matrix = new int* [m];

   for (LoopVar i = 0; i < m; i++) {
      matrix[i] = new int[n];
   }

   inputMatrix(matrix, m, n);
   printMatrix(matrix, m, n);
}

void inputMatrix(int** matrix, int m, int n) {
   for (LoopVar i = 0; i < m; i++) {
      for (LoopVar j = 0; j < n; j++) {
         cout << "Enter element [" << i << "][" << j << "]: ";
         cin >> matrix[i][j];
      }
   }
}

void printMatrix(int** matrix, int m, int n) {
   cout << "Given matrix is: " << endl;

   for (LoopVar i = 0; i < m; i++) {
      for (LoopVar j = 0; j < n; j++) {
         cout << matrix[i][j] << "\t";
      }

      cout << endl;
   }
}