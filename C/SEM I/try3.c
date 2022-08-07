#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef unsigned int loopVar;
typedef int intArr;

enum Bool {
   YES = 1,
   NO = 2
};

struct elemIndex {
   int small;
   int large;
};

struct elemIndex indexFinder( intArr[10] );

char bufferClear;

int main( void ) {
   struct elemIndex indices;
   intArr arr[10];

   loopVar i;
   enum Bool repeat;

   system( "cls" );

   printf( "Enter the ten integers: " );

   for (i = 0; i < 10; i++) {
      scanf( "%d", &arr[i] );
   }

   indices = indexFinder( arr );

   printf(
      "Smallest Element of array %d is at index %d\n",
      arr[indices.small],
      indices.small
   );
   printf(
      "Largest Element of array %d is at index %d\n",
      arr[indices.large],
      indices.large
   );

   printf( "\nRepeat Program? (1 = YES): " );
   scanf( "%d", &repeat );
   scanf( "%c", &bufferClear );


   (repeat == YES) ?
      main() :
      printf( "\nEND" );

   getch();
}

struct elemIndex indexFinder( intArr arr[10] ) {
   struct elemIndex indices;
   loopVar i;

   indices.small = 0;
   indices.large = 0;

   for (i = 0; i < 10; i++) {
      if (arr[i] < arr[indices.small]) {
         indices.small = i;
      }

      if (arr[i] > arr[indices.large]) {
         indices.large = i;
      }
   }

   return indices;
}