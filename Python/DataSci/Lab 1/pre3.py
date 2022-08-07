# Program to add two matrices

import random

MATRIX_SIZE = 5
ELEM_LIMIT = 20


def random_matrix_gen():
    matrix = [
        [random.randrange(0, ELEM_LIMIT) for _ in range(MATRIX_SIZE)]
        for _ in range(MATRIX_SIZE)
    ]

    return matrix


def print_matrix(matrix):
    for i in range(MATRIX_SIZE):
        for j in range(MATRIX_SIZE):
            print(f"{matrix[i][j]:3} ", end="")

        print()

    print()


def matrix_add(m1, m2):
    result_matrix = [
        [m1[i][j] + m2[i][j] for j in range(MATRIX_SIZE)] for i in range(MATRIX_SIZE)
    ]

    return result_matrix


def main():
    m1 = random_matrix_gen()
    m2 = random_matrix_gen()

    print_matrix(m1)
    print_matrix(m2)
    print_matrix(matrix_add(m1, m2))


if __name__ == "__main__":
    main()
