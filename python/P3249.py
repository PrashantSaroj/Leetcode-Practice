from typing import List


class Node:
    def __init__(self, id: int) -> None:
        self.id = id
        self.neighbours: List[Node] = []
        if self.id == 0:
            self.parentId = -1
        else:
            self.parentId = None

    def insertNeighbour(self, node) -> None:
        self.neighbours.append(node)

    def calculateSize(self) -> int:
        self.size = 1
        for neighbour in self.neighbours:
            if neighbour.id != self.parentId:
                self.size += neighbour.calculateSize()
        return self.size

    def augmentParent(self) -> None:
        for neighbour in self.neighbours:
            if neighbour.id != self.parentId:
                neighbour.parentId = self.id
                neighbour.augmentParent()

    def isGood(self) -> bool:
        targetSize = None
        for neighbour in self.neighbours:
            if neighbour.id != self.parentId:
                if targetSize is None:
                    targetSize = neighbour.size
                else:
                    if neighbour.size != targetSize:
                        return False
        return True


class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        nodeMap = {i: Node(i) for i in range(len(edges) + 1)}
        for edge in edges:
            node1, node2 = nodeMap[edge[0]], nodeMap[edge[1]]
            node1.insertNeighbour(node2)
            node2.insertNeighbour(node1)

        # traverse tree and augment sizes
        nodeMap[0].augmentParent()
        nodeMap[0].calculateSize()

        goodNodes = 0
        for _, node in nodeMap.items():
            if node.isGood():
                goodNodes += 1
        return goodNodes


edges1 = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 5], [2, 6]]
edges2 = [[0, 1], [1, 2], [1, 3], [1, 4], [0, 5], [5, 6],
          [6, 7], [7, 8], [0, 9], [9, 10], [9, 12], [10, 11]]
edges3 = [[0, 1], [1, 2], [2, 3], [3, 4], [0, 5], [1, 6], [2, 7], [3, 8]]

print(Solution().countGoodNodes(edges1))
print(Solution().countGoodNodes(edges2))
print(Solution().countGoodNodes(edges3))
