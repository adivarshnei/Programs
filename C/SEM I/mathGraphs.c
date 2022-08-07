#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 180
#define PI 3.14

typedef unsigned int LoopVar;
typedef char BufferClear;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

void barGraph();
int* genExpArr();
int* genSqrtArr();
int* genRandArr();
int* genSinSqArr();

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   system("cls");

   barGraph(genExpArr());
   barGraph(genSqrtArr());
   barGraph(genRandArr());
   barGraph(genSinSqArr());

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

int* genExpArr() {
   static int a[LEN];
   LoopVar i;

   for (i = 0; i < LEN; i++) {
      a[i] = (int) (exp(((float) i + 1.0) / ((float) LEN / 2.0)) * 8.0 - 4.0);
   }

   return a;
}

int* genSqrtArr() {
   static int a[LEN];
   LoopVar i;

   for (i = 0; i < LEN; i++) {
      a[i] = (int) (sqrt(((float) i)) * 4.0);
   }

   return a;
}

int* genRandArr() {
   static int b[LEN];
   LoopVar i;

   for (i = 0; i < LEN; i++) {
      b[i] = rand() % 20 + 1;
   }

   return b;
}

int* genSinSqArr() {
   static int b[LEN];
   LoopVar i;

   for (i = 0; i < LEN; i++) {
      b[i] = (int) (sin(((float) i + 1.0) * 2 * PI / (120.0)) * sin(((float) i + 1.0) * 2 * PI / (120.0)) * 50.0);
   }

   return b;
}

void barGraph(int a[LEN]) {
   int max;
   LoopVar i, j;

   max = a[0];

   for (i = 1; i < LEN; i++) {
      if (a[i] > max) {
         max = a[i];
      }
   }

   for (i = 0; i < max; i++) {
      for (j = 0; j < LEN; j++) {
         if (a[j] >= max - i) {
            printf("*");
         } else {
            printf(" ");
         }
      }
      printf("\n");
   }

   for (i = 0; i < LEN; i++) {
      printf("%d ", a[i]);
   }
   
   printf("\n");
}
