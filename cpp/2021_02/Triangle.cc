/* 120. Triangle */
/** Given a triangle array, return the minimum path sum from top to bottom.
 *  For each step, you may move to an adjacent number of the row below. 
 *  More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
 * 
 *  Example 1:
 *  Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 *  Output: 11
 *  Explanation: The triangle looks like:
 *      2
 *     3 4
 *    6 5 7
 *   4 1 8 3
 *  The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 * 
 *  Example 2:
 *  Input: triangle = [[-10]]
 *  Output: -10
 * 
 *  Constraints:
 *  1 <= triangle.length <= 200
 *  triangle[0].length == 1
 *  triangle[i].length == triangle[i - 1].length + 1
 *  -10^4 <= triangle[i][j] <= 10^4
 *  Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle? **/

#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
    vector<int> cache(triangle.size(), -1);
    int val1, val2;
    int answer = INT_MAX;

    if (triangle.empty()) return 0;
    cache[0] = triangle[0][0];
    
    for (int i = 1; i < triangle.size(); ++i) {
        val1 = INT_MAX;
        for (int j = 0; j < i; ++j) {
            val2 = cache[j];
            cache[j] = triangle[i][j]+ min(val1, val2);
            val1 = val2;
        }
        cache[i] = val1 + triangle[i][i];
    }

    for (int i = 0; i < triangle.size(); ++i) {
        answer = min(answer, cache[i]);
    }

    return answer;
}

int main() {
    vector<int> row00 {2};
    vector<int> row01 {3,4};
    vector<int> row02 {6,5,7};
    vector<int> row03 {4,1,8,3};
    vector<vector<int>> triangle0 {row00, row01, row02, row03};

    int ans0 = minimumTotal(triangle0);

    vector<int> row10 {-10};
    vector<vector<int>> triangle1 {row10};

    int ans1 = minimumTotal(triangle1);

    cout << ans0 << endl; // 11
    cout << ans1 << endl; // -10

    return 0;
}


