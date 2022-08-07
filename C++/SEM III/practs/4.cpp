// Write a program to read a matrix of size m x n from the keyboard and display
// the same on the screen using functions.

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

int main(void) {
   system("cls");

   while (1) {
      int m, n;
      int** matrix;

      cout << "Enter number of rows of matrix: ";
      cin >> m;
      cout << "Enter number of columns of matrix: ";
      cin >> n;

      matrix = new int*[m];

      for (LoopVar i = 0; i < m; i++) {
         matrix[i] = new int[n];
      }

      inputMatrix(matrix, m, n);
      printMatrix(matrix, m, n);

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
