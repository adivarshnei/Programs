#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 5;

float
min(float x, float y) {
    if ( x < y )
        return x;
    else
        return y;
}

void
printmat(float W[][10]) {
    int i, j;
    printf("\n");
    for ( i = 0; i <= n; i++ ) {
        for ( j = 0; j <= n; j++ ) {
            if ( W[i][j] == INFINITY ) {
                printf(" ");
                // printf("%lc",
                // ( wint_t ) 236);  // Alternate Code for infinity symbol
                printf("I");
                printf(" ");
            } else
                printf("%2d ", ( int ) W[i][j]);
        }
        printf("\n");
    }
}

void
FW(float W[][10], float D[10][10][10], float P[10][10][10]) {
    int i, j, k;
    for ( i = 1; i <= n; i++ ) {
        for ( j = 1; j <= n; j++ ) {
            if ( (D[0][i][j] == INFINITY) || (D[0][i][j] == 0) )
                P[0][i][j] = -1;  // put parent as -1 for 0 & infinity edges
            else
                P[0][i][j] = i;  // input parent node
        }
    }

    for ( k = 1; k <= n; k++ ) {
        for ( i = 1; i <= n; i++ ) {
            for ( j = 1; j <= n; j++ ) {
                D[k][i][j] =
                    min(D[k - 1][i][j], D[k - 1][i][k] + D[k - 1][k][j]);
                if ( D[k][i][j] != D[k - 1][i][j] )
                    P[k][i][j] = k;
            }
        }
    }
    printf("\n Final D matrix: ");
    printmat(D[4]);
    printf("\n Final Path matrix: ");
    printmat(P[4]);
}

void
sequence(float P[10][10][10], int start, int end) {
    int parent = ( int ) P[4][start][end];
    if ( parent != start ) {
        sequence(P, start, parent);
        sequence(P, parent, end);
    } else
        printf(" %d -> ", end);
}

void
finalpath(float P[10][10][10], int start, int end) {
    printf("\n Final Path from %d to %d is: ", start, end);
    printf("\n");
    printf("%d -> ", start);
    sequence(P, start, end);
}

int
main() {
    int   i, j, k;
    float y = INFINITY;
    float start, end;
    float W[10][10] = {
        {0, 1, 2,  3, 4,  5},
        {1, 0, 3,  8, y, -4},
        {2, 4, 0,  y, 1,  7},
        {3, y, 4,  0, y,  y},
        {4, 2, y, -5, 0,  y},
        {5, y, y,  y, 6,  0}
    };
    printf("\n Initial Adjacency matrix: ");
    printmat(W);

    float D[10][10][10] = { 0 };  // Edges matrix that contains min. cost
    float P[10][10][10] = { 0 };  // Path matrix that contains Parent nodes

    for ( k = 0; k <= n; k++ ) {
        for ( i = 0; i <= n; i++ ) {
            P[k][0][i] = P[k][i][0] = i;
            D[k][0][i] = D[k][i][0] = i;
        }
    }

    FW(W, D, P);

    for ( i = 1; i <= n; i++ ) {
        for ( j = 1; j <= n; j++ ) {
            if ( i != j ) {
                start = i;
                end   = j;
                finalpath(P, start, end);  // To give sequence acc to P matrix
            }
        }
    }

    return 0;
}