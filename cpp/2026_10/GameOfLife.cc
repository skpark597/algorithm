/**289. Game of Life
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the
British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead
(represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following
four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state of the board is determined by applying the above rules simultaneously to every cell in the current state
of the m x n grid board. In this process, births and deaths occur simultaneously.

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
* Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells
first and then use their updated values to update other cells.
* In this question, we represent the board using a 2D
array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border
of the array (i.e., live cells reach the border). How would you address these problems? */

#include <cassert>
#include <vector>

using namespace std;

int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void gameOfLife(vector<vector<int>>& board) {
  int m = board.size(), n = board[0].size();

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      int live = 0;

      for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i], nc = c + dc[i];

        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
        if (board[nr][nc] == 1 || board[nr][nc] == 2) live++;
      }

      if (board[r][c] == 1 && (live < 2 || live > 3)) board[r][c] = 2;
      if (board[r][c] == 0 && live == 3) board[r][c] = 3;
    }
  }

  for (int r = 0; r < m; ++r) {
    for (int c = 0; c < n; ++c) {
      if (board[r][c] == 2) board[r][c] = 0;
      if (board[r][c] == 3) board[r][c] = 1;
    }
  }
}

int main() {
  vector<vector<int>> board0{{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  vector<vector<int>> board1{{1, 1}, {1, 0}};

  vector<vector<int>> ans0{{0, 0, 0}, {1, 0, 1}, {0, 1, 1}, {0, 1, 0}};
  vector<vector<int>> ans1{{1, 1}, {1, 1}};

  gameOfLife(board0);
  gameOfLife(board1);

  assert(board0 == ans0);
  assert(board1 == ans1);

  return 0;
}
