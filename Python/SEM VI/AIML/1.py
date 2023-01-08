# 1. Write a python program to compute central tendency measures and measure of dispersion

import random
from typing import List
import statistics
import math


def random_list(size: int) -> list:
    return [random.randint(0, 100) for _ in range(size)]


def mean(elements: List[int]) -> float:
    elements_sum = sum(elements) / len(elements)
    return elements_sum


def median(elements: List[int]) -> float:
    if len(elements) % 2 != 0:
        return elements[len(elements) // 2]
    else:
        return (
            elements[(len(elements)) // 2] + elements[(len(elements)) // 2 - 1]
        ) / 2


def mode(elements: List[int]) -> int:
    counts = [0 for _ in range(max(elements) + 1)]

    for i in elements:
        counts[i] += 1

    return counts.index(max(counts))
    pass


def variance(elements: List[int]) -> float:
    return sum((i - mean(elements)) ** 2 for i in elements) / (
        len(elements) - 1
    )


def stddev(elements: List[int]) -> float:
    return math.sqrt(
        sum((i - mean(elements)) ** 2 for i in elements) / (len(elements) - 1)
    )


def main() -> None:
    elements: list = random_list(100)
    elements.sort()
    print(elements)

    print(f"Mean:     {mean(elements)}")
    print(f"Median:   {median(elements)}")
    print(f"Mode:     {mode(elements)}")
    print(f"Variance: {variance(elements)}")
    print(f"Std. Dev: {stddev(elements)}")


if __name__ == "__main__":
    main()
