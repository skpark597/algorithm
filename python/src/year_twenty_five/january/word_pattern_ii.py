"""
291. Word Pattern II
Given a pattern and a string s, return true if s matches the pattern.
A string s matches a pattern if there is some bijective mapping of single characters to
non-empty strings such that if each character in pattern is replaced by the string it maps to,
then the resulting string is s.
A bijective mapping means that no two characters map to the same string, and no character maps to two different strings.

Example 1:
Input: pattern = "abab", s = "redblueredblue"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "red"
'b' -> "blue"

Example 2:
Input: pattern = "aaaa", s = "asdasdasdasd"
Output: true
Explanation: One possible mapping is as follows:
'a' -> "asd"

Example 3:
Input: pattern = "aabb", s = "xyzabcxzyabc"
Output: false

Constraints:
1 <= pattern.length, s.length <= 20
pattern and s consist of only lowercase English letters.
"""


class Solution:
    def word_pattern_match(self, pattern: str, s: str) -> bool:
        mapping = {}

        def backtracking(p_idx: int, s_idx: int):
            if p_idx == len(pattern):
                return s_idx == len(s)

            cur_pattern = pattern[p_idx]

            if cur_pattern in mapping:
                char = mapping[cur_pattern]
                return s.startswith(char, s_idx) and backtracking(p_idx + 1, s_idx + len(char))

            for i in range(1, len(s) - s_idx + 1):
                if s[s_idx : s_idx + i] in mapping.values():
                    continue

                mapping[cur_pattern] = s[s_idx : s_idx + i]

                if backtracking(p_idx + 1, s_idx + i):
                    return True

                del mapping[cur_pattern]

            return False

        return backtracking(0, 0)
