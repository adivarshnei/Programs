import pygame
import random


class screenDefine:
    def __init__(self, screenParams):
        pygame.init()
        self.screen = pygame.display.set_mode(screenParams['dimensions'])
        pygame.display.set_caption(screenParams['caption'])
        self.screen.fill(screenParams['bgColor'])

    def returnScreenVar(self):
        return self.screen


def rangeMap(val, prev, new):
    return (val - prev[0]) / (prev[1] - prev[0]) * (new[1] - new[0]) + new[0]


def barnsleyFern(screen, screenParams, x, y):
    for i in range(1000):
        for j in range(600):
            pygame.event.get()

            randVar = random.random()

            pointX = rangeMap(x, (-2.1820, 2.6558),
                              (0, screenParams['dimensions'][0]))
            pointY = rangeMap(
                y, (0, 9.9983), (screenParams['dimensions'][1], 0))

            pygame.draw.line(
                screen.returnScreenVar(),
                screenParams['printColor'],
                (pointX, pointY),
                (pointX + 0.1, pointY + 0.1)
            )

            if randVar < 0.01:
                nextX = 0
                nextY = 0.16 * y
            elif randVar < 0.86:
                nextX = 0.85 * x + 0.04 * y
                nextY = -0.04 * x + 0.85 * y + 1.6
            elif randVar < 0.93:
                nextX = 0.20 * x - 0.26 * y
                nextY = 0.23 * x + 0.22 * y + 1.6
            else:
                nextX = -0.15 * x + 0.28 * y
                nextY = 0.26 * x + 0.24 * y + 0.44

            x = nextX
            y = nextY

        pygame.display.update()


def main():
    screenParams = {
        'dimensions': [800, 800],
        'printColor': (31, 33, 42),
        'caption': 'Barnsley Fern',
        'bgColor': (180, 180, 180)
    }

    running = True
    runChk = False

    screen = screenDefine(screenParams)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

        if not runChk:
            barnsleyFern(screen, screenParams, 0, 0)
            runChk = True

        pygame.display.update()

    pygame.quit()


if __name__ == '__main__':
    main()
