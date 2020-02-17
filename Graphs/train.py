from functions import calculateMagnitude

class Train:
    def __init__(self, speed, startingPoint, endPoint, routeWeight):
        self.speed = speed
        self.currentSpeed = 0
        self.offset = 0
        self.startingPoint = startingPoint
        self.endPoint = endPoint
        self.currentPoint = [self.startingPoint[0], self.startingPoint[1]]
        self.routeWeight = routeWeight
        self.speedX = abs(self.startingPoint[0] - self.endPoint[0]) / (self.routeWeight / self.speed)
        self.speedY = abs(self.startingPoint[1] - self.endPoint[1]) / (self.routeWeight / self.speed)

    def calculateCurrentSpeed(self):
        if int(self.offset) == 0 or int(self.offset) == self.routeWeight:
            self.currentSpeed = 0.1 * self.speed
        elif self.offset/self.routeWeight <= 0.2:
            self.currentSpeed = self.speed * (self.offset/self.routeWeight) / 0.2
        elif self.offset/self.routeWeight >= 0.8:
            self.currentSpeed = self.speed *  (1 - (self.offset/self.routeWeight)) / 0.8
        else:
            self.currentSpeed = self.speed
