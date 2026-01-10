"""
73. Set Matrix Zeroes
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.


Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
"""


class Solution:
    def set_zeroes(self, matrix: list[list[int]]):
        row_len, col_len = len(matrix), len(matrix[0])
        row_idxs, col_idxs = set(), set()

        for i in range(row_len):
            for j in range(col_len):
                if matrix[i][j] == 0:
                    row_idxs.add(i)
                    col_idxs.add(j)

        for i in row_idxs:
            for j in range(col_len):
                matrix[i][j] = 0

        for j in col_idxs:
            for i in range(row_len):
                matrix[i][j] = 0
