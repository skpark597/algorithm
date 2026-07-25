/** 191. Number of 1 Bits
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also
known as the Hamming weight).

Example 1:
Input: n = 11
Output: 3
Explanation:
The input binary string 1011 has a total of three set bits.

Example 2:
Input: n = 128
Output: 1
Explanation:
The input binary string 10000000 has a total of one set bit.

Example 3:
Input: n = 2147483645
Output: 30

Explanation:
The input binary string 1111111111111111111111111111101 has a total of thirty set bits.

Constraints:
1 <= n <= 2^31 - 1

Follow up: If this function is called many times, how would you optimize it? */

#include <cassert>

using namespace std;

int hammingWeight(int n) {
  int result = 0;

  while (n > 0) {
    if (n & 1) result += 1;
    n = n >> 1;
  }

  return result;
}

int main() {
  int n0 = 11;
  int n1 = 128;
  int n2 = 2147483645;

  int ret0 = hammingWeight(n0);
  int ret1 = hammingWeight(n1);
  int ret2 = hammingWeight(n2);

  assert(ret0 == 3);
  assert(ret1 == 1);
  assert(ret2 == 30);

  return 0;
}