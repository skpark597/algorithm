/** 130. Surrounded Regions
You are given an m x n matrix board containing letters 'X' and 'O', capture
regions that are surrounded:

* Connect: A cell is connected to adjacent cells horizontally or vertically.
* Region: To form a region connect every 'O' cell.
* Surround: A region is surrounded if none of the 'O' cells in that region are
on the edge of the board. Such regions are completely enclosed by 'X' cells. To
capture a surrounded region, replace all 'O's with 'X's in-place within the
original board. You do not need to return anything.

Example 1:
Input: board =
[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output:
[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:
In the above diagram, the bottom region is not captured because it is on the
edge of the board and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]

Constraints:
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'. */

#include <cassert>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int m, n;

vector<vector<bool>> visited;

bool dfs(vector<vector<char>>& board, vector<pair<int, int>>& coords, int r,
         int c) {
  coords.push_back({r, c});
  visited[r][c] = true;

  bool meetEdge = r == 0 || r == m - 1 || c == 0 || c == n - 1;

  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i], nc = c + dc[i];

    if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] ||
        board[nr][nc] == 'X')
      continue;

    if (dfs(board, coords, nr, nc)) meetEdge = true;
  }

  return meetEdge;
}

void solve(vector<vector<char>>& board) {
  m = board.size(), n = board[0].size();
  visited.assign(m, vector<bool>(n, false));

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (visited[i][j] || board[i][j] == 'X') continue;
      vector<pair<int, int>> coords;

      if (dfs(board, coords, i, j)) continue;

      for (auto& coord : coords) {
        board[coord.first][coord.second] = 'X';
      }
    }
  }
}

int main() {
  vector<vector<char>> board0{{'X', 'X', 'X', 'X'},
                              {'X', 'O', 'O', 'X'},
                              {'X', 'X', 'O', 'X'},
                              {'X', 'O', 'X', 'X'}};
  vector<vector<char>> board1{{'X'}};
  vector<vector<char>> board2{
      {'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'}};

  vector<vector<char>> ans0{{'X', 'X', 'X', 'X'},
                            {'X', 'X', 'X', 'X'},
                            {'X', 'X', 'X', 'X'},
                            {'X', 'O', 'X', 'X'}};
  vector<vector<char>> ans1{{'X'}};
  vector<vector<char>> ans2{
      {'O', 'O', 'O', 'O', 'X', 'X'}, {'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'X', 'O'},
      {'O', 'X', 'O', 'X', 'O', 'O'}, {'O', 'X', 'O', 'O', 'O', 'O'}};

  solve(board0);
  solve(board1);
  solve(board2);

  assert(board0 == ans0);
  assert(board1 == ans1);
  assert(board2 == ans2);

  return 0;
}
