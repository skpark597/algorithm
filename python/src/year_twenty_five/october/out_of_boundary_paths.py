"""
576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn].
You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary).
You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary.
Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6

Example 2:
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12


Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow < m
0 <= startColumn < n
"""

drs = [(-1, 0), (0, 1), (1, 0), (0, -1)]
mod = 10**9 + 7


class Solution:
    # d[i][j][k] = number of paths from (i, j) alllowed to move k times

    def find_paths_old(self, m: int, n: int, max_move: int, start_row: int, start_column: int) -> int:
        if max_move == 0:
            return 0

        dp = [[[0] * (max_move + 1) for _ in range(n)] for _ in range(m)]

        for i in range(m):
            dp[i][0][1] += 1
            dp[i][n - 1][1] += 1

        for j in range(n):
            dp[0][j][1] += 1
            dp[m - 1][j][1] += 1

        for k in range(2, max_move + 1):
            for i in range(m):
                for j in range(n):
                    for dr, dc in drs:
                        ni, nj = i + dr, j + dc

                        if 0 <= ni < m and 0 <= nj < n:
                            dp[i][j][k] = (dp[i][j][k] + dp[ni][nj][k - 1]) % mod
                        else:
                            dp[i][j][k] = (dp[i][j][k] + 1) % mod

        return dp[start_row][start_column][max_move] % mod

    # d[i][j] = number of paths that reach (i, j)

    def find_paths(self, m: int, n: int, max_move: int, start_row: int, start_column: int) -> int:
        dp = [[0] * n for _ in range(m)]

        dp[start_row][start_column] = 1
        count = 0

        for _ in range(max_move):
            new_dp = [[0] * n for _ in range(m)]

            for i in range(m):
                for j in range(n):
                    if dp[i][j] == 0:
                        continue

                    for dr, dc in drs:
                        ni, nj = i + dr, j + dc

                        if 0 <= ni < m and 0 <= nj < n:
                            new_dp[ni][nj] = (new_dp[ni][nj] + dp[i][j]) % mod
                        else:
                            count = (count + dp[i][j]) % mod
            dp = new_dp

        return count
