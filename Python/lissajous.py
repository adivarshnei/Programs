import pygame
import math
import sys

pygame.init()

dimensions = [400, 400]
position1 = [200, 200]
position2 = [400, 200]
position3 = [600, 200]
position4 = [200, 400]
position5 = [200, 600]
bgColor = (31, 33, 42)
running = True
updateElem = 1
pauseStatus = False

circData = {
    'radius': 30,
    'thickness': 3
}

screen = pygame.display.set_mode(dimensions)
clock = pygame.time.Clock()

def drawBaseCirc(position):
    pygame.draw.circle(
        screen, 
        (63, 97, 81), 
        (position[1] / 2, position[1] / 2), 
        circData['radius'],
        circData['thickness']
    )

def drawMoveCirc(i, position):
    pygame.draw.circle(
        screen, 
        (180, 180, 180), 
        (
            (circData['radius'] - circData['thickness'] / 2) * math.cos(i) + position[0] / 2,
            (circData['radius'] - circData['thickness'] / 2) * math.sin(i) + position[1] / 2
        ), 
        circData['thickness']
    )

def drawLines(i, position):
    lineX = [
        ((circData['radius'] - circData['thickness'] / 2) * math.cos(i) + position[0] / 2, 0),
        ((circData['radius'] - circData['thickness'] / 2) * math.cos(i) + position[0] / 2, dimensions[1])
    ]

    lineY = [
        (0, (circData['radius'] - circData['thickness'] / 2) * math.sin(i) + position[1] / 2),
        (dimensions[0], (circData['radius'] - circData['thickness'] / 2) * math.sin(i) + position[1] / 2)
    ]

    pygame.draw.line(
        screen,
        (180, 180, 180),
        lineX[0],
        lineX[1]
    )

    pygame.draw.line(
        screen,
        (180, 180, 180),
        lineY[0],
        lineY[1]
    )

def elemUpdate():
    updateElem += 1

def drawCircs(i):
    screen.fill(bgColor)
    drawBaseCirc(position1)
    drawBaseCirc(position2)
    drawBaseCirc(position3)
    drawBaseCirc(position4)
    drawBaseCirc(position5)
    drawMoveCirc(i / 10, position1)
    drawMoveCirc(i / 10, position2)
    drawMoveCirc(i / 10, position3)
    drawMoveCirc(i / 10, position4)
    drawMoveCirc(i / 10, position5)
    drawLines(i / 10, position1)
    drawLines(i / 10, position2)
    drawLines(i / 10, position3)
    drawLines(i / 10, position4)
    drawLines(i / 10, position5)

    pygame.time.delay(60)
    pygame.display.update()

screen.fill(bgColor)

while running:
    clock.tick(60)

    keys = pygame.key.get_pressed()

    pygame.time.delay(5)
    
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if keys[pygame.K_e]:
        sys.exit(0)

    if keys[pygame.K_SPACE]:
        pauseStatus = not pauseStatus

    if not pauseStatus:
        updateElem += 1
        drawCircs(updateElem)

    pygame.display.update()

pygame.quit()
# %%
