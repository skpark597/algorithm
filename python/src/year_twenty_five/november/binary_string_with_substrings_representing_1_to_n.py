"""
1016. Binary String With Substrings Representing 1 To N

Given a binary string s and a positive integer n, return true if the binary representation of all the integers
in the range [1, n] are substrings of s, or false otherwise.

A substring is a contiguous sequence of characters within a string.

Example 1:
Input: s = "0110", n = 3
Output: true

Example 2:
Input: s = "0110", n = 4
Output: false

Constraints:
1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= n <= 10^9
"""

from collections import defaultdict
import math


class Solution0:
    def query_string(self, s: str, n: int) -> bool:
        prev, cur = defaultdict(list[int]), defaultdict(list[int])
        m = math.floor(math.log2(n)) + 1

        for i, digit in enumerate(s):
            prev[digit].append(i)

        if "1" not in prev:
            return False

        for i in range(2, m + 1):
            for j in range(0, min(2**i, n + 1)):
                bin_str = f"{j:0{i}b}"
                head, tail = bin_str[0], bin_str[1:]

                for k in prev[tail]:
                    if k > 0 and s[k - 1] == head:
                        cur[bin_str].append(k - 1)

                if head == "1" and bin_str not in cur:
                    return False

            prev = cur
            cur = defaultdict(list[int])

        return True


class Solution1:
    def query_string(self, s: str, n: int) -> bool:
        seen = set()
        m = len(s)
        max_len = len(bin(n)) - 2

        for length in range(1, max_len + 1):
            for i in range(0, m - length + 1):
                seen.add(int(s[i : i + length], 2))

        return all(k in seen for k in range(1, n + 1))
