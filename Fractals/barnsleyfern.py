import typing
import pygame
import random

from __future__ import annotations


class screenDefine:
    def __init__(
        self: screenDefine,
        screenParams: dict[str, typing.Any],
    ) -> None:
        pygame.init()
        self.screen: pygame.Surface = pygame.display.set_mode(
            screenParams["dimensions"]
        )
        pygame.display.set_caption(screenParams["caption"])
        self.screen.fill(screenParams["bgColor"])

    def returnScreenVar(self: screenDefine) -> pygame.Surface:
        return self.screen


def rangeMap(
    val: float, prev: tuple[float, float], new: tuple[float, float]
) -> float:
    return (val - prev[0]) / (prev[1] - prev[0]) * (new[1] - new[0]) + new[0]


def barnsleyFern(
    screen: screenDefine,
    screenParams: dict[str, typing.Any],
    x: float,
    y: float,
) -> None:
    for i in range(1000):
        for j in range(600):
            pygame.event.get()

            randVar: float = random.random()

            pointX: float = rangeMap(
                x, (-2.1820, 2.6558), (0, screenParams["dimensions"][0])
            )
            pointY: float = rangeMap(
                y, (0, 9.9983), (screenParams["dimensions"][1], 0)
            )

            pygame.draw.line(
                screen.returnScreenVar(),
                screenParams["printColor"],
                (pointX, pointY),
                (pointX + 0.01, pointY + 0.01),
            )

            if randVar < 0.01:
                nextX: float = 0
                nextY: float = 0.16 * y
            elif randVar < 0.86:
                nextX: float = 0.85 * x + 0.04 * y
                nextY: float = -0.04 * x + 0.85 * y + 1.6
            elif randVar < 0.93:
                nextX: float = 0.20 * x - 0.26 * y
                nextY: float = 0.23 * x + 0.22 * y + 1.6
            else:
                nextX: float = -0.15 * x + 0.28 * y
                nextY: float = 0.26 * x + 0.24 * y + 0.44

            x: float = nextX
            y: float = nextY

        pygame.display.update()


def main() -> None:
    screenParams: dict[str, typing.Any] = {
        "dimensions": [800, 800],
        # 'printColor': (31, 33, 42),
        # "printColor": (0, 0, 0),
        "printColor": (255, 255, 255),
        "caption": "Barnsley Fern",
        # 'bgColor': (180, 180, 180),
        # "bgColor": (255, 255, 255),
        "bgColor": (0, 0, 0),
    }

    running: typing.Literal[True] = True
    runChk: typing.Literal[False] = False

    screen: screenDefine = screenDefine(screenParams)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running: typing.Literal[True] = not running

        if not runChk:
            barnsleyFern(screen, screenParams, 0, 0)
            runChk: typing.Literal[False] = True

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
