class Train:
    def __init__(self, speed, startingPoint, endPoint, routeWeight):
        self.speed = speed
        self.currentSpeed = 0
        self.offset = 0
        self.startingPoint = startingPoint
        self.endPoint = endPoint
        self.routeWeight = routeWeight
        
    def calculateCurrentSpeed(self):
        if offset/routeWeight <= 0.1:
            self.currentSpeed = self.speed * (offset/routeWeight) / 0.1
        elif offset/routeWeight >= 0.9:
            self.currentSpeed = self.speed *  (1 - (offset/routeWeight)) / 0.1
