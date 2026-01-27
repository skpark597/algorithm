/**120. Triangle
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More
formally, if you are on index i on the current row, you may move to either index
i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
above).

Example 2:
Input: triangle = [[-10]]
Output: -10

Constraints:
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4

Follow up: Could you do this using only O(n) extra space, where n is the total
number of rows in the triangle? */

#include <algorithm>
#include <cassert>
#include <climits>
#include <vector>

#include "math.h"

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
  int rows = triangle.size();

  vector<int> prev(rows, 0);
  vector<int> cur(rows, 0);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) {
        cur[j] = prev[j] + triangle[i][j];
      } else if (j == i) {
        cur[j] = prev[j - 1] + triangle[i][j];
      } else {
        cur[j] = min(prev[j - 1], prev[j]) + triangle[i][j];
      }
    }

    prev = cur;
  }

  return *min_element(cur.begin(), cur.end());
}

int main() {
  vector<vector<int>> triangle0 = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  vector<vector<int>> triangle1 = {{-10}};

  int ret0 = minimumTotal(triangle0);
  int ret1 = minimumTotal(triangle1);

  assert(ret0 == 11);
  assert(ret1 == -10);

  return 0;
}