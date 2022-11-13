// 10. Write a program to solve the N-Queens Problem using Backtracking Approach

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_STR argv[1]

struct Position {
    int  x;
    int  y;
    bool active;
};

int** board_init(struct Position const* positions, int const len);
void  board_dealloc(int** board, int const len);
void  matrix_print(int** board, int const len);
bool  place_check(int const i, int const j, int const k, int const l);
bool  check_valid(struct Position const* positions, int const len);
int   n_queen_init(int const len);
void  n_queen(struct Position* positions,
              int const        row,
              int const        len,
              int*             solncount);

int
main(int argc, char** argv) {
    if ( argc != 2 ) {
        return 0;
    }

    int len = atoi(N_STR);

    fprintf(stdout, "Solution boards for %d-queen problem:\n", len);
    int solncount = n_queen_init(len);
    fprintf(stdout, "Number of solutions with %d queens: %d\n", len, solncount);

    return 0;
}

int**
board_init(struct Position const* positions, int const len) {
    int** board = ( int** ) malloc(len * sizeof(int*));

    for ( int i = 0; i < len; i++ ) {
        board[i] = ( int* ) malloc(len * sizeof(int));

        for ( int j = 0; j < len; j++ ) {
            board[i][j] = 0;
        }
    }

    for ( int i = 0; i < len; i++ ) {
        board[positions[i].x][positions[i].y] = 1;
    }

    return board;
}

void
board_dealloc(int** board, int const len) {
    for ( int i = 0; i < len; i++ ) {
        free(board[i]);
    }

    free(board);
}

void
matrix_print(int** board, int const len) {
    for ( int i = -1; i < len * 4; i++ ) {
        fprintf(stdout, "-");
    }

    fprintf(stdout, "\n");

    for ( int i = 0; i < len; i++ ) {
        for ( int j = 0; j < len; j++ ) {
            fprintf(stdout, "| %c ", (board[i][j] == 1) ? 'Q' : ' ');
        }

        fprintf(stdout, "|\n");

        for ( int i = -1; i < len * 4; i++ ) {
            fprintf(stdout, "-");
        }

        fprintf(stdout, "\n");
    }
}

bool
place_check(int const i, int const j, int const k, int const l) {
    if ( i == k ) {
        return false;
    } else if ( j == l ) {
        return false;
    } else if ( (i + j) == (k + l) ) {
        return false;
    } else if ( (i - j) == (k - l) ) {
        return false;
    }

    return true;
}

bool
check_valid(struct Position const* positions, int const elements) {
    for ( int i = 0; i < elements; i++ ) {
        struct Position p1 = positions[i];

        for ( int j = i + 1; j < elements; j++ ) {
            struct Position p2 = positions[j];

            if ( p2.active == false && elements == 1 ) {
                return true;
            }

            if ( place_check(p1.x, p1.y, p2.x, p2.y) == false ) {
                return false;
            }
        }
    }

    return true;
}

int
n_queen_init(int const len) {
    int              row       = 0;
    int              solncount = 0;
    struct Position* positions =
        ( struct Position* ) calloc(len, sizeof(struct Position));

    n_queen(positions, row, len, &solncount);
    free(positions);

    return solncount;
}

void
n_queen(struct Position* positions,
        int const        row,
        int const        len,
        int*             solncount) {
    for ( int i = 0; i < len; i++ ) {
        positions[row].x      = row;
        positions[row].y      = i;
        positions[row].active = true;

        if ( check_valid(positions, row + 1) == true ) {
            if ( row < len - 1 ) {
                n_queen(positions, row + 1, len, solncount);
            } else {
                int** board = board_init(positions, len);
                matrix_print(board, len);

                (*solncount) += 1;

                board_dealloc(board, len);
            }
        }

        positions[row].active = false;
    }
}
