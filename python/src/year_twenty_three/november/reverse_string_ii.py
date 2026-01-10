"""
541. Reverse String II
Given a string s and an integer k, reverse the first k characters for every
2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them.
If there are less than 2k but greater than or equal to k characters,
then reverse the first k characters and leave the other as original.

Example 1:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"

Example 2:
Input: s = "abcd", k = 2
Output: "bacd"

Constraints:
1 <= s.length <= 10^4
s consists of only lowercase English letters.
1 <= k <= 10^4

"""


from math import floor


class Solution:
    def reverse_str_v1(self, s: str, k: int) -> str:
        s_list = list(s)

        for start in range(0, len(s), 2 * k):
            end = min(len(s) - 1, start + k - 1)
            middle = floor((start + end) / 2)

            for i in range(start, middle + 1):
                temp = s_list[i]
                s_list[i] = s_list[end + start - i]
                s_list[end + start - i] = temp

        return "".join(s_list)

    def reverse_str_v2(self, s: str, k: int) -> str:
        result = ""

        for start in range(0, len(s), 2 * k):
            end = min(len(s) - 1, start + k - 1)
            result += s[start : end + 1][::-1] + s[end + 1 : start + 2 * k]

        return result
