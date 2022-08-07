import pygame
import pygame.freetype
import math
import random
import copy

f: int = 0
w: int = 1920
h: int = 1080
width: int = w + 2 * buf
height: int = h + 2 * buf
res: int = 30

rows: int = math.floor(w / res)
cols: int = math.floor(h / res)


class Screen:
    screen: pygame.surface.Surface = None  # type: ignore[assignment]
    font: pygame.Font = None

    def __init__(self, screenParams: dict) -> None:
        pygame.init()
        # self.screen = pygame.display.set_mode(size=screenParams['dimensions'], flags=pygame.FULLSCREEN)
        self.screen = pygame.display.set_mode(size=screenParams["dimensions"])
        pygame.display.set_caption(title=screenParams["caption"])
        self.screen.fill(color=screenParams["bgColor"])
        self.font = pygame.freetype.SysFont(
            name="Consolas", size=math.floor(3 * res / 4), bold=False
        )

    def returnScreen(self) -> pygame.surface.Surface:
        return self.screen

    def returnFont(self) -> pygame.Font:
        return self.font


class Conway(Screen):
    board1: "list[list[bool]]" = [
        [False for _ in range(cols)] for _ in range(rows)
    ]
    board2: "list[list[bool]]" = [
        [False for _ in range(cols)] for _ in range(rows)
    ]
    neighborsArr: "list[list[int]]" = [
        [0 for _ in range(cols)] for _ in range(rows)
    ]

    calcMode: bool = False
    numDisplay: bool = True
    lineDisplay: int = 0
    initMode: bool = True

    def __init__(self, screenParams: dict) -> None:
        super().__init__(screenParams=screenParams)
        self.board1 = copy.deepcopy(x=boardRandomize(board=self.board1))
        self.calc()

    def changeCalcMode(self, screenParams: dict) -> None:
        self.calcMode = not self.calcMode
        self.initMode = True

        self.calc()

        self.show(screenParams=screenParams)

    def returnCalcMode(self) -> bool:
        return self.calcMode

    def changeNumDisplay(self) -> None:
        self.numDisplay = not self.numDisplay

    def changeLineDisplay(self) -> None:
        self.lineDisplay = (self.lineDisplay + 1) % 4

    def clickToAdd(self, screenParams: dict, mousePosition: tuple) -> None:
        r: int = math.floor(mousePosition[0] / res)
        c: int = math.floor(mousePosition[1] / res)
        self.board1[c][r] = not self.board1[c][r]

        self.initMode = True

        self.calc()

        self.show(screenParams=screenParams)

    def show(self, screenParams: dict) -> None:
        if self.calcMode:
            self.calc()

        for i in range(rows):
            for j in range(cols):
                color: tuple[int, int, int] = (
                    screenParams["printColor"]
                    if self.board1[j][i]
                    else screenParams["bgColor"]
                )

                pygame.draw.rect(
                    surface=super().returnScreen(),
                    color=color,
                    rect=pygame.Rect(
                        left=(res * i + buf),
                        top=(res * j + buf),
                        width=res,
                        height=res,
                    ),
                )

                if self.numDisplay and self.neighborsArr[i][j] != 0:
                    super().returnFont().render_to(
                        surf=super().returnScreen(),
                        dest=(
                            (res * i + buf + 3 * res / 8),
                            (res * j + buf + 3 * res / 8),
                        ),
                        text=str(self.neighborsArr[i][j]),
                        fgcolor=(255, 255, 255),
                    )

        if self.lineDisplay != 0:
            color = (
                (0, 0, 0)
                if self.lineDisplay == 1
                else (
                    (127, 127, 127)
                    if self.lineDisplay == 2
                    else (255, 255, 255)
                )
            )

            for i in range(cols + 1):
                pygame.draw.line(
                    surface=super().returnScreen(),
                    color=color,
                    start_pos=(buf, (res * i + buf)),
                    end_pos=((width - buf), (res * i + buf)),
                    width=2,
                )

            for i in range(rows + 1):
                pygame.draw.line(
                    surface=super().returnScreen(),
                    color=color,
                    start_pos=((res * i + buf), buf),
                    end_pos=((res * i + buf), (width - buf)),
                    width=2,
                )

    def calc(self) -> None:
        self.board2 = copy.deepcopy(x=self.board1)
        neighbors: int = 0

        for i in range(rows):
            for j in range(cols):
                neighbors = 0

                if not self.initMode:
                    if self.neighborsArr[i][j] < 2:
                        self.board2[j][i] = False
                    elif self.neighborsArr[i][j] == 2:
                        pass
                    elif self.neighborsArr[i][j] == 3:
                        self.board2[j][i] = True
                    elif self.neighborsArr[i][j] > 3:
                        self.board2[j][i] = False

                if j != 0:
                    neighbors = (
                        neighbors + 1 if self.board1[j - 1][i] else neighbors
                    )
                if j != cols - 1:
                    neighbors = (
                        neighbors + 1 if self.board1[j + 1][i] else neighbors
                    )
                if i != 0:
                    neighbors = (
                        neighbors + 1 if self.board1[j][i - 1] else neighbors
                    )
                if i != rows - 1:
                    neighbors = (
                        neighbors + 1 if self.board1[j][i + 1] else neighbors
                    )
                if i != 0 and j != 0:
                    neighbors = (
                        neighbors + 1
                        if self.board1[j - 1][i - 1]
                        else neighbors
                    )
                if i != 0 and j != cols - 1:
                    neighbors = (
                        neighbors + 1
                        if self.board1[j + 1][i - 1]
                        else neighbors
                    )
                if i != rows - 1 and j != 0:
                    neighbors = (
                        neighbors + 1
                        if self.board1[j - 1][i + 1]
                        else neighbors
                    )
                if i != rows - 1 and j != cols - 1:
                    neighbors = (
                        neighbors + 1
                        if self.board1[j + 1][i + 1]
                        else neighbors
                    )

                self.neighborsArr[i][j] = neighbors

        if not self.initMode:
            self.board1 = copy.deepcopy(x=self.board2)

        self.initMode = False


def boardRandomize(board: "list[list[bool]]") -> "list[list[bool]]":
    board = [
        [
            (False if math.floor(random.random() * 2) == 0 else True)
            for _ in range(rows)
        ]
        for _ in range(cols)
    ]

    # board = [[(False if (i+j) % 2 != 0 else True)
    #           for i in range(rows)] for j in range(cols)]

    # board = [[(False if math.tan(i) + math.sin(j) > 0 else True)
    #           for i in range(rows)] for j in range(cols)]

    return board


def main() -> None:
    screenParams: dict = {
        "dimensions": [width, height],
        "bgColor": (31, 33, 42),
        "caption": "Conway's Game of Life",
        "printColor": (180, 180, 180),
    }

    running: bool = True
    runChk: bool = False

    conway: Conway = Conway(screenParams=screenParams)
    conway.show(screenParams=screenParams)

    while running:
        conway.show(screenParams=screenParams)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

            if event.type == pygame.MOUSEBUTTONDOWN:
                mousePosition: tuple[int, int] = pygame.mouse.get_pos()
                conway.clickToAdd(
                    screenParams=screenParams, mousePosition=mousePosition
                )

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = not running
                if event.key == pygame.K_r:
                    print()
                    conway = Conway(screenParams=screenParams)
                    conway.show(screenParams=screenParams)
                if event.key == pygame.K_c:
                    conway.changeCalcMode(screenParams=screenParams)
                if event.key == pygame.K_n:
                    conway.changeNumDisplay()
                if event.key == pygame.K_l:
                    conway.changeLineDisplay()

        if not runChk:
            runChk = True

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
