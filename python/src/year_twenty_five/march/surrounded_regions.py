"""
130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
"""

from typing import List

# up, right, down, left
directions = [[-1, 0], [0, 1], [1, 0], [0, -1]]


class Solution:
    def dfs(self, board: List[List[str]], region: set, visited: set, r: int, c: int):
        is_surrounded, visited[r][c] = True, True
        region.add((r, c))

        for dr, dc in directions:
            next_r, next_c = r + dr, c + dc

            if next_r < 0 or next_r >= len(board) or next_c < 0 or next_c >= len(board[0]):
                is_surrounded = False
                continue

            if board[next_r][next_c] == "X" or visited[next_r][next_c]:
                continue

            is_surrounded &= self.dfs(board, region, visited, next_r, next_c)

        return is_surrounded

    def solve(self, board: List[List[str]]):
        visited = [[False for _ in range(len(board[0]))] for _ in range(len(board))]

        for r in range(len(board)):
            for c in range(len(board[0])):
                region = set()

                if board[r][c] == "X" or visited[r][c]:
                    continue

                if not self.dfs(board, region, visited, r, c):
                    continue

                for cell in region:
                    board[cell[0]][cell[1]] = "X"
