#include <stdio.h>
#include <stdlib.h>

struct Node {
   struct Node* prev;
   int data;
   struct Node* next;
};

struct Node* start = NULL;
struct Node* start1 = NULL;
struct Node* start2 = NULL;
struct Node* current;
struct Node* NN;
struct Node* temp1;
struct Node* temp2;
struct Node* temp3;

void display(int type) {
   if (type == 1) {
      temp1 = start1;
   } else if (type == 2) {
      temp1 = start2;
   }

   while (temp1 != NULL) {
      printf("%d->", temp1->data);
      temp1 = temp1->next;
      system("pause");
   }

   printf("NULL\n");
}

void create(int type) {
   int ch, val;

   do {
      printf("Enter the no: ");
      scanf("%d", &val);

      NN = (struct Node*)malloc(sizeof(struct Node));

      NN->data = val;
      NN->prev = NULL;
      NN->next = NULL;

      if (start == NULL) {
         start = NN;
         current = NN;
      } else {
         current->next = NN;
         NN->prev = current;
         current = NN;
      }

      printf("NN:      %d, %d, %d\n", NN->prev, NN->data, NN->next);
      printf("start:   %d, %d, %d\n", start->prev, start->data, start->next);
      printf("current: %d, %d, %d\n", current->prev, current->data,
             current->next);

      printf("\nPress 0 to stop");
      scanf("%d", &ch);
   } while (ch != 0);

   if (type == 1) {
      start1 = start;
   } else if (type == 2) {
      start2 = start;
   }

   // printf("start:   %d, %d, %d\n", start1->prev, start1->data, start1->next);
   // printf("start:   %d, %d, %d\n", start2->prev, start2->data, start2->next);
}

void concat() {
   temp1 = start1;

   while (temp1->next != NULL) {
      temp1 = temp1->next;
   }

   temp1->next = start2;
   start2->prev = temp1;
}

void count() {
   int nonZero = 0;
   temp1 = start1;

   while (temp1->next != start1) {
      if (temp1->data != 0) {
         nonZero++;
      }

      temp1 = temp1->next;
   }

   printf("Number of nonzero values: %d", nonZero);
}

void print3rdLast() {
   printf("3rd Last Elem: %d", start1->prev->prev->prev->data);
}
// void avgCalc() {
//    int sum = 0;
//    int nodes = 0;
//    float avg;
//
//    temp1 = start;
//
//    while (temp1 != NULL) {
//       nodes++;
//       sum += temp1->data;
//       temp1 = temp1->next;
//    }
//
//    avg = (float)sum / (float)nodes;
//
//    printf("No of nodes: %d\n", nodes);
//    printf("Total sum:   %d\n", sum);
//    printf("Average:     %.4f\n", avg);
// }

int main(void) {
   printf("List 1: \n");
   create(1);
   display(1);

   printf("List 2: \n");
   create(2);
   display(2);

   concat();
   display(1);

   return 0;
}
