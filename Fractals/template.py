import pygame


class screenDefine:
    def __init__(self, screenParams):
        pygame.init()
        self.screen = pygame.display.set_mode(screenParams['dimensions'])
        pygame.display.set_caption(screenParams['caption'])
        self.screen.fill(screenParams['bgColor'])

    def returnScreenVar(self):
        return self.screen


def main():
    screenParams = {
        'dimensions': [800, 800],
        'bgColor': (31, 33, 42),
        'caption': 'Title',
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

            runChk = True

        pygame.display.update()

    pygame.quit()


if __name__ == '__main__':
    main()
