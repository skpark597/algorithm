"""
311. Sparse Matrix Multiplication
Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of mat1 x mat2.
You may assume that multiplication is always possible.

Example 1:
Input: mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
Output: [[7,0,0],[-7,0,3]]

Example 2:
Input: mat1 = [[0]], mat2 = [[0]]
Output: [[0]]


Constraints:
m == mat1.length
k == mat1[i].length == mat2.length
n == mat2[i].length
1 <= m, n, k <= 100
-100 <= mat1[i][j], mat2[i][j] <= 100
"""


class Solution:
    def multiply(self, mat1: list[list[int]], mat2: list[list[int]]) -> list[list[int]]:
        m, k, n = len(mat1), len(mat1[0]), len(mat2[0])
        answer = [[0] * n for _ in range(m)]
        nonzeros1 = {i: {j: val for j, val in enumerate(row)} for i, row in enumerate(mat1)}
        nonzeros2 = {i: {j: val for j, val in enumerate(row)} for i, row in enumerate(mat2)}

        for i, cols in nonzeros1.items():
            for j, val1 in cols.items():
                if j not in nonzeros2:
                    continue

                for k, val2 in nonzeros2[j].items():
                    answer[i][k] += val1 * val2

        return answer
