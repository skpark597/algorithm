"""
2812. Find the Safest Path in a Grid
You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
A cell containing a thief if grid[r][c] = 1
An empty cell if grid[r][c] = 0
You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.

Example 1:
Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
Output: 0
Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).

Example 2:
Input: grid = [[0,0,1],[0,0,0],[0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 2) is cell (0, 0). The distance between them is | 0 - 0 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.

Example 3:
Input: grid = [[0,0,0,1],[0,0,0,0],[0,0,0,0],[1,0,0,0]]
Output: 2
Explanation: The path depicted in the picture above has a safeness factor of 2 since:
- The closest cell of the path to the thief at cell (0, 3) is cell (1, 2). The distance between them is | 0 - 1 | + | 3 - 2 | = 2.
- The closest cell of the path to the thief at cell (3, 0) is cell (3, 2). The distance between them is | 3 - 3 | + | 0 - 2 | = 2.
It can be shown that there are no other paths with a higher safeness factor.


Constraints:
1 <= grid.length == n <= 400
grid[i].length == n
grid[i][j] is either 0 or 1.
There is at least one thief in the grid.
"""

import sys
from collections import deque


class Solution:
    dirs = [(-1, 0), (0, 1), (1, 0), (0, -1)]

    def find_safeness(self, n: int, grid: list[list[int]]):
        thieves = [(r, c) for r in range(n) for c in range(n) if grid[r][c] == 1]
        safeness = [[sys.maxsize] * n for _ in range(n)]

        for r, c in thieves:
            safeness[r][c] = 0

        queue = deque(thieves)

        while queue:
            r, c = queue.popleft()

            for dr, dc in self.dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n and safeness[nr][nc] > safeness[r][c] + 1:
                    safeness[nr][nc] = safeness[r][c] + 1
                    queue.append((nr, nc))

        return safeness

    def has_safe_path(self, n: int, safeness: list[list[int]], factor: int):
        if safeness[0][0] < factor or safeness[n - 1][n - 1] < factor:
            return False

        queue, seen = deque([(0, 0)]), set([(0, 0)])

        while queue:
            r, c = queue.popleft()

            if r == n - 1 and c == n - 1:
                return True

            for dr, dc in self.dirs:
                nr, nc = r + dr, c + dc

                if 0 <= nr < n and 0 <= nc < n and (nr, nc) not in seen and safeness[nr][nc] >= factor:
                    queue.append((nr, nc))
                    seen.add((nr, nc))

        return False

    def maximum_safeness_factor(self, grid: list[list[int]]) -> int:
        n = len(grid)
        safeness = self.find_safeness(n, grid)

        left, right = 0, 2 * (n - 1)

        while left <= right:
            mid = (left + right) // 2

            if self.has_safe_path(n, safeness, mid):
                left = mid + 1
            else:
                right = mid - 1

        return right
