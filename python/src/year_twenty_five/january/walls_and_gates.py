"""
286. Walls and Gates
You are given an m x n grid rooms initialized with these three possible values.
* -1 A wall or an obstacle.
* 0 A gate.
* INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.

Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example 1:
Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Example 2:
Input: rooms = [[-1]]
Output: [[-1]]

Constraints:
m == rooms.length
n == rooms[i].length
1 <= m, n <= 250
rooms[i][j] is -1, 0, or 2^31 - 1.
"""

from collections import deque

INF = 2**31 - 1

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]


class Solution:
    def walls_and_gates(self, rooms: list[list[int]]):
        queue = deque([])

        for i, row in enumerate(rooms):
            for j, val in enumerate(row):
                if val == 0:
                    queue.append((i, j))

        while len(queue) > 0:
            r, c = queue.popleft()

            for i in range(4):
                next_r, next_c = r + dr[i], c + dc[i]

                if (
                    next_r < 0
                    or next_r >= len(rooms)
                    or next_c < 0
                    or next_c >= len(rooms[0])
                    or rooms[next_r][next_c] != INF
                ):
                    continue

                rooms[next_r][next_c] = rooms[r][c] + 1
                queue.append((next_r, next_c))
