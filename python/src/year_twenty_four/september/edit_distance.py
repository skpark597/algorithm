"""
72. Edit Distance
Given two strings word0 and word1, return the minimum number of operations required to convert word0 to word1.
You have the following three operations permitted on a word:

* Insert a character
* Delete a character
* Replace a character


Example 1:
Input: word0 = "horse", word1 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word0 = "intention", word1 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:
0 <= word0.length, word1.length <= 500
word0 and word1 consist of lowercase English letters.
"""


class Solution:
    def min_distance(self, word0: str, word1: str) -> int:
        len0, len1 = len(word0), len(word1)
        cache = [[0] * (len1 + 1) for _ in range(len0 + 1)]

        for i in range(len0 + 1):
            for j in range(len1 + 1):
                if i == 0 or j == 0:
                    cache[i][j] = i + j
                elif word0[i - 1] == word1[j - 1]:
                    cache[i][j] = cache[i - 1][j - 1]
                else:
                    cache[i][j] = min(cache[i - 1][j] + 1, cache[i][j - 1] + 1, cache[i - 1][j - 1] + 1)

        return cache[len0][len1]
