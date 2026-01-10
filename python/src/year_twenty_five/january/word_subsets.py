"""
916. Word Subsets
You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["lc","eo"]
Output: ["leetcode"]

Example 3:
Input: words1 = ["acaac","cccbb","aacbb","caacc","bcbbb"], words2 = ["c","cc","b"]
Output: ["cccbb"]

Constraints:
1 <= words1.length, words2.length <= 10^4
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.
"""


class Solution:
    def word_subsets(self, words1: list[str], words2: list[str]) -> list[str]:
        def count(word: str):
            ans = [0] * 26
            for letter in word:
                ans[ord(letter) - ord("a")] += 1

            return ans

        result, max_count = [], [0] * 26

        for word in words2:
            for i, c in enumerate(count(word)):
                max_count[i] = max(max_count[i], c)

        for word in words1:
            if all(x >= y for x, y in zip(count(word), max_count)):
                result.append(word)

        return result
