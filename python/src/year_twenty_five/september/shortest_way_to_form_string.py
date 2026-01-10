"""
1055. Shortest Way to Form String
A subsequence of a string is a new string that is formed from the original string by deleting some (can be none)
of the characters without disturbing the relative positions of the remaining characters.
(i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target.
If the task is impossible, return -1.

Example 1:
Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:
Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.

Example 3:
Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".


Constraints:
1 <= source.length, target.length <= 1000
source and target consist of lowercase English letters.

"""

import bisect
from collections import defaultdict


class Solution:
    def shortest_way(self, source: str, target: str) -> int:
        idxs = defaultdict(list)

        for i, c in enumerate(source):
            idxs[c].append(i)

        if not set(target) <= set(source):
            return -1

        count, i = 1, -1

        for c in target:
            pos_list = idxs[c]
            k = bisect.bisect_right(pos_list, i)

            if k == len(pos_list):
                count += 1
                i = pos_list[0]
            else:
                i = pos_list[k]

        return count
