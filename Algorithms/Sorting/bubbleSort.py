import os
import random
import time

ARRAY_SIZE = 10
ELEM_LIMIT = 50
TIME_DELAY = 0.005


def initArrayValues() -> list:
    array = []

    for _ in range(ELEM_LIMIT):
        array.append(random.randrange(0, ARRAY_SIZE))

    return array


def barGraph(array: list) -> None:
    maxElement = max(array)

    for i in range(maxElement):
        for j in range(len(array)):
            if array[j] >= maxElement - i:
                print("*", end="")
            else:
                print(" ", end="")

        print()


def isSorted(array: list) -> bool:
    for i in range(len(array) - 1):
        if array[i] > array[i + 1]:
            return False

    return True


def bubbleSort(array: list) -> list:
    barGraph(array)

    for i in range(len(array) - 1):
        for j in range(len(array) - i - 1):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]

                time.sleep(TIME_DELAY)
                os.system("cls")
                barGraph(array)

    return array


def main() -> None:
    array = initArrayValues()
    array = bubbleSort(array)

    while True:
        if isSorted(array):
            print("DONE")
            break
        else:
            array = bubbleSort(array)


if __name__ == "__main__":
    main()
