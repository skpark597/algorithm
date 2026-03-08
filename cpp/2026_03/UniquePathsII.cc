/** 63. Unique Paths II
You are given an m x n integer array grid. There is a robot initially located at
the top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 *
10^9.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

Constraints:
m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1 */

#include <cassert>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
  int r_len = grid.size(), c_len = grid[0].size();
  vector<int> dp(c_len, 0);

  dp[0] = grid[0][0] == 1 ? 0 : 1;

  for (int r = 0; r < r_len; ++r) {
    for (int c = 0; c < c_len; ++c) {
      if (grid[r][c] == 1) {
        dp[c] = 0;
      } else if (c > 0) {
        dp[c] += dp[c - 1];
      }
    }
  }

  return dp[c_len - 1];
}

int uniquePathsWithObstacles_Diagonal(vector<vector<int>>& grid) {
  /**
   * [Initial Approach] 2D DP with Diagonal Traversal
   * - Method: Uses the property (r + c = i) to traverse the grid diagonally and
   * compute paths
   * - Pros: A unique approach that is potentially useful for parallelization
   * - Cons: Space complexity is O(R*C). Can be further optimized to O(C) using
   * a 1D array
   */

  int r_len = grid.size(), c_len = grid[0].size();
  vector<vector<int>> dp(r_len, vector<int>(c_len, 0));
  dp[0][0] = grid[0][0] == 1 ? 0 : 1;

  for (int i = 0; i < r_len + c_len - 1; ++i) {
    for (int r = 0; r < r_len; ++r) {
      int c = i - r;

      if (c < 0 || c >= c_len || grid[r][c] == 1) continue;
      if (c > 0) dp[r][c] += dp[r][c - 1];
      if (r > 0) dp[r][c] += dp[r - 1][c];
    }
  }

  return dp[r_len - 1][c_len - 1];
}

int main() {
  vector<vector<int>> grid0{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> grid1{{0, 1}, {0, 0}};
  vector<vector<int>> grid2{{0, 0}, {0, 1}};
  vector<vector<int>> grid3{{0}};

  int ret0 = uniquePathsWithObstacles(grid0);
  int ret1 = uniquePathsWithObstacles(grid1);
  int ret2 = uniquePathsWithObstacles(grid2);
  int ret3 = uniquePathsWithObstacles(grid3);

  assert(ret0 == 2);
  assert(ret1 == 1);
  assert(ret2 == 0);
  assert(ret3 == 1);

  return 0;
}
