"""
1135. Connecting Cities With Minimum Cost
There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi]
indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities.
If it is impossible to connect all the n cities, return -1,
The cost is the sum of the connections' costs used.

Example 1:
Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
Output: 6
Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

Example 2:
Input: n = 4, connections = [[1,2,3],[3,4,4]]
Output: -1
Explanation: There is no way to connect all cities even if all edges are used.

Constraints:
1 <= n <= 10^4
1 <= connections.length <= 10^4
connections[i].length == 3
1 <= xi, yi <= n
xi != yi
0 <= costi <= 10^5
"""


class Solution:
    parents: list[int]
    ranks: list[int]
    num_components: int

    def find(self, x: int) -> int:
        if x != self.parents[x]:
            return self.find(self.parents[x])

        return x

    def union(self, x: int, y: int):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return False

        if self.ranks[root_x] < self.ranks[root_y]:
            self.parents[root_x] = root_y
        elif self.ranks[root_y] < self.ranks[root_x]:
            self.parents[root_y] = root_x
        else:
            self.parents[root_x] = root_y
            self.ranks[root_y] += 1

        self.num_components -= 1

        return True

    def minimum_cost(self, n: int, connections: list[list[int]]) -> int:
        self.parents = [i for i in range(n + 1)]
        self.ranks = [0] * (n + 1)
        self.num_components = n

        edges = sorted(connections, key=lambda x: x[2])
        min_cost = 0

        for x, y, w in edges:
            if self.union(x, y):
                min_cost += w

        return min_cost if self.num_components == 1 else -1
