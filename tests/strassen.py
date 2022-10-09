from __future__ import annotations
from numpy import array


def add_matrix(a, b):
    if type(a) is int:
        return a + b
    else:
        return [[p + q for p, q in zip(i, j)] for i, j in zip(a, b)]


def sub_matrix(a, b):
    if type(a) is int:
        return a - b
    else:
        return [[p - q for p, q in zip(i, j)] for i, j in zip(a, b)]


def split_matrix(matrix):
    matrices = [[None] * 2] * 2

    for x, i in zip(range(0, len(matrix), int(len(matrix) / 2)), range(2)):
        for y, j in zip(range(0, len(matrix), int(len(matrix) / 2)), range(2)):
            matrices[i][j] = array(matrix)[i : i + 2, j : j + 2].tolist()

    # print(matrices)

    return matrices


def strassen_mult(a, b):
    A = [[None] * 2] * 2
    B = [[None] * 2] * 2

    if type(a) is int:
        return a * b
    if len(a) != 2 and type(a) is list:
        A = split_matrix(a)
        B = split_matrix(b)
        # print([[p + q for p, q in zip(i, j)] for i, j in zip(A[0], A[3])])
        # print(A)
    else:
        A = a
        B = b
        # print(A)

    # print(A)

    p = strassen_mult(
        add_matrix(A[0][0], A[1][1]), add_matrix(B[0][0], B[1][1])
    )
    q = strassen_mult(add_matrix(A[1][0], A[1][1]), B[0][0])
    r = strassen_mult(A[0][0], sub_matrix(B[0][1], B[1][1]))
    s = strassen_mult(A[1][1], sub_matrix(B[1][0], B[0][0]))
    t = strassen_mult(add_matrix(A[0][0], A[0][1]), B[1][1])
    u = strassen_mult(
        sub_matrix(A[1][0], A[0][0]), add_matrix(B[0][0], B[0][1])
    )
    v = strassen_mult(
        sub_matrix(A[0][1], A[1][1]), add_matrix(B[1][0], B[1][1])
    )
    
    print(p)

    c = [
        [add_matrix(sub_matrix(add_matrix(p, s), t), v), add_matrix(r, t)],
        [add_matrix(q, s), add_matrix(sub_matrix(add_matrix(p, r), q), u)],
    ]
    
    return c


def main() -> None:
    # matrix_a = [
    #     [4, 2, 0, 1],
    #     [3, 1, 2, 5],
    #     [3, 2, 1, 4],
    #     [5, 2, 6, 7],
    # ]
    # matrix_b = [
    #     [2, 1, 3, 2],
    #     [5, 4, 2, 3],
    #     [1, 4, 0, 2],
    #     [3, 2, 4, 1],
    # ]
    matrix_a = [[1, 2], [3, 4]]
    matrix_b = [[5, 6], [7, 8]]

    # print(matrix_a)
    # print(matrix_b)

    # split_a: list[list[list[int]]] = split_matrix(matrix_a)
    # split_b: list[list[list[int]]] = split_matrix(matrix_b)
    # print(split_a)
    # print(split_b)

    # strassen_mult([[1, 2], [3, 4]], [[5, 6], [7, 8]])

    strassen_mult(matrix_a, matrix_b)


if __name__ == "__main__":
    main()
