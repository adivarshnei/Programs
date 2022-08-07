// Matrix Multiplication

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef char bufferClear;
typedef int intMatrix;

int count = 0;
bufferClear temp;

int main(void) {
  loopVar rep = 1;

  while (rep == 1) {
    intMatrix matrixA[50][50], matrixB[50][50];
    intMatrix mulMatrix[50][50];
    loopVar i, j, k;
    int rowA, colArowB, colB;

    printf("Enter the number of rows in A: ");
    scanf("%d", &rowA);

    printf("Enter the number of columns in A (will be taken as number of rows "
           "in B: ");
    scanf("%d", &colArowB);

    printf("Enter the number of columns in B: ");
    scanf("%d", &colB);

    for (i = 0; i < 50; i++) {
      for (j = 0; j < 50; j++) {
        matrixA[i][j] = 0;
        matrixB[i][j] = 0;
        mulMatrix[i][j] = 0;
      }
    }

    printf("Enter matrix A:\n");

    for (i = 0; i < rowA; i++) {
      for (j = 0; j < colArowB; j++) {
        printf("Enter element [%d][%d]: ", i, j);
        scanf("%d", &matrixA[i][j]);
      }
    }

    printf("Enter matrix B:\n");

    for (i = 0; i < colArowB; i++) {
      for (j = 0; j < colB; j++) {
        printf("Enter element [%d][%d]: ", i, j);
        scanf("%d", &matrixB[i][j]);
      }
    }

    for (i = 0; i < rowA; i++) {
      for (j = 0; j < colB; j++) {
        for (k = 0; k < (rowA > colB ? rowA : colB); k++) {
          mulMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
        }
      }
    }

    printf("Matrix A:\n");

    for (i = 0; i < rowA; i++) {
      for (j = 0; j < colArowB; j++) {
        printf("%d\t", matrixA[i][j]);
      }

      printf("\n");
    }

    printf("Matrix B:\n");

    for (i = 0; i < colArowB; i++) {
      for (j = 0; j < colB; j++) {
        printf("%d\t", matrixB[i][j]);
      }

      printf("\n");
    }

    printf("Resultant matrix:\n");

    for (i = 0; i < rowA; i++) {
      for (j = 0; j < colB; j++) {
        printf("%d\t", mulMatrix[i][j]);
      }

      printf("\n");
    }

    printf("\nRepeat Program?: ");
    scanf("%d", &rep);
    scanf("%c", &temp);

    count++;

    if (count >= 15) {
      printf("Abnormal END\n");

      getch();
      exit(0);
    } // if (count >= 15)
  }   // while (rep == 1)

  printf("Normal END\n");

  getch();
  return 0;
} // int main(void)

/*Recursive Factorial

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef char bufferClear;

long int factorial(long int);

int count = 0;
bufferClear temp;

int main(void) {
        loopVar rep = 1;

        while (rep == 1) {
                int num;
                long int fact;

                printf("Enter the number: ");
                scanf("%d", &num);

                fact=factorial(num);

                printf("%d! = %ld", num, fact);

                printf("\nRepeat Program?: ");
                scanf("%d", & rep);
                scanf("%c", & temp);

                count++;

                if (count >= 15) {
                        printf("Abnormal END\n");

                        getch();
                        exit(0);
                } //if (count >= 15)
        } //while (rep == 1)

        printf("Normal END\n");

        getch();
        return 0;
} //int main(void)

long int factorial(long int num) {
        if (num == 1) {
                return 1;
        } else {
                return num * factorial(num - 1);
        }
}*/

/*Appending data to text file.
Reading data before and after

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

int count = 0;
bufferClear temp;

int main(void) {
        loopVar rep = 1;

        while (rep == 1) {
                FILE * f1;
                string inpString[20];
                loopVar i;
                char charac;

                f1 = fopen("file.txt", "a+");

                printf("File before appending:\n");

                while ((charac = getc(f1)) != EOF) {
                        printf("%c", charac);
                }

                fclose(f1);
                f1 = fopen("file.txt", "a+");

                printf("\n\nEnter the string: ");
                gets(inpString);

                fprintf(f1, inpString);

                fclose(f1);
                f1 = fopen("file.txt", "a+");

                printf("File after appending:\n");

                while ((charac = getc(f1)) != EOF) {
                        printf("%c", charac);
                }

                fclose(f1);

                printf("\nRepeat Program?: ");
                scanf("%d", & rep);
                scanf("%c", & temp);

                count++;

                if (count >= 15) {
                        printf("Abnormal END\n");

                        getch();
                        exit(0);
                } //if (count >= 15)
        } //while (rep == 1)

        printf("Normal END\n");

        getch();
        return 0;
} //int main(void)

*/

/* Swapping a number without third variable

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef char bufferClear;

int count = 0;
bufferClear temp;

int main(void) {
        loopVar rep = 1;

        while (rep == 1) {
                int num1, num2;

                printf("Enter the first number: ");
                scanf("%d", & num1);

                printf("Enter the second number: ");
                scanf("%d", & num2);

                num1 = num1 + num2;
                num2 = num1 - num2;
                num1 = num1 - num2;

                printf("Number 1: %d\nNumber 2: %d\n", num1, num2);

                printf("\nRepeat Program?: ");
                scanf("%d", & rep);
                scanf("%c", & temp);

                count++;

                if (count >= 15) {
                        printf("Abnormal END\n");

                        getch();
                        exit(0);
                } //if (count >= 15)
        } //while (rep == 1)

        printf("Normal END\n");

        getch();
        return 0;
} //int main(void)
*/

/*Concatenation of strings without strcat()

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int loopVar;
typedef char bufferClear;
typedef char string;

void stringCat(string * , string * , string * );

int count = 0;
bufferClear temp;

int main(void) {
        loopVar rep = 1;

        while (rep == 1) {
                string s1[50], s2[50], catStr[100];

                printf("Enter the first string: ");
                gets(s1);

                printf("Enter the second string: ");
                gets(s2);

                stringCat(s1, s2, catStr);

                printf("The concatenated string is: %s\n", catStr);

                printf("\nRepeat Program?: ");
                scanf("%d", & rep);
                scanf("%c", & temp);

                count++;

                if (count >= 15) {
                        printf("Abnormal END\n");

                        getch();
                        exit(0);
                } //if (count >= 15)
        } //while (rep == 1)

        printf("Normal END\n");

        getch();
        return 0;
} //int main(void)

void stringCat(string * s1, string * s2, string * catStr) {
        loopVar i;

        for (i = 0; i < strlen(s1); i++) {
                catStr[i] = s1[i];
        }

        for (i = 0; i < strlen(s2); i++) {
                catStr[i + strlen(s1)] = s2[i];
        }
}*/
