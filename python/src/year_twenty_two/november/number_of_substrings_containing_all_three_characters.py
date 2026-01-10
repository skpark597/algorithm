"""
1358. Number of Substrings Containing All Three Characters
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence
of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b
and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again)

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c
are "aaacb", "aacb" and "acb"

Example 3:
Input: s = "abc"
Output: 1

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
"""


class Solution:
    def __init__(self) -> None:
        self.appeared = {"a": -1, "b": -1, "c": -1}

    def is_all_chars_appeared(self):
        return (
            self.appeared["a"] >= 0
            and self.appeared["b"] >= 0
            and self.appeared["c"] >= 0
        )

    def need_to_find_more(self, end: int, string: str) -> bool:
        return end < len(string) - 1 or self.is_all_chars_appeared()

    def remove_apperance(self, char: str, index: int):
        if self.appeared[char] <= index:
            self.appeared[char] = -1

    def add_appearance(self, char: str, index: int):
        self.appeared[char] = max(self.appeared[char], index)

    def number_of_substrings(self, string: str) -> int:
        start, end, count = 0, 0, 0
        self.add_appearance(string[0], 0)

        while self.need_to_find_more(end, string):
            if self.is_all_chars_appeared():
                count += len(string) - end
                self.remove_apperance(string[start], start)
                start += 1
                self.add_appearance(string[start], start)
            else:
                end += 1
                self.add_appearance(string[end], end)

        return count
