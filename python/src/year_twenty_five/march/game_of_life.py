"""
289. Game of Life
According to Wikipedia's article:
"The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970"

The board is made up of an m x n grid of cells, where each cell has an initial state:
live (represented by a 1) or dead (represented by a 0).
Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
* Any live cell with fewer than two live neighbors dies as if caused by under-population.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by over-population.
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state of the board is determined by applying the above rules simultaneously
to every cell in the current state of the m x n grid board. In this process, births and deaths occur simultaneously.
Given the current state of the board, update the board to reflect its next state.

Note that you do not need to return anything.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] is 0 or 1.


Follow up:
Could you solve it in-place? Remember that the board needs to be updated simultaneously:
You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array.
In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array
(i.e., live cells reach the border). How would you address these problems?
"""

from typing import List


directions = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]


class Solution:
    def count_of_live_cells(self, board: List[List[int]], r: int, c: int):
        result = 0

        for direction in directions:
            next_r, next_c = r + direction[0], c + direction[1]

            if next_r < 0 or next_r >= len(board) or next_c < 0 or next_c >= len(board[0]):
                continue

            if board[next_r][next_c] in (1, 2):
                result += 1

        return result

    def mark_cell_for_update(self, board: List[List[int]]):
        for r in range(len(board)):
            for c in range(len(board[0])):
                count = self.count_of_live_cells(board, r, c)

                if board[r][c] == 1 and count not in (2, 3):
                    board[r][c] = 2
                elif board[r][c] == 0 and count == 3:
                    board[r][c] = 3

    def update_cells(self, board: List[List[int]]):
        for r in range(len(board)):
            for c in range(len(board[0])):
                if board[r][c] == 2:
                    board[r][c] = 0
                elif board[r][c] == 3:
                    board[r][c] = 1

    def game_of_life(self, board: List[List[int]]):
        self.mark_cell_for_update(board)
        self.update_cells(board)
