"""
419. Battleships in a Board
Given an m x n matrix board where each cell is a battleship 'X' or empty '.'
return the number of the battleships on board.
Battleships can only be placed horizontally or vertically on board.
In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column),
where k can be of any size. At least one horizontal or vertical cell separates between two battleships
(i.e., there are no adjacent battleships).

Example 1:
Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2

Example 2:
Input: board = [["."]]
Output: 0

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is either '.' or 'X'.
"""


from typing import List


class Solution:
    def is_head_of_battleship(self, r: int, c: int, board: List[List[str]]) -> bool:
        if board[r][c] != "X":
            return False

        if r > 0 and board[r - 1][c] == "X":
            return False

        if c > 0 and board[r][c - 1] == "X":
            return False

        return True

    def count_battleships(self, board: List[List[str]]) -> int:
        result, row_length, col_length = 0, len(board), len(board[0])

        for r in range(row_length):
            for c in range(col_length):
                if self.is_head_of_battleship(r, c, board):
                    result += 1

        return result
