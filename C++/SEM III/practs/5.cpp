// Rewrite Experiment 4, to make row parameter of hte matrix as a default
// argument

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int LoopVar;

int shouldRepeat;

void inputMatrix(int** matrix, int m, int n) {
   for (LoopVar i = 0; i < m; i++) {
      for (LoopVar j = 0; j < n; j++) {
         cout << "Enter element[" << i << "][" << j << "]: ";
         cin >> matrix[i][j];
      }
   }
}

void printMatrix(int** matrix, int m, int n) {
   for (LoopVar i = 0; i < m; i++) {
      for (LoopVar j = 0; j < n; j++) {
         cout << matrix[i][j] << "\t";
      }

      cout << endl;
   }
}

void matrixFunctions(int** matrix, int n, int m = 3) {
   matrix = new int*[m];

   for (LoopVar i = 0; i < m; i++) {
      matrix[i] = new int[n];
   }

   inputMatrix(matrix, m, n);
   printMatrix(matrix, m, n);
}

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
