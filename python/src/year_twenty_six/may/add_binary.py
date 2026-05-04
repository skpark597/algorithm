"""
67. Add Binary
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself
"""


class Solution:
    def add_binary_old(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]

    def add_binary(self, a: str, b: str) -> str:
        res = []
        carry, i, j = 0, len(a) - 1, len(b) - 1

        while i >= 0 or j >= 0 or carry > 0:
            val_a = int(a[i]) if i >= 0 else 0
            val_b = int(b[j]) if j >= 0 else 0
            total = val_a + val_b + carry

            res.append(str(total % 2))
            carry = total // 2
            i -= 1
            j -= 1

        return "".join(res[::-1])
