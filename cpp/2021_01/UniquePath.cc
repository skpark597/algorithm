/* 62. Unique Paths */
/** A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 *  The robot can only move either down or right at any point in time. 
 *  The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 *  How many possible unique paths are there?
 *  
 *  Example 1:
 *  Input: m = 3, n = 7
 *  Output: 28
 * 
 *  Example 2:
 *  Input: m = 3, n = 2
 *  Output: 3
 *  Explanation:
 *  From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
 *  1. Right -> Down -> Down
 *  2. Down -> Down -> Right
 *  3. Down -> Right -> Down
 * 
 *  Example 3:
 *  Input: m = 7, n = 3
 *  Output: 28
 * 
 *  Example 4:
 *  Input: m = 3, n = 3
 *  Output: 6
 * 
 *  Constraints:
 *  1 <= m, n <= 100
 *  It's guaranteed that the answer will be less than or equal to 2 * 10^9 **/

#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cache[101][101];

int uniquePaths(int m, int n) {
    memset(cache, 0, sizeof(cache));
    cache[m][n-1] = 1;

    for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            cache[i][j] = cache[i+1][j] + cache[i][j+1];
        }
    }

    return cache[0][0];
}

int main() {
    int ans0 = uniquePaths(3, 7);
    int ans1 = uniquePaths(3, 2);
    int ans2 = uniquePaths(7, 3);
    int ans3 = uniquePaths(3, 3);

    cout << ans0 << endl; // 28
    cout << ans1 << endl; // 3
    cout << ans2 << endl; // 28
    cout << ans3 << endl; // 6

    return 0;
}


