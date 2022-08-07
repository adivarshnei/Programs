#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int LoopVar;
typedef char BufferClear;
typedef char String;

enum Bool {
   TRUE = 1,
   FALSE = 0
};

String* decToBin(int);
String* revString(String*);

BufferClear temp;
enum Bool shouldRepeat;

int main(void) {
   int decimal;
   String* binary;

   system("cls");

   printf("Enter the decimal number: ");
   scanf("%d", &decimal);

   binary = decToBin(decimal);

   if (binary != NULL) {
      printf("%d in decimal is %s in binary\n", decimal, binary);
   }

   printf("\nRepeat Program? (1 = YES): ");
   scanf("%d", &shouldRepeat);
   scanf("%c", &temp);

   (shouldRepeat == TRUE) ? main() : printf("\nEND");
}

String* decToBin(int num) {
   static String binary[50];
   int binaryIndex = 0;

   if (num < 0) {
      printf("Invalid number");
      return NULL;
   } else if (num == 0) {
      return "0";
   }

   while (num > 0) {
      binary[binaryIndex] = num % 2 + '0';
      num /= 2;
      binaryIndex++;
   }

   revString(binary);
   binary[binaryIndex] = '\0';

   return binary;
}

String* revString(String str[]) {
   int temp;
   LoopVar i, j;

   for (i = strlen(str) - 1, j = 0; i > j; i--, j++) {
      temp = str[j];
      str[j] = str[i];
      str[i] = temp;
   }
}