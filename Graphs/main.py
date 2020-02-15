import pygame, sys
from graph import Graph

pygame.init()

screen = pygame.display.set_mode((640, 800))

clock = pygame.time.Clock()
clock.tick(10)

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

shapes = []

graph = Graph()

coord1 = (0, 0)
coord2 = (0, 0)

secondClick = False
clickedVertex = None

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE: sys.exit()
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
                                graph.addEdge(clickedVertex, shapes.index(shape), 5)
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
            pygame.draw.line(screen, (255, j[1], j[1]), shapes[i[0]], shapes[j[0]], 5)

    pygame.display.update()
