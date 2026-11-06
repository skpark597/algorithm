/** 201. Bitwise AND of Numbers Range
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this
range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

Constraints:
* 0 <= left <= right <= 2^31 - 1*/

#include <cassert>
#include <cmath>

using namespace std;

int rangeBitwiseAnd(int left, int right) {
  if (right == 0) return 0;

  int msb = log2(right);
  int ret = 0;

  for (int i = msb; i >= 0; --i) {
    int mask = 1 << i;

    if ((right & mask) && !(left & mask)) break;
    if ((right & mask)) ret |= mask;
  }

  return ret;
}

int main() {
  int ret0 = rangeBitwiseAnd(5, 7);
  int ret1 = rangeBitwiseAnd(0, 0);
  int ret2 = rangeBitwiseAnd(1, 2147483647);
  int ret3 = rangeBitwiseAnd(416, 436);

  assert(ret0 == 4);
  assert(ret1 == 0);
  assert(ret2 == 0);
  assert(ret3 == 416);

  return 0;
}
