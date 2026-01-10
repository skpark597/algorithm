/* 279. Perfect Squares */
/** Given an integer n, return the least number of perfect square numbers that sum to n.
 *  A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. 
 *  For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 * 
 *  Example 1:
 *  Input: n = 12
 *  Output: 3
 *  Explanation: 12 = 4 + 4 + 4.
 * 
 *  Example 2:
 *  Input: n = 13
 *  Output: 2
 *  Explanation: 13 = 4 + 9.
 * 
 *  Constraints: 1 <= n <= 10^4 **/

#include <vector>
#include <iostream>
#include <cstring>
#include <math.h>
#include <limits.h>

using namespace std;

const static int cacheSize = 10001;
int cache[cacheSize];

int numSquares(int n) {
    for (int i = 0; i < cacheSize; ++i) {
        cache[i] = INT_MAX;
    }
    cache[0] = 0;
    
    for (int i = 1 ; i <= n; ++i) {
        for (int j = 1; j <= sqrt(i); ++j) {
            cache[i] = min(cache[i], cache[i-j*j] + 1);
        }
    }

    return cache[n];
}

int main() {
    int n0 = 12;
    int n1 = 13;

    int ans0 = numSquares(n0);
    int ans1 = numSquares(n1);

    cout << ans0 << endl;
    cout << ans1 << endl;

    return 0;
}

