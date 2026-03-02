/** 64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200 */

#include <cassert>
#include <climits>
#include <deque>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>> dp(m, vector<int>(n, INT_MAX));

  dp[0][0] = grid[0][0];

  for (int i = 1; i < m + n - 1; ++i) {
    for (int r = max(0, i - n + 1); r <= min(i, m - 1); ++r) {
      int c = i - r;

      if (r >= 1) dp[r][c] = min(dp[r][c], dp[r - 1][c] + grid[r][c]);
      if (c >= 1) dp[r][c] = min(dp[r][c], dp[r][c - 1] + grid[r][c]);
    }
  }

  return dp[m - 1][n - 1];
}

int main() {
  vector<vector<int>> grid0{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  vector<vector<int>> grid1{{1, 2, 3}, {4, 5, 6}};

  int ret0 = minPathSum(grid0);
  int ret1 = minPathSum(grid1);

  assert(ret0 == 7);
  assert(ret1 == 12);

  return 0;
}
