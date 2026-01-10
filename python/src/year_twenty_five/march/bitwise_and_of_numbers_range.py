"""
201. Bitwise AND of Numbers Range
Given two integers left and right that represent the range [left, right],
return the bitwise AND of all numbers in this range, inclusive.

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
0 <= left <= right <= 2^31 - 1
"""


class Solution:
    def range_bitwise_and(self, left: int, right: int) -> int:
        result = 0

        for i in range(31, -1, -1):
            if left // 2**i != right // 2**i:
                break

            result += (left // 2**i) * 2**i
            left -= (left // 2**i) * 2**i
            right -= (right // 2**i) * 2**i

        return result
