/** 54. Spiral Matrix
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100 */

#include <cassert>
#include <vector>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  int r = 0, c = 0, idx = 0;
  int r_count = matrix.size(), c_count = matrix[0].size();

  vector<int> result;
  vector<vector<bool>> visited(r_count, vector<bool>(c_count, false));

  for (int step = 0; step < r_count * c_count; ++step) {
    result.push_back(matrix[r][c]);
    visited[r][c] = true;

    int nr = r + dr[idx];
    int nc = c + dc[idx];

    if (nr < 0 || nr >= r_count || nc < 0 || nc >= c_count || visited[nr][nc]) {
      idx = (idx + 1) % 4;
    }

    r += dr[idx];
    c += dc[idx];
  }

  return result;
}

int main() {
  vector<vector<int>> matrix0 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  vector<int> ret0 = spiralOrder(matrix0);
  vector<int> ret1 = spiralOrder(matrix1);

  vector<int> ans0 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
  vector<int> ans1 = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
