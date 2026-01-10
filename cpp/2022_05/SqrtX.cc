/* Since the return type is an integer, the decimal digits are truncated,and
 * only the integer part of the result is returned.
 * Note : You are not allowed to use any built-in exponent function or operator,
 * such as pow(x, 0.5) or x ** 0.5.
 *
 * Example 1 :
 * Input : x = 4 Output : 2
 *
 * Example 2 :
 * Input : x = 8 Output : 2 Explanation : The square root of 8 is 2.82842...,
 * and since the decimal part is truncated, 2 is returned.
 *
 * Constraints: 0 <= x <= 2^31 - 1 */

#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x) {
  long long left = 1;
  long long right = x;

  while (left <= right) {
    long long middle = left + (right - left) / 2;

    if (middle * middle > x) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  return right;
}

int main() {
  int x0 = 4;
  int x1 = 8;
  int x2 = 9;

  int ans0 = mySqrt(x0);
  int ans1 = mySqrt(x1);
  int ans2 = mySqrt(x2);

  cout << ans0 << endl; // 2
  cout << ans1 << endl; // 2
  cout << ans2 << endl; // 3

  return 0;
}