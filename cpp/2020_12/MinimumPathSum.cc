/* 64. Minimum Path Sum */
/** Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
 *  Note: You can only move either down or right at any point in time.
 *  
 *  Example 1:
 *  Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
 *  Output: 7
 *  Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
 * 
 *  Example 2:
 *  Input: grid = [[1,2,3],[4,5,6]]
 *  Output: 12
 *  
 *  Constraints:
 *  m == grid.length
 *  n == grid[i].length
 *  1 <= m, n <= 200
 *  0 <= grid[i][j] <= 100 **/

#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>

using namespace std;

int sum[201][201];

int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int right;
    int down;

    memset (sum, 101, sizeof(sum));
    sum[m-1][n-1] = 0;

    for (int i = m-1; i >= 0; --i) {
        right = min(m-1, i+1);
        for (int j = n-1; j >= 0; --j) {
            down = min(n-1, j+1);
            sum[i][j] = min(sum[right][j], sum[i][down]) + grid[i][j];
        }
    }

    return sum[0][0];
}

int main() {
    vector<int> r1 {1,3,1};
    vector<int> r2 {1,5,1};
    vector<int> r3 {4,2,1};
    vector<vector<int>> grid0 {r1, r2, r3};

    vector<int> r11 {1,2,3};
    vector<int> r12 {4,5,6};
    vector<vector<int>> grid1 {r11, r12};

    int answer1 = minPathSum(grid0);
    int answer2 = minPathSum(grid1);

    cout << answer1 << endl;
    cout << answer2 << endl;

    return 0;
}

