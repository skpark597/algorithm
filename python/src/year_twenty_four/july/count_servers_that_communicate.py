"""
1267. Count Servers that Communicate
You are given a map of a server center, represented as a m * n integer matrix grid,
where 1 means that on that cell there is a server and 0 means that it is no server.
Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.


Constraints:
m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
"""


class Solution:
    def count_servers(self, grid: list[list[int]]) -> int:
        transposed = list(map(list, zip(*grid)))

        communicated_in_row = {
            (row_idx, col_idx)
            for row_idx, row in enumerate(grid)
            for col_idx, value in enumerate(row)
            if row.count(1) >= 2 and value == 1
        }

        communicated_in_col = {
            (col_idx, row_idx)
            for row_idx, row in enumerate(transposed)
            for col_idx, value in enumerate(row)
            if row.count(1) >= 2 and value == 1
        }

        return len(set(communicated_in_row) | set(communicated_in_col))

    def count_servers_2(self, grid: list[list[int]]) -> int:
        servers, rows, cols = 0, {}, {}

        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value == 1:
                    rows[i] = False if i not in rows else True
                    cols[j] = False if j not in cols else True

        for i, row in enumerate(grid):
            for j, value in enumerate(row):
                if value == 1 and (rows.get(i, False) or cols.get(j, False)):
                    servers += 1

        return servers
