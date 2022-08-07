#include <stdio.h>
#include <stdlib.h>

#define len(array) sizeof(array) / sizeof(array[0])

enum Bool {
   TRUE  = 1,
   FALSE = 2
};

int refString[] = {
   7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1
};
;

void
printPageStack(int pageStack[], int pageStackSize) {
   for ( int i = 0; i < pageStackSize; i++ ) {
      if ( pageStack[i] != -1 ) {
         fprintf(stdout, "%d ", pageStack[i]);
      }
   }

   fprintf(stdout, "\n");
}

enum Bool
isPresent(int value, int array[], int arraySize) {
   for ( int i = 0; i < arraySize; i++ ) {
      if ( value == array[i] ) {
         return TRUE;
      }
   }

   return FALSE;
}

int
seekIndex(int value, int array[], int arraySize) {
   for ( int i = 0; i < arraySize; i++ ) {
      if ( value == array[i] ) {
         return i;
      }
   }

   return -1;
}

int
fifo(int frames, int refString[], int refStringSize) {
   int  faults       = 0;
   int  replaceCount = 0;
   int* pageStack;

   pageStack = (int*) malloc(frames * sizeof(int));

   for ( int i = 0; i < frames; i++ ) {
      pageStack[i] = -1;
   }

   // fprintf(stdout, "Page Stack Status: \n");

   for ( int i = 0; i < refStringSize; i++ ) {
      if ( isPresent(refString[i], pageStack, frames) == FALSE ) {
         faults++;

         if ( isPresent(-1, pageStack, frames) == TRUE ) {
            pageStack[seekIndex(-1, pageStack, frames)] = refString[i];
         } else {
            pageStack[replaceCount] = refString[i];
            replaceCount            = (replaceCount + 1) % frames;
         }
      }

      // fprintf(stdout, "%d: ", refString[i]);
      // printPageStack(pageStack, frames);
   }

   free(pageStack);

   return faults;
}

int
main(void) {
   fprintf(stdout, "Reference String: ");

   for ( int i = 0; i < len(refString); i++ ) {
      fprintf(stdout, "%d ", refString[i]);
   }

   fprintf(stdout, "\n");

   for ( int i = 1; i < len(refString); i++ ) {
      fprintf(stdout, "Faults caused by %d frames: %d\n", i,
              fifo(i, refString, len(refString)));
   }

   return 0;
}
