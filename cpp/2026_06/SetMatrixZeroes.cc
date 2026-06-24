/** 73. Set Matrix Zeroes
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
Could you devise a constant space solution?*/

#include <cassert>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();
  bool zeroRows = false, zeroCols = false;

  for (int c = 0; c < cols; ++c)
    if (matrix[0][c] == 0) zeroRows = true;

  for (int r = 0; r < rows; ++r)
    if (matrix[r][0] == 0) zeroCols = true;

  for (int r = 1; r < rows; ++r) {
    for (int c = 1; c < cols; ++c) {
      if (matrix[r][c] == 0) {
        matrix[r][0] = 0;
        matrix[0][c] = 0;
      }
    }
  }

  for (int r = 1; r < rows; ++r) {
    for (int c = 1; c < cols; ++c) {
      if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
    }
  }

  if (zeroRows)
    for (int c = 0; c < cols; ++c) matrix[0][c] = 0;

  if (zeroCols)
    for (int r = 0; r < rows; ++r) matrix[r][0] = 0;
}

int main() {
  vector<vector<int>> matrix0{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> matrix1{{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  vector<vector<int>> matrix2{{-1}, {2}, {3}};

  setZeroes(matrix0);
  setZeroes(matrix1);
  setZeroes(matrix2);

  vector<vector<int>> ans0{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  vector<vector<int>> ans1{{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};
  vector<vector<int>> ans2{{-1}, {2}, {3}};

  assert(matrix0 == ans0);
  assert(matrix1 == ans1);
  assert(matrix2 == ans2);

  return 0;
}