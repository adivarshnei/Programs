import pygame
import math
import random
import pygame.freetype

buf = 0
w, h = 1920, 1080

border = 2
appleBuf = 2

width = w + 2 * buf
height = h + 2 * buf

res = 30
spd = 30

rows = math.floor(w / res)
cols = math.floor(h / res)


class Screen:
    def __init__(self, screenParams):
        pygame.init()
        self.screen = pygame.display.set_mode(screenParams["dimensions"])
        pygame.display.set_caption(screenParams["caption"])
        self.screen.fill(screenParams["bgColor"])
        self.clock = pygame.time.Clock()
        self.titleFont = pygame.freetype.SysFont("Consolas", 2 * res, bold=False)
        self.font = pygame.freetype.SysFont("Consolas", res, bold=False)

    def returnScreen(self):
        return self.screen

    def returnClock(self):
        return self.clock

    def returnTitleFont(self):
        return self.titleFont

    def returnFont(self):
        return self.font


class Snake(Screen):
    def __init__(self, screenParams):
        super().__init__(screenParams)
        self.newSnake()

    def boardInit(self):
        self.board = [[False for i in range(cols)] for j in range(rows)]

    def snakeInit(self):
        self.snake = [[30, 30, 0], [30, 31, 0], [30, 32, 0]]

    def appleInit(self):
        self.apple = [
            math.floor(random.randrange(2, rows - 2)),
            math.floor(random.randrange(2, cols - 2))
        ]

    def newSnake(self):
        self.boardInit()
        self.snakeInit()
        self.appleInit()
        self.lineDisplay = False

    def boardUpdate(self):
        self.boardInit()
        self.moveSnake()

        for i in range(0, len(self.snake)):
            self.board[self.snake[i][0]][self.snake[i][1]] = True

    def toggleLines(self):
        self.lineDisplay = not self.lineDisplay

    def moveUp(self):
        if self.snake[0][2] != 2:
            self.snake[0][2] = 0
            self.moveSnake()

    def moveLeft(self):
        if self.snake[0][2] != 3:
            self.snake[0][2] = 1
            self.moveSnake()

    def moveDown(self):
        if self.snake[0][2] != 0:
            self.snake[0][2] = 2
            self.moveSnake()

    def moveRight(self):
        if self.snake[0][2] != 1:
            self.snake[0][2] = 3
            self.moveSnake()

    def moveSnake(self):
        for i in range(spd * len(self.snake)):
            if i % spd == 0:
                j = math.floor(i / spd)

                if self.snake[j][2] == 0:
                    self.snake[j][1] -= 1
                elif self.snake[j][2] == 1:
                    self.snake[j][0] -= 1
                elif self.snake[j][2] == 2:
                    self.snake[j][1] += 1
                elif self.snake[j][2] == 3:
                    self.snake[j][0] += 1

                self.die()

                if self.snake[0][:2] == self.apple:
                    self.appleInit()
                    self.grow()

        for i in range(1, len(self.snake)):
            self.snake[-i][2] = self.snake[-i - 1][2]

    def grow(self):
        self.snake.append([self.snake[-1][0], self.snake[-1][1], self.snake[-1][2]])

    def die(self):
        if (
            self.snake[0][0] == border - 1
            or self.snake[0][0] - 1 == rows - 2 * border + 1
            or self.snake[0][1] == border - 1
            or self.snake[0][1] - 1 == cols - 2 * border + 1
        ):
            pygame.quit()

        for i in range(1, len(self.snake)):
            if self.snake[0][:2] == self.snake[i][:2]:
                pygame.quit()

    def show(self, screenParams):
        self.boardUpdate()

        for i in range(rows):
            for j in range(cols):
                if (
                    i < border
                    or j < border
                    or i > rows - 2 * border + 1
                    or j > cols - 2 * border + 1
                ):
                    # color = screenParams["printColor"]
                    color = (0, 0, 0)
                elif i == self.apple[0] and j == self.apple[1]:
                    color = screenParams["appleColor"]
                elif self.board[i][j]:
                    color = screenParams["printColor"]
                else:
                    color = screenParams["bgColor"]

                pygame.draw.rect(
                    super().returnScreen(),
                    color,
                    pygame.Rect((res * i + buf), (res * j + buf), res, res),
                )

        super().returnTitleFont().render_to(
            super().returnScreen(), (880, 5), "Snake", (255, 255, 255)
        )

        super().returnFont().render_to(
            super().returnScreen(),
            (200, 1040),
            "L: Show Gridlines     R: Reset     Space: Pause",
            (255, 255, 255)
        )

        super().returnFont().render_to(
            super().returnScreen(),
            (1500, 1040),
            "Snake Length: " + str(len(self.snake)),
            (255, 255, 255)
        )

        if self.lineDisplay:
            color = screenParams["printColor"]

            for i in range(border - 1, cols - 2 * border):
                pygame.draw.line(
                    super().returnScreen(),
                    color,
                    (buf + border * res, (res * (i + border) + buf)),
                    ((width - buf) - border * res, (res * (i + border) + buf)),
                    2,
                )

            for i in range(border - 1, rows - 2 * border):
                pygame.draw.line(
                    super().returnScreen(),
                    color,
                    ((res * (i + border) + buf), buf + border * res),
                    ((res * (i + border) + buf), (width - buf) - 15 * border * res),
                    2,
                )

        pygame.display.update()


def main():
    screenParams = {
        "dimensions": [width, height],
        "bgColor": (31, 33, 42),
        "caption": "Snake",
        "printColor": (180, 180, 180),
        "appleColor": (224, 108, 117),
    }

    snake = Snake(screenParams)

    running = True
    paused = False

    while running:
        if not paused:
            snake.show(screenParams)
            snake.returnClock().tick(20)

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = not running

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    running = not running
                elif event.key == pygame.K_l:
                    snake.toggleLines()
                    snake.show(screenParams)
                elif event.key == pygame.K_SPACE:
                    paused = not paused
                elif event.key == pygame.K_r:
                    paused = True
                    snake.newSnake()
                    snake.show(screenParams)
                    snake.returnClock().tick(20)
                elif event.key == pygame.K_RIGHT and not paused:
                    snake.moveRight()
                elif event.key == pygame.K_UP and not paused:
                    snake.moveUp()
                elif event.key == pygame.K_LEFT and not paused:
                    snake.moveLeft()
                elif event.key == pygame.K_DOWN and not paused:
                    snake.moveDown()

            pygame.display.update()

    pygame.quit()


if __name__ == "__main__":
    main()
