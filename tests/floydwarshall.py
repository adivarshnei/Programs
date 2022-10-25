from __future__ import annotations

import os
import subprocess
import typing


def get_outputs(filename: str) -> bytes:
    os.system(command=f"gcc {filename} -o {os.path.splitext(p=filename)[0]}")
    process = subprocess.Popen(
        args=[f"{os.path.splitext(p=filename)[0]}"], stdout=subprocess.PIPE
    )

    (output, _) = process.communicate()
    _ = process.wait()

    return output


def tokenize(input: bytes) -> list[list[typing.Any]]:
    lines = input.decode().split(sep="\n")
    tokens = [line.split() for line in lines]
    # tokens = [list(map(int, token)) for token in tokens]
    tokens.pop()

    return tokens


def parse(
    tokens: list[list[str]],
) -> tuple[int, list[list[str]], list[list[int]], list[list[str]]]:
    length = int(tokens[0][0])
    del tokens[0]

    adj = tokens[0:length]
    del tokens[0:length]

    distance = [list(map(int, row)) for row in tokens[0:length]]
    del tokens[0:length]

    parent = tokens

    return (length, adj, distance, parent)


def main() -> None:
    # output = get_outputs(filename="floydwarshall.c")

    # matrix = tokenize(output)

    # for row in matrix:
    #     print(row)

    length, adj, distance, parent = parse(
        tokens=tokenize(input=get_outputs(filename="floydwarshall.c"))
    )

    print(length)

    for row in adj:
        print(row)

    for row in distance:
        print(row)

    for row in parent:
        print(row)

    # print(
    # f"{parse(tokens=tokenize(input=get_outputs(filename='floydwarshall.c')))}"
    # )


if __name__ == "__main__":
    main()
