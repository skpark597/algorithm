"""
931. Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is
either directly below or diagonally left/right.
Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.


Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
"""


class Solution:
    def min_falling_path_sum(self, matrix: list[list[int]]) -> int:
        row_len, col_len = len(matrix), len(matrix[0])
        d = [[101] * col_len for _ in range(row_len)]

        for col in range(col_len):
            d[row_len - 1][col] = matrix[row_len - 1][col]

        for row in range(row_len - 2, -1, -1):
            for col in range(col_len):
                d[row][col] = matrix[row][col] + min(d[row + 1][max(0, col - 1) : min(col_len, col + 2)])

        return min(d[0])
