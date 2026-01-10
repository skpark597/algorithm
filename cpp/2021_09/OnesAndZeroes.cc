/* 474. Ones and Zeroes */
/** You are given an array of binary strings strs and two integers m and n.
 *  Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
 *  A set x is a subset of a set y if all elements of x are also elements of y
 * 
 *  Example 1:
 *  Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
 *  Output: 4
 *  Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
 *  Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
 *  {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
 * 
 *  Example 2:
 *  Input: strs = ["10","0","1"], m = 1, n = 1
 *  Output: 2
 *  Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 * 
 *  Constraints:
 *  1 <= strs.length <= 600
 *  1 <= strs[i].length <= 100
 *  strs[i] consists only of digits '0' and '1'.
 *  1 <= m, n <= 100 **/


#include <vector>
#include <string>
#include <math.h>
#include <iostream>
#include <cstring>

using namespace std;

vector<int> getCounts(string str) {
    vector<int> counts(2);
    int count = 0;

    for (char c : str) {
        if (c == '0') count++;
    }

    counts[0] = count;
    counts[1] = str.length() - count;
    return counts;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int s = strs.size();
    int cache[s+1][m+1][n+1];

    memset(cache, 0, sizeof(cache));

    for (int i = s-1; i >= 0; --i) {
        vector<int> counts = getCounts(strs[i]);

        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (counts[0] > j || counts[1] > k) {
                    cache[i][j][k] = cache[i+1][j][k];
                } else {
                    cache[i][j][k] = max(1 + cache[i+1][j-counts[0]][k-counts[1]], cache[i+1][j][k]);
                }
            }
        }
    }

    return cache[0][m][n];
}

int main() {
    vector<string> strs0 = {"10","0001","111001","1","0"};
    int ans0 = findMaxForm(strs0, 5, 3);

    vector<string> strs1 {"10","0","1"};
    int ans1 = findMaxForm(strs1, 1, 1);

    cout << ans0 << endl; // 4
    cout << ans1 << endl; // 2

    return 0;
}


