"""
583. Delete Operation for Two Strings

Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4

Constraints:
1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
"""


import sys


class Solution:
    def min_distance(self, word1: str, word2: str) -> int:
        cache = [[0] * 501 for _ in range(501)]

        for i in range(len(word1) + 1):
            cache[i][0] = i

        for j in range(len(word2) + 1):
            cache[0][j] = j

        for j in range(len(word2) - 1, -1, -1):
            idx_same, length2 = -1, len(word2) - j

            for k in range(len(word1) - 1, -1, -1):
                length1 = len(word1) - k

                if word1[k] == word2[j]:
                    idx_same = k

                first_char_erased = 1 + cache[length1][length2 - 1]
                first_char_not_erased = (
                    (idx_same - k + cache[len(word1) - 1 - idx_same][length2 - 1])
                    if idx_same != -1
                    else sys.maxsize
                )

                cache[length1][length2] = min(first_char_erased, first_char_not_erased)

        return cache[len(word1)][len(word2)]
