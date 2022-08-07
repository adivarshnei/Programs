import math
import os
import random
import time

ARRAY_SIZE = 150
ELEM_LIMIT = 10
TIME_DELAY = 0.005


def initArrayValues() -> list:
    array = []

    for _ in range(ARRAY_SIZE):
        array.append(random.randrange(0, ELEM_LIMIT))

    return array


def barGraph(array: list) -> None:
    maxElement = max(array)

    for i in range(maxElement):
        for j in range(len(array)):
            if array[j] >= maxElement - i:
                print("*", end="")
                pass
            else:
                print(" ", end="")

        print()


def isSorted(array: list) -> bool:
    for i in range(len(array) - 1):
        if array[i] > array[i + 1]:
            return False

    return True


def merge(array: list, bottom: int, middle: int, top: int) -> None:
    i = bottom
    j = middle + 1
    aux = [0 for _ in range(ARRAY_SIZE)]

    for k in range(bottom, top + 1):
        aux[k] = array[k]

    for k in range(bottom, top + 1):
        if i > middle:
            array[k] = aux[j]
            j += 1

            time.sleep(TIME_DELAY)
            os.system("cls")
            barGraph(array)
        elif j > top:
            array[k] = aux[i]
            i += 1

            time.sleep(TIME_DELAY)
            os.system("cls")
            barGraph(array)
        elif aux[j] < aux[i]:
            array[k] = aux[j]
            j += 1

            time.sleep(TIME_DELAY)
            os.system("cls")
            barGraph(array)
        else:
            array[k] = aux[i]
            i += 1


def mergeSort(array: list) -> list:
    os.system("cls")
    barGraph(array)

    sort(array, 0, ARRAY_SIZE - 1)

    return array


def sort(array: list, bottom: int, top: int) -> None:
    if top <= bottom or isSorted(array):
        return

    middle = math.floor(bottom + (top - bottom) / 2)

    sort(array, bottom, middle)
    sort(array, middle + 1, top)
    merge(array, bottom, middle, top)


def main() -> None:
    array = initArrayValues()
    array = mergeSort(array)

    while True:
        if isSorted(array):
            print("DONE")
            break
        else:
            array = mergeSort(array)


if __name__ == "__main__":
    main()
