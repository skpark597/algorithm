"""
1071. Greatest Common Divisor of Strings
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Example 3:
Input: str1 = "LEET", str2 = "CODE"
Output: ""

Constraints:
1 <= str1.length, str2.length <= 1000
str1 and str2 consist of English uppercase letters.
"""

from math import gcd


class Solution:
    def gcd_of_strings_before(self, s0: str, s1: str) -> str:
        dividend, divisor = max(len(s0), len(s1)), min(len(s0), len(s1))

        while divisor > 0:
            dividend, divisor = divisor, dividend % divisor

        for i in range(dividend, 0, -1):
            if dividend % i > 0:
                continue

            word_set0 = set([s0[j : j + dividend] for j in range(0, len(s0), dividend)])
            word_set1 = set([s1[j : j + dividend] for j in range(0, len(s1), dividend)])

            if len(word_set0) == len(word_set1) == 1 and word_set0 == word_set1:
                return word_set0.pop()

        return ""

    def gcd_of_strings(self, s0: str, s1: str) -> str:
        if s0 + s1 != s1 + s0:
            return ""

        return s0[: gcd(len(s0), len(s1))]
