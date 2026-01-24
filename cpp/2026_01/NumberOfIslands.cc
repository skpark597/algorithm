/** 200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and
'0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically. You may assume all four edges of the grid are all
surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'. */

#include <cassert>
#include <vector>

using namespace std;

static const int dr[4] = {0, 1, 0, -1};
static const int dc[4] = {1, 0, -1, 0};

bool canVisit(vector<vector<char>>& grid, int r, int c) {
  return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
         grid[r][c] == '1';
}

void dfs(vector<vector<char>>& grid, int r, int c) {
  grid[r][c] = '2';

  for (int i = 0; i < 4; ++i) {
    int nr = r + dr[i], nc = c + dc[i];
    if (canVisit(grid, nr, nc)) dfs(grid, nr, nc);
  }
}

int numIslands(vector<vector<char>>& grid) {
  int result = 0;
  int rows = grid.size();
  int cols = grid[0].size();

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (canVisit(grid, r, c)) {
        dfs(grid, r, c);
        result++;
      }
    }
  }

  return result;
}

int main() {
  vector<vector<char>> grid0 = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
  vector<vector<char>> grid1 = {{'1', '1', '0', '0', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '1', '0', '0'},
                                {'0', '0', '0', '1', '1'}};

  int ret0 = numIslands(grid0);
  int ret1 = numIslands(grid1);

  assert(ret0 == 1);
  assert(ret1 == 3);

  return 0;
}
