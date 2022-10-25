from __future__ import annotations

import subprocess
import os
import sys
import typing


def get_outputs(filename: str) -> bytes:
    os.system(command=f"gcc {filename} -o {os.path.splitext(filename)[0]}")
    process: subprocess.Popen[bytes] = subprocess.Popen(
        args=[f"{os.path.splitext(filename)[0]}"], stdout=subprocess.PIPE
    )

    output: bytes
    err: bytes
    (output, err) = process.communicate()
    exit_code: int = process.wait()

    return output


def tokenize(input: bytes) -> list[list[typing.Any]]:
    lines: list[str] = input.decode().split(sep="\n")
    tokens: list[list[str]] = [line.split() for line in lines]
    tokens = list(list(map(int, token)) for token in tokens)

    return tokens


def main() -> None:
    output: bytes = get_outputs(filename="test3.c")
    # output: bytes = get_outputs(sys.argv[1])

    print(tokenize(output))


if __name__ == "__main__":
    main()
