from math import sqrt

def calculateMagnitude(point1, point2):
    return round(sqrt(abs(point1[0] - point2[0])**2 + abs(point1[1] - point2[1])**2))

def calculateMedianPoint(pointFrom, pointTo):
    return (abs(pointTo[0] - pointFrom[0]) // 2 + min(pointFrom[0], pointTo[0]),
    abs(pointTo[1] - pointFrom[1]) // 2 + min(pointFrom[1], pointTo[1]))
