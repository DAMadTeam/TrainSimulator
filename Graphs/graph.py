class Graph:
    def __init__(self):
        self.adjDict = {}
        self.count = len(self.adjDict)

    def addVertex(self, idNumber):
        self.adjDict[idNumber] = []
        self.count = len(self.adjDict)

    def addEdge(self, idFrom, idTo, weight):
        self.adjDict[idFrom].append((idTo, weight))
