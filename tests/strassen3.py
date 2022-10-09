import math


def add(a, b):
    if type(a) is int:
        return a + b
    else:
        return [add(a[i], b[i]) for i in range(len(a))]


def sub(a, b):
    if type(a) is int:
        return a - b
    else:
        return [sub(a[i], b[i]) for i in range(len(a))]


def split(a):
    length = len(a)
    rows = int(math.sqrt(length))
    quadsize = int(rows / 2)
    part1 = list()
    part2 = list()
    part3 = list()
    part4 = list()
    for i in range(quadsize):
        part1.extend(
            (j + 0 * quadsize) for j in range(i * rows, quadsize + i * rows)
        )
        part2.extend(
            (j + 1 * quadsize) for j in range(i * rows, quadsize + i * rows)
        )
        part3.extend(
            (j + (rows + 0) * quadsize)
            for j in range(i * rows, quadsize + i * rows)
        )
        part4.extend(
            (j + (rows + 1) * quadsize)
            for j in range(i * rows, quadsize + i * rows)
        )

    return (
        [a[i] for i in part1],
        [a[i] for i in part2],
        [a[i] for i in part3],
        [a[i] for i in part4],
    )


def unsplit(a):
    # if type(a[0]) is int:
    #     print(a)
    #     return a
    # else:
    # print_matrix(a)

    length = len(a)
    rows = int(math.sqrt(len(a)))
    quadsize = int(rows / 2)
    print(len(a))
    print(rows)
    print(quadsize)

    final = [[a[j + rows * i] for j in range(rows)] for i in range(rows)]

    for i in range(len(final)):
        for j in range(len(final[0])):
            print(f"{final[i][j]:5}", end="")
        print()

    return final


# else:
#     for i in range(len(a)):
#         unsplit(a[i])


def mult(a, b):
    if type(a) is int:
        return a * b
    else:
        a11, a12, a21, a22 = split(a)
        # print(a11)
        # print(a12)
        # print(a21)
        # print(a22)
        b11, b12, b21, b22 = split(b)
        if len(a11) == 1:
            a11 = a11[0]
            a12 = a12[0]
            a21 = a21[0]
            a22 = a22[0]
            b11 = b11[0]
            b12 = b12[0]
            b21 = b21[0]
            b22 = b22[0]
        p = mult(add(a11, a22), add(b11, b22))
        q = mult(add(a21, a22), b11)
        r = mult(a11, sub(b12, b22))
        s = mult(a22, sub(b21, b11))
        t = mult(add(a11, a12), b22)
        u = mult(sub(a21, a11), add(b11, b12))
        v = mult(sub(a12, a22), add(b21, b22))

        c = list()
        c11 = add(sub(add(p, s), t), v)
        c12 = add(r, t)
        c21 = add(q, s)
        c22 = add(sub(add(p, r), q), u)

        if type(c11) is int:
            c.append(c11)
            c.append(c12)
            c.append(c21)
            c.append(c22)
        else:
            c.extend(c11)
            c.extend(c12)
            c.extend(c21)
            c.extend(c22)

        # print(c11, c12, c21, c22)
        # print

        return c


def print_matrix(matrix):
    length = int(len(matrix))
    rows = math.sqrt(length)

    for i in range(int(len(matrix))):
        if i % rows == 0:
            print()

        print(f"{matrix[i]:5}", end="")


def main() -> None:
    a = [i % 16 for i in range(64)]
    b = [i % 16 for i in range(64)]
    # print_matrix(a)
    # a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
    # b = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    # a = [1, 2, 3, 4]
    # b = [5, 6, 7, 8]

    # split(a)

    # print(mult(a, b))
    print_matrix(unsplit(mult(a, b)))


if __name__ == "__main__":
    main()
