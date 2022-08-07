import pygame
import random
import keyboard

dimensions = [1920, 1020] # Full Screen Windowed
# dimensions = [1920, 1080] # Full Screen
# dimensions = [960, 510]
randNos = []
colorNos = []
numRange = dimensions[0] // 21
maxNum = dimensions[1] // 5
swapStat = False
elemType = "c"

pygame.init()
pygame.display.set_caption("Visualizer")

screen = pygame.display.set_mode(dimensions)


def randGen():
    randNos.clear()
    colorNos.clear()

    for i in range(numRange):
        randNos.append(random.randint(0, maxNum))

    for i in range(numRange):
        colorNos.append(
            (
                255 - int((255 / maxNum) * randNos[i]),
                int((255 / maxNum) * randNos[i]),
                0,
            )
        )


def drawElem(typ, arr):
    if typ == "c":
        for i in range(len(randNos)):
            pygame.draw.circle(
                screen,
                colorNos[i],
                (
                    dimensions[0] / 2 + 20 * (i - (len(arr) / 2 - 1)),
                    dimensions[1] - 3 * (arr[i] + 20),
                ),
                5,
            )
    elif typ == "r":
        for i in range(len(randNos)):
            pygame.draw.rect(
                screen,
                colorNos[i],
                (
                    dimensions[0] / 2 - 5 + 20 * (i - (len(arr) / 2 - 1)),
                    dimensions[1] - 3 * (arr[i] + 20),
                    10,
                    dimensions[1] - randNos[i],
                ),
            )


def drawLine(j):
    pygame.draw.line(
        screen,
        (0, 0, 255),
        (dimensions[0] / 2 + 20 * (j - (len(randNos) / 2 - 1)), dimensions[1]),
        (dimensions[0] / 2 + 20 * (j - (len(randNos) / 2 - 1)), 0),
    )
    pygame.time.delay(15)
    pygame.display.update()


def bubSort():
    for i in range(len(randNos)):
        swapStat = False

        for j in range(0, len(randNos) - i - 1):
            if randNos[j] > randNos[j + 1]:
                randNos[j], randNos[j + 1] = randNos[j + 1], randNos[j]
                colorNos[j], colorNos[j + 1] = colorNos[j + 1], colorNos[j]
                swapStat = True

            drawLine(j)

            screen.fill((0, 0, 0))

            drawElem(elemType, randNos)

            # pygame.time.delay(15)
            pygame.display.update()

        if swapStat == False:
            break


def selSort():
    for i in range(len(randNos)):
        minIndex = i

        for j in range(i + 1, len(randNos)):
            if randNos[j] < randNos[minIndex]:
                minIndex = j

        if minIndex != i:
            randNos[i], randNos[minIndex] = randNos[minIndex], randNos[i]
            colorNos[i], colorNos[minIndex] = colorNos[minIndex], colorNos[i]

            drawLine(i)
            drawLine(minIndex)

        screen.fill((0, 0, 0))

        drawElem(elemType, randNos)

        pygame.time.delay(15)
        pygame.display.update()


def partition(arr, colArr, low, high):
    i = low - 1
    pivot = arr[high]  # pivot element

    for j in range(low, high):
        # If current element is smaller
        if arr[j] <= pivot:
            # increment
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
            colArr[i], colArr[j] = colArr[j], colArr[i]

            screen.fill((0, 0, 0))

            drawElem(elemType, randNos)

            pygame.time.delay(15)
            pygame.display.update()

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    colArr[i + 1], colArr[high] = colArr[high], colArr[i + 1]

    screen.fill((0, 0, 0))

    drawElem(elemType, randNos)

    # pygame.time.delay(15)
    pygame.display.update()

    return i + 1


# sort
def quickSort(arr, colArr, low, high):
    if low < high:
        # index
        pi = partition(arr, colArr, low, high)
        drawLine(pi)
        # pygame.time.delay(15)

        if sortCheck(arr):
            return

        # sort the partitions
        quickSort(arr, colArr, low, pi - 1)
        quickSort(arr, colArr, pi + 1, high)


def insSort():
    for i in range(len(randNos)):
        key = randNos[i]
        colKey = colorNos[i]

        j = i - 1

        while j >= 0 and key < randNos[j]:
            randNos[j + 1] = randNos[j]
            colorNos[j + 1] = colorNos[j]
            j -= 1

            screen.fill((0, 0, 0))

            drawElem(elemType, randNos)

            pygame.time.delay(15)
            pygame.display.update()

        randNos[j + 1] = key
        colorNos[j + 1] = colKey

        drawLine(j + 1)
        drawLine(key)

        pygame.time.delay(15)

        screen.fill((0, 0, 0))

        drawElem(elemType, randNos)

        pygame.time.delay(15)
        pygame.display.update()


# TODO: FIX COUNT SORT
# TODO: split file into algorithms, prerequisites, main, auxiliary methods


def countSort():
    colNosTup = []

    for i in range(len(randNos)):
        colNosTup.append((randNos[i], colorNos[i]))

    output = [0 for i in range(len(randNos))]
    count = [0 for i in range(maxNum + 1)]

    for i in range(len(randNos)):
        count[randNos[i]] += 1

    for i in range(1, maxNum):
        count[i] += count[i - 1]

    i = len(randNos) - 1

    while i >= 0:
        output[count[randNos[i]] - 1] = randNos[i]
        count[randNos[i]] -= 1
        i -= 1

    for i in range(len(randNos)):
        randNos[i] = output[i]

        for j in range(len(randNos)):
            if randNos[i] == colNosTup[j][0]:
                colorNos[i] = colNosTup[j][1]

        screen.fill((0, 0, 0))

        drawElem(elemType, randNos)

        pygame.time.delay(15)
        pygame.display.update()


def sortCheck(arr):
    if len(arr) == 1 or len(arr) == 0:
        return True

    return arr[0] <= arr[1] and sortCheck(arr[1:])


randGen()

running = True
keyChk = False

clock = pygame.time.Clock()

while running:
    sortExec = False

    clock.tick(15)

    pygame.time.delay(5)

    keys = pygame.key.get_pressed()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if (
        keys[pygame.K_b]
        or keys[pygame.K_s]
        or keys[pygame.K_q]
        or keys[pygame.K_i]
        or keys[pygame.K_c]
    ):
        sortExec = True

    if sortExec == False:
        screen.fill((0, 0, 0))
        drawElem(elemType, randNos)
        pygame.display.update()

        try:
            if keyboard.is_pressed("r"):
                randGen()
                print(randNos)
                pygame.display.update()

            if keyboard.is_pressed("e"):
                running = False

            if keyboard.is_pressed("t"):
                if elemType == "c":
                    elemType = "r"
                else:
                    elemType = "c"

        except:
            pass

    else:
        if keys[pygame.K_b]:
            bubSort()
        elif keys[pygame.K_s]:
            selSort()
        elif keys[pygame.K_q]:
            quickSort(randNos, colorNos, 0, len(randNos) - 1)
        elif keys[pygame.K_i]:
            insSort()
        elif keys[pygame.K_c]:
            countSort()

pygame.quit()
