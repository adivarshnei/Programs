#include <stdio.h>

void
swap(int* a, int* b) {
    int temp = *a;
    *a       = *b;
    *b       = temp;
}

int
main() {
    int A[50];
    int i, j, k, l, n, smallest;

    printf("\n Enter no. of elements in Array: ");
    scanf("%d", &n);
    printf("\n Enter Array elements: ");
    for ( k = 0; k < n; k++ ) {
        scanf("%d", &A[k]);
    }

    printf("\n Selection Sort");

    for ( j = 0; j < n - 1; j++ )  // Swapping
    {
        smallest = j;
        for ( i = j + 1; i <= n; i++ )  // Comparison
        {
            if ( A[i] < A[smallest] )
                smallest = i;
        }
        swap(&A[smallest], &A[j]);
    }
    printf("\n Sorted Array via Selection Sort is: ");
    for ( l = 0; l < n; l++ ) {
        printf("%d", A[l]);
    }
}