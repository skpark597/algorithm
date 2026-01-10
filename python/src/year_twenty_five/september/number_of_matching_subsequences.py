"""
792. Number of Matching Subsequences
Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
For example, "ace" is a subsequence of "abcde".


Example 1:
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

Example 2:
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2


Constraints:
1 <= s.length <= 5 * 10^4
1 <= words.length <= 5000
1 <= words[i].length <= 50
s and words[i] consist of only lowercase English letters.
"""

from collections import defaultdict


class Solution:
    def _find_next_pos(self, pos: int, idxs: list[int]) -> int:
        left, right = 0, len(idxs) - 1

        while left <= right:
            mid = (left + right) // 2

            if idxs[mid] < pos:
                left = mid + 1
            else:
                right = mid - 1

        return idxs[left] + 1 if left < len(idxs) else -1

    def num_matching_subseq(self, s: str, words: list[str]) -> int:
        answer, idxs = 0, defaultdict(list)

        for i, c in enumerate(s):
            idxs[c].append(i)

        for word in words:
            pos = 0

            for c in word:
                pos = self._find_next_pos(pos, idxs[c])

                if pos == -1:
                    break
            else:
                answer += 1

        return answer
