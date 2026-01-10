/** 1925. Count Square Sum Triples */
/** A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
 *  Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
 *  
 *  Example 1:
 *  Input: n = 5
 *  Output: 2
 *  Explanation: The square triples are (3,4,5) and (4,3,5).
 * 
 *  Example 2:
 *  Input: n = 10
 *  Output: 4
 *  Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 * 
 *  Constraints : 1 <= n <= 250 **/

#include <iostream>
#include <math.h>

using namespace std;

bool isPerfectSquare(int n) {
    return ceil((double)sqrt(n)) == floor((double)sqrt(n));
}

int countTriples(int n) {
    int count = 0;

    for (int a = 1; a < n/sqrt(2); ++a) {
        for (int b = a; b < n; ++b) {
            int squareSum = a * a + b * b;
            if (squareSum > n * n) break;
            if (!isPerfectSquare(squareSum)) continue;
            if (b == a) {
                count++;
            } else {
                count += 2;
            }
        }
    }

    return count;
}

int main() {
    int ans0 = countTriples(5);
    int ans1 = countTriples(10);

    cout << ans0 << endl; // 2
    cout << ans1 << endl; // 4

    return 0;
}