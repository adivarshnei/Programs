from __future__ import annotations
import itertools


def add(a, b):
    if type(a) is int:
        return a + b
    else:
        return [[a[i][j] + b[i][j] for j in range(2)] for i in range(2)]


def sub(a, b):
    if type(a) is int:
        return a - b
    else:
        return [[a[i][j] + b[i][j] for j in range(2)] for i in range(2)]


def split(a):
    h = len(a)
    w = len(a[1])
    top_left = list(
        itertools.chain.from_iterable([a[i][: w // 2] for i in range(h // 2)])
    )
    top_right = list(
        itertools.chain.from_iterable([a[i][w // 2 :] for i in range(h // 2)])
    )
    bot_left = list(
        itertools.chain.from_iterable(
            [a[i][: w // 2] for i in range(h // 2, h)]
        )
    )
    bot_right = list(
        itertools.chain.from_iterable(
            [a[i][w // 2 :] for i in range(h // 2, h)]
        )
    )

    return top_left, top_right, bot_left, bot_right


def mult(a, b):
    if type(a) is int:
        return a * b
    else:
        split_a = split(a)
        split_b = split(b)
        print(split_a[0])
        p = mult(
            add(split_a[0][0], split_a[3][0]),
            add(split_b[0][0], split_b[3][0]),
        )
        q = mult(add(split_a[2][0][0], split_a[3][0][0]), split_b[0][0][0])
        r = mult(split_a[0][0][0], sub(split_b[1][0][0], split_b[3][0][0]))
        s = mult(split_a[3][0][0], sub(split_b[2][0][0], split_b[0][0][0]))
        t = mult(add(split_a[0][0][0], split_a[1][0][0]), split_b[3][0][0])
        u = mult(
            sub(split_a[2][0][0], split_a[0][0][0]),
            add(split_b[0][0][0], split_b[1][0][0]),
        )
        v = mult(
            sub(split_a[1][0][0], split_a[3][0][0]),
            add(split_b[2][0][0], split_b[3][0][0]),
        )

        c = [
            [add(sub(add(p, s), t), v), add(r, t)],
            [add(q, s), add(sub(add(p, r), q), u)],
        ]

        print(c)


def main() -> None:
    a: list[list[int]] = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
        [13, 14, 15, 16],
    ]
    b: list[list[int]] = [
        [1, 1, 1, 1],
        [1, 1, 1, 1],
        [1, 1, 1, 1],
        [1, 1, 1, 1],
    ]

    # a: list[list[int]] = [[1, 2], [3, 4]]
    # b: list[list[int]] = [[5, 6], [7, 8]]

    # split(a)

    mult(a, b)


if __name__ == "__main__":
    main()
