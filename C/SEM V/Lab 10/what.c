// N-Queens Problem

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

int** board_init(int len);
void  board_dealloc(int** board, int len);
void  matrix_print(int** board, int len);

int
main(int argc, char** argv) {
    int   len   = N;
    int** board = board_init(len);

    matrix_print(board, len);

    board_dealloc(board, len);

    return 0;
}

int**
board_init(int len) {
    int** board = ( int** ) malloc(len * sizeof(int));

    for ( int i = 0; i < len; i++ ) {
        board[i] = ( int* ) malloc(len * sizeof(int));

        for ( int j = 0; j < len; j++ ) {
            board[i][j] = 0;
        }
    }

    return board;
}

void
board_dealloc(int** board, int len) {
    for ( int i = 0; i < len; i++ ) {
        free(board[i]);
    }

    free(board);
}

void
matrix_print(int** board, int len) {
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            fprintf(stdout, "%3d", board[i][j]);
        }

        fprintf(stdout, "\n");
    }
}