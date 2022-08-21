#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50
#define ELEM_LIMIT 10

typedef unsigned int LoopVar;
typedef char         BufferClear;

enum Bool {
    TRUE  = 1,
    FALSE = 0
};

void initArrayValues(int*);
void printArray(int*, int);
void insertElement(int*, int);

BufferClear temp;
enum Bool   shouldRepeat;

int
main(void) {
    static int array[ARRAY_SIZE] = { 0 };

    // system("cls");

    initArrayValues(array);

    printf("\nRepeat Program? (1 = YES): ");
    scanf("%d", &shouldRepeat);
    scanf("%c", &temp);

    (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

void
initArrayValues(int* array) {
    LoopVar i;

    srand(time(NULL));

    for ( i = 0; i < ARRAY_SIZE; i++ ) {
        array[i] = rand() % ELEM_LIMIT;
    }
}

void
printArray(int* array, int size) {
    LoopVar i;

    for ( i = 0; i < size; i++ ) {
        printf("%-4d", array[i]);
    }
}

void
insertElement(int* array, int size) {
    int element;
    int index;

    printf("Enter element: ");
    scanf("%d", &element);

    printf("Enter index: ");
    scanf("%d", &index);
}

// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>
// #include <time.h>

// #define ARRAY_SIZE 50
// #define ELEM_LIMIT 10

// typedef unsigned int LoopVar;
// typedef char BufferClear;

// enum Bool {
//    TRUE = 1,
//    FALSE = 0
// };

// void delay(int);
// void swapVals(int*, int*);
// void initArrayValues(int*);
// void printArray(int*, int);
// enum Bool isSorted(int*);
// void barGraph(int*);
// void bubbleSort(int*);

// BufferClear temp;
// enum Bool shouldRepeat;

// int main(void) {
//    static int array[ARRAY_SIZE] = { 0 };

//    // system("cls");

//    initArrayValues(array);

//    bubbleSort(array);

//    printf("\nRepeat Program? (1 = YES): ");
//    scanf("%d", &shouldRepeat);
//    scanf("%c", &temp);

//    (shouldRepeat == TRUE) ? main() : printf("\nEND");
// }

// void delay(int sec) {
//    clock_t stTime = clock();

//    while (clock() < stTime + sec) { }
// }

// void swapVals(int* val1, int* val2) {
//    int temp;

//    temp = *val1;
//    *val1 = *val2;
//    *val2 = temp;
// }

// void initArrayValues(int* array) {
//    LoopVar i;

//    srand(time(NULL));

//    for (i = 0; i < ARRAY_SIZE; i++) {
//       array[i] = rand() % ELEM_LIMIT;
//    }
// }

// void printArray(int* array, int size) {
//    LoopVar i;

//    for (i = 0; i < size; i++) {
//       printf("%-4d", array[i]);
//    }
// }

// enum Bool isSorted(int* array) {
//    LoopVar i;

//    for (i = 0; i < ARRAY_SIZE - 1; i++) {
//       if (array[i] > array[i + 1]) {
//          return FALSE;
//       }
//    }

//    return TRUE;
// }

// void barGraph(int a[ARRAY_SIZE]) {
//    int max;
//    LoopVar i, j;

//    max = a[0];

//    for (i = 1; i < ARRAY_SIZE; i++) {
//       if (a[i] > max) {
//          max = a[i];
//       }
//    }

//    for (i = 0; i < max; i++) {
//       for (j = 0; j < ARRAY_SIZE; j++) {
//          if (a[j] >= max - i) {
//             printf("*");
//          } else {
//             printf(" ");
//          }
//       }
//       printf("\n");
//    }
// }

// void bubbleSort(int* array) {
//    LoopVar i, j;

//    for (i = 0; i < ARRAY_SIZE - 1; i++) {
//       for (j = 0; j < ARRAY_SIZE - 1 - i; j++) {
//          if (array[j] > array[j + 1]) {
//             swapVals(&array[j], &array[j + 1]);

//             // printArray(array);
//             // printf("\n");
//             delay(1);
//             system("cls");
//             barGraph(array);
//          }
//       }
//    }
// }