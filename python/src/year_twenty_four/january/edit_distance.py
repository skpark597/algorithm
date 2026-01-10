"""
72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Constraints:
0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
"""


class Solution:
    def min_distance(self, word1: str, word2: str) -> int:
        length1, length2 = len(word1), len(word2)
        distances = [[0] * (length2 + 1) for _ in range(length1 + 1)]

        for i in range(length1 + 1):
            distances[i][0] = i

        for j in range(length2 + 1):
            distances[0][j] = j

        for i in range(1, length1 + 1):
            for j in range(1, length2 + 1):

                if word1[i - 1] == word2[j - 1]:
                    distances[i][j] = distances[i - 1][j - 1]
                else:
                    insert = distances[i][j - 1]
                    replace = distances[i - 1][j - 1]
                    delete = distances[i - 1][j]
                    distances[i][j] = min(insert, replace, delete) + 1

        return distances[length1][length2]
