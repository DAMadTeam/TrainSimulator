import pygame, sys
from graph import Graph
from train import Train
import functions as fn

pygame.init()

screen = pygame.display.set_mode((640, 800))

clock = pygame.time.Clock()
clock.tick(30)

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

shapes = []

graph = Graph()

secondClick = False
clickedVertex = None

font = pygame.font.SysFont('arial', 20)

train = Train(1, (10, 10), (600, 600), fn.calculateMagnitude((10, 10), (600, 10)))
trains = []

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE: sys.exit()
            if event.key == pygame.K_SPACE and clickedVertex != None:
                for i in graph.adjDict[clickedVertex]:
                    trains.append(Train(2, shapes[clickedVertex], shapes[i[0]], fn.calculateMagnitude(shapes[clickedVertex], shapes[i[0]])))
        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 3:
                shapes.append(pygame.mouse.get_pos())
                graph.addVertex(graph.count)

            elif event.button == 1:
                if not secondClick:
                    for shape in shapes:
                        if (shape[0] - 10 <= pygame.mouse.get_pos()[0] <= shape[0] + 10
                        and shape[1] - 10 <= pygame.mouse.get_pos()[1] <= shape[1] + 10):
                            clickedVertex = shapes.index(shape)
                            secondClick = True
                elif secondClick:
                    for shape in shapes:
                        if (shape[0] - 10 <= pygame.mouse.get_pos()[0] <= shape[0] + 10
                        and shape[1] - 10 <= pygame.mouse.get_pos()[1] <= shape[1] + 10):
                            if clickedVertex != shapes.index(shape):
                                graph.addEdge(clickedVertex, shapes.index(shape), fn.calculateMagnitude(shapes[clickedVertex], shape))
                            secondClick = False
                            clickedVertex = None

    screen.fill(BLACK)

    for shape in shapes:
        if shapes.index(shape) == clickedVertex:
            pygame.draw.circle(screen, GREEN, shape, 10)
        else: pygame.draw.circle(screen, WHITE, shape, 10)

        if (shape[0] - 10 <= pygame.mouse.get_pos()[0] <= shape[0] + 10
        and shape[1] - 10 <= pygame.mouse.get_pos()[1] <= shape[1] + 10):
            pygame.draw.circle(screen, RED, shape, 10, 1)

    for i in graph.adjDict.items():
        for j in i[1]:
            pygame.draw.line(screen, RED, shapes[i[0]], shapes[j[0]], 5)
            text = font.render(str(j[1]), 1, WHITE)
            screen.blit(text, fn.calculateMedianPoint(shapes[i[0]], shapes[j[0]]))

    for train in trains:
        pygame.draw.circle(screen, RED, (int(train.currentPoint[0]), int(train.currentPoint[1])), 20)
        train.offset = fn.calculateMagnitude(train.currentPoint, train.startingPoint)
        train.calculateCurrentSpeed()
        if int(train.currentPoint[0]) != train.endPoint[0] and int(train.currentPoint[1]) != train.endPoint[1]:
            if train.endPoint[0] - train.startingPoint[0] > 0:
                train.currentPoint[0] += train.speedX
            else:
                train.currentPoint[0] -= train.speedX
            if train.endPoint[1] - train.startingPoint[1] > 0:
                train.currentPoint[1] += train.speedY
            else:
                train.currentPoint[1] -= train.speedY

    pygame.display.update()
