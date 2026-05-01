/** 48. Rotate Image
You are given an n x n 2D matrix representing an image, rotate the image by 90
degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Constraints:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000 */

#include <cassert>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
  int end = matrix.size() - 1;

  for (int i = 0; i <= end / 2; ++i) {
    for (int c = i; c < end - i; ++c) {
      int val = matrix[end - c][i];

      matrix[end - c][i] = matrix[end - i][end - c];
      matrix[end - i][end - c] = matrix[c][end - i];
      matrix[c][end - i] = matrix[i][c];
      matrix[i][c] = val;
    }
  }
}

int main() {
  vector<vector<int>> matrix0{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> matrix1{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

  vector<vector<int>> ans0{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  vector<vector<int>> ans1{{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

  rotate(matrix0);
  rotate(matrix1);

  assert(matrix0 == ans0);
  assert(matrix1 == ans1);

  return 0;
}
