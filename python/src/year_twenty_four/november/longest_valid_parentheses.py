"""
32. Longest Valid Parentheses
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring.


Example 1:
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:
Input: s = ""
Output: 0


Constraints:
0 <= s.length <= 3 * 10^4
s[i] is '(', or ')'.
"""


class Solution:
    def find_unbalanced_idx(self, s: str, direction: int = 1):
        balance = 0

        for i, c in enumerate(s):
            balance += 1 if c == "(" else -1

            if balance * direction < 0:
                return i

        return -1

    def longest_valid_parentheses_old(self, s: str) -> int:
        if not s:
            return 0

        first = self.find_unbalanced_idx(s)
        last = self.find_unbalanced_idx(s[::-1], -1)

        if first != -1:
            right = self.longest_valid_parentheses_old(s[first + 1 :])
            return max(first, right)
        elif last != -1:
            left = self.longest_valid_parentheses_old(s[: -last - 1])
            return max(left, last)

        return len(s)

    def longest_valid_parentheses(self, s: str) -> int:
        max_len = 0
        stack = [-1]

        for idx, char in enumerate(s):
            if char == "(":
                stack.append(idx)
            else:
                stack.pop()

                if len(stack) == 0:
                    stack.append(idx)
                else:
                    max_len = max(max_len, idx - stack[-1])

        return max_len
