def apsp(matrix, i, j):
    if i == j:
        print(i + 1, end="")
        # pass
    elif matrix[i][j] == 0:
        print("NOPE")
    else:
        apsp(matrix, i, matrix[i][j] - 1)
        print(f" -> {j + 1}", end="")


def main():
    matrix = [
        [0, 3, 4, 5, 1],
        [4, 0, 4, 2, 1],
        [4, 3, 0, 2, 1],
        [4, 3, 4, 0, 1],
        [4, 3, 4, 5, 0],
    ]

    for i in range(1, 6):
        for j in range(1, 6):
            if i == j:
                continue
            print(f"{i}, {j}: ", end="")
            apsp(matrix, i - 1, j - 1)
            print()


if __name__ == "__main__":
    main()
