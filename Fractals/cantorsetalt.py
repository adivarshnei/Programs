import typing
import pygame

from __future__ import annotations


class screenDefine:
    def __init__(self, screenParams) -> None:
        pygame.init()
        self.screen: pygame.Surface = pygame.display.set_mode(
            screenParams["dimensions"]
        )
        pygame.display.set_caption(screenParams["caption"])
        self.screen.fill(screenParams["bgColor"])

    def returnScreenVar(self) -> pygame.Surface:
        return self.screen


def cantorSetAlt(screen, screenParams, left, top, width, height, index) -> None:
    onColor = screenParams["printColor"]
    offColor = screenParams["bgColor"]

    partWidth = width / 3

    if partWidth <= 1:
        return

    if index >= 1:
        pygame.draw.rect(
            screen.returnScreenVar(),
            onColor,
            pygame.Rect(left, top, width, height),
        )

        pygame.time.delay(40)
        pygame.display.update()

        pygame.draw.rect(
            screen.returnScreenVar(),
            offColor,
            pygame.Rect(left + width / 3, top, width / 3, height),
        )
    else:
        pygame.draw.rect(
            screen.returnScreenVar(),
            onColor,
            pygame.Rect(left, top, width, height),
        )
        partWidth = width

    cantorSetAlt(
        screen, screenParams, left, top + 30, partWidth, height, index + 1
    )
    cantorSetAlt(
        screen,
        screenParams,
        left + 2 * partWidth,
        top + 30,
        partWidth,
        height,
        index + 1,
    )


def main() -> None:
    screenParams:dict[str,typing.Any] = {
        "dimensions": [800, 800],
        "bgColor": (31, 33, 42),
        "caption": "Alternate Cantor Set",
        "printColor": (180, 180, 180),
    }

    running: typing.Literal[True] = True
    runChk: typing.Literal[False] = False

    screen: screenDefine = screenDefine(screenParams)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running: typing.Literal[True] = not running

        if not runChk:
            cantorSetAlt(
                screen,
                screenParams,
                0,
                200,
                screenParams["dimensions"][0],
                20,
                0,
            )
            runChk: typing.Literal[False] = True

        pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
