import pygame
from multiprocessing import Process


class screenDefine:
    def __init__(self, screenParams):
        pygame.init()
        self.screen = pygame.display.set_mode(screenParams['dimensions'])
        pygame.display.set_caption(screenParams['caption'])
        self.screen.fill(screenParams['bgColor'])

    def returnScreenVar(self):
        return self.screen


def cantorSet(screen, screenParams, left, width):
    onColor = screenParams['printColor']
    offColor = screenParams['bgColor']

    partWidth = width / 3

    if partWidth <= 1:
        return

    pygame.draw.rect(
        screen.returnScreenVar(),
        onColor,
        pygame.Rect(
            left,
            0,
            width,
            screenParams['dimensions'][1]
        )
    )

    pygame.time.delay(40)
    pygame.display.update()

    pygame.draw.rect(
        screen.returnScreenVar(),
        offColor,
        pygame.Rect(
            left + width / 3,
            0,
            width / 3,
            screenParams['dimensions'][1]
        )
    )

    cantorSet(screen, screenParams, left, partWidth)
    cantorSet(screen, screenParams, left + 2 * partWidth, partWidth)


def main():
    screenParams = {
        'dimensions': [800, 800],
        'bgColor': (31, 33, 42),
        'caption': 'Cantor Set',
        'printColor': (180, 180, 180)
    }

    running = True
    runChk = False

    screen = screenDefine(screenParams)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

        if not runChk:
            cantorSet(screen, screenParams, 0, screenParams['dimensions'][0])
            runChk = True

        pygame.display.update()

    pygame.quit()


if __name__ == '__main__':
    main()
