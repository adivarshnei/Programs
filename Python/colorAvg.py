import pygame
import random
import copy

board1 = []
board2 = []


class screenDefine:
    def __init__(self, screenParams):
        pygame.init()
        self.screen = pygame.display.set_mode(screenParams["dimensions"])
        pygame.display.set_caption(screenParams["caption"])
        self.screen.fill(screenParams["bgColor"])

    def returnScreenVar(self):
        return self.screen


def initBoardAnim(screen, screenParams):
    boardPixelCol = []
    global board1
    global board2

    for i in range(int(screenParams["dimensions"][0] / screenParams["size"])):
        subList = []
        subList1 = []

        for j in range(
            int(screenParams["dimensions"][1] / screenParams["size"])
        ):
            n = int(200 * random.random())
            subList.append(n)
            subList1.append(0)

        boardPixelCol.append(subList)
        board1.append(subList1)
        board2.append(subList1)

    for i in range(int(screenParams["dimensions"][0] / screenParams["size"])):
        for j in range(
            int(screenParams["dimensions"][1] / screenParams["size"])
        ):
            pygame.draw.rect(
                screen.returnScreenVar(),
                (boardPixelCol[i][j], boardPixelCol[i][j], boardPixelCol[i][j]),
                pygame.Rect(
                    i * screenParams["size"],
                    j * screenParams["size"],
                    (i + 1) * screenParams["size"],
                    (j + 1) * screenParams["size"],
                ),
            )

    pygame.display.update()

    board1 = copy.deepcopy(boardPixelCol)


def animate(screen, screenParams):
    global board1
    global board2

    while True:
        for i in range(
            int(screenParams["dimensions"][0] / screenParams["size"])
        ):
            for j in range(
                int(screenParams["dimensions"][1] / screenParams["size"])
            ):
                pygame.draw.rect(
                    screen.returnScreenVar(),
                    (board1[i][j], board1[i][j], board1[i][j]),
                    pygame.Rect(
                        i * screenParams["size"],
                        j * screenParams["size"],
                        (i + 1) * screenParams["size"],
                        (j + 1) * screenParams["size"],
                    ),
                )

        pygame.time.delay(40)
        pygame.display.update()

        val = 0

        for i in range(
            int(screenParams["dimensions"][0] / screenParams["size"])
        ):
            for j in range(
                int(screenParams["dimensions"][1] / screenParams["size"])
            ):
                divVal = 4

                if i != 0:
                    val += board1[i - 1][j]
                if (
                    i
                    != int(screenParams["dimensions"][0] / screenParams["size"])
                    - 1
                ):
                    val += board1[i + 1][j]
                if j != 0:
                    val += board1[i][j - 1]
                if (
                    j
                    != int(screenParams["dimensions"][1] / screenParams["size"])
                    - 1
                ):
                    val += board1[i][j + 1]

                if i == 0:
                    divVal -= 1
                if (
                    i
                    == int(screenParams["dimensions"][0] / screenParams["size"])
                    - 1
                ):
                    divVal -= 1
                if j == 0:
                    divVal -= 1
                if (
                    j
                    == int(screenParams["dimensions"][1] / screenParams["size"])
                    - 1
                ):
                    divVal -= 1

                val /= divVal
                val = int(val)
                print("", end="")

                board2[i][j] = val

        print("", end="")
        board1 = copy.deepcopy(board2)


def main():
    screenParams = {
        "dimensions": [800, 800],
        "caption": "Color Average",
        "bgColor": (31, 33, 42),
        "size": 20,
    }

    running = True
    runChk = False

    screen = screenDefine(screenParams)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

        if not runChk:
            initBoardAnim(screen, screenParams)
            animate(screen, screenParams)

            runChk = True

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
