import os
import random
import time

ARRAY_SIZE = 10
ELEM_LIMIT = 50
TIME_DELAY = 0.005


def initArrayValues() -> None:
    array = []

    for _ in range(ELEM_LIMIT):
        array.append(random.randrange(0, ARRAY_SIZE))

    return array


def barGraph(array: list) -> list:
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


def getMinValIndex(array: list, buffer: int) -> int:
    min = array[buffer]
    minIndex = buffer
    found = False

    for i in range(buffer + 1, len(array)):
        if min > array[i]:
            min = array[i]
            minIndex = i
            found = True

    return minIndex if found == True else -1


def selectionSort(array: list) -> list:
    barGraph(array)

    for i in range(len(array)):
        minValIndex = getMinValIndex(array, i)

        if minValIndex >= i and minValIndex != -1:
            array[i], array[minValIndex] = array[minValIndex], array[i]

            time.sleep(TIME_DELAY)
            os.system("cls")
            barGraph(array)

    return array


def main() -> None:
    array = initArrayValues()
    array = selectionSort(array)

    while True:
        if isSorted(array):
            print("DONE")
            break
        else:
            array = selectionSort(array)


if __name__ == "__main__":
    main()
