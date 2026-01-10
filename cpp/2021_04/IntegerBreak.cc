/** 343. Integer Break */
/** Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
 *  Return the maximum product you can get.
 * 
 *  Example 1:
 *  Input: n = 2
 *  Output: 1
 *  Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 *  Example 2:
 *  Input: n = 10
 *  Output: 36
 *  Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 *  Constraints: 2 <= n <= 58  */

#include <iostream>
#include <cstring>
using namespace std;

int cache[59];

// F(m) = max(F(i) * F(m-i)) (range 2 <= i <= m/2)
int integerBreak(int n) {
    if (n <= 2) return 1;
    if (n == 3) return 2;

    memset(cache, 0, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;

    for (int i = 4; i <= n; ++i) {
        for (int j = 2; j <= i/2; ++j) {
            cache[i] = max(cache[i], cache[j] * cache[i-j]);
        }
    }

    return cache[n];
}

int main() {
    int ans0 = integerBreak(2);
    int ans1 = integerBreak(10);
    int ans2 = integerBreak(6);

    cout << ans0 << endl; // 1
    cout << ans1 << endl; // 36
    cout << ans2 << endl; // 9

    return 0;
}