"""
1081. Smallest Subsequence of Distinct Characters
Given a string s, return the lexicographically smallest subsequence of s 
that contains all the distinct characters of s exactly once.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"

Constraints:
1 <= s.length <= 1000
s consists of lowercase English letters.
"""


class Solution:
    def smallest_subsequence(self, s: str) -> str:
        result = ""
        last, seen = {char: index for index, char in enumerate(s)}, set()

        for index, char in enumerate(s):
            if char in seen:
                continue

            while len(result) > 0 and result[-1] > char and last[result[-1]] > index:
                seen.remove(result[-1])
                result = result[:-1]

            result += char
            seen.add(char)

        return result
