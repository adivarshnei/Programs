#include <stdio.h>
#include <stdlib.h>

union Quadrant {
    int            num;
    struct Matrix* matrix;
};

struct Matrix {
    int            len;
    union Quadrant quadrants[2][2];
};

struct Matrix* matrix_constructor(int** input_matrix,
                                  int   len,
                                  int   start_x,
                                  int   start_y);
struct Matrix* matrix_add(struct Matrix* a, struct Matrix* b);
void           matrix_destructor(struct Matrix* matrix);

int
main(int argc, char** argv) {
    int  len             = 4;
    int* base_matrix_a[] = {
        (int[]) { 1,  2,  3,  4},
         (int[]) { 5,  6,  7,  8},
        (int[]) { 9, 10, 11, 12},
         (int[]) {13, 14, 15, 16}
    };
    int* base_matrix_b[] = {
        (int[]) {1, 1, 1, 1},
         (int[]) {1, 1, 1, 1},
         (int[]) {1, 1, 1, 1},
        (int[]) {1, 1, 1, 1}
    };

    struct Matrix* matrix_a = matrix_constructor(base_matrix_a, len, 0, 0);
    struct Matrix* matrix_b = matrix_constructor(base_matrix_b, len, 0, 0);

    matrix_add(matrix_a, matrix_b);

    matrix_destructor(matrix_a);
    matrix_destructor(matrix_b);

    return 0;
}

struct Matrix*
matrix_constructor(int** input_matrix, int len, int start_x, int start_y) {
    struct Matrix* matrix = ( struct Matrix* ) malloc(sizeof(struct Matrix));

    matrix->len = len;

    if ( matrix->len == 2 ) {
        matrix->quadrants[0][0].num = input_matrix[start_x + 0][start_y + 0];
        matrix->quadrants[0][1].num = input_matrix[start_x + 0][start_y + 1];
        matrix->quadrants[1][0].num = input_matrix[start_x + 1][start_y + 0];
        matrix->quadrants[1][1].num = input_matrix[start_x + 1][start_y + 1];
    } else {
        matrix->quadrants[0][0].matrix =
            matrix_constructor(input_matrix, len / 2, 0, 0);
        matrix->quadrants[0][1].matrix =
            matrix_constructor(input_matrix, len / 2, 0, len / 2);
        matrix->quadrants[1][0].matrix =
            matrix_constructor(input_matrix, len / 2, len / 2, 0);
        matrix->quadrants[1][1].matrix =
            matrix_constructor(input_matrix, len / 2, len / 2, len / 2);
    }

    return matrix;
}

struct Matrix*
matrix_add(struct Matrix* a, struct Matrix* b) {
    if ( a->len == 2 ) {
        a->quadrants[0][0].num += b->quadrants[0][0].num;
        a->quadrants[0][1].num += b->quadrants[0][1].num;
        a->quadrants[1][0].num += b->quadrants[1][0].num;
        a->quadrants[1][1].num += b->quadrants[1][1].num;
    } else {
        matrix_add(a->quadrants[0][0].matrix, b->quadrants[0][0].matrix);
        matrix_add(a->quadrants[0][1].matrix, b->quadrants[0][1].matrix);
        matrix_add(a->quadrants[1][0].matrix, b->quadrants[1][0].matrix);
        matrix_add(a->quadrants[1][1].matrix, b->quadrants[1][1].matrix);
    }

    return a;
}

void
matrix_destructor(struct Matrix* matrix) {
    if ( matrix->len > 2 ) {
        matrix_destructor(matrix->quadrants[0][0].matrix);
        matrix_destructor(matrix->quadrants[0][1].matrix);
        matrix_destructor(matrix->quadrants[1][0].matrix);
        matrix_destructor(matrix->quadrants[1][1].matrix);
    }

    free(matrix);
}