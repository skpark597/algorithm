"""
788. Rotated Digits
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x.
Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:
* 0, 1, and 8 rotate to themselves,
* 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
* 6 and 9 rotate to each other, and
* the rest of the numbers do not rotate to any other number and become invalid.

Given an integer n, return the number of good integers in the range [1, n].

Example 1:
Input: n = 10
Output: 4
Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

Example 2:
Input: n = 1
Output: 0

Example 3:
Input: n = 2
Output: 1

Constraints:
1 <= n <= 10^4
"""

cache = []


class Solution:
    def count_valid(self, n: int, is_good: int):
        if cache[is_good][n] != -1:
            return cache[is_good][n]

        s = str(n)
        first, rem = int(s[0]), int(s[1:])
        next = first * 10 ** (len(s) - 1) - 1

        if first not in {0, 1, 2, 5, 6, 8, 9}:
            result = self.count_valid(next, is_good)
        elif not is_good or first in {0, 1, 8}:
            result = self.count_valid(next, is_good) + self.count_valid(rem, is_good)
        else:
            result = self.count_valid(next, is_good) + self.count_valid(rem, 1 - is_good)

        cache[is_good][n] = result
        return result

    def rotated_digits(self, n: int) -> int:
        global cache
        cache = [[-1] * max(n + 1, 10) for _ in range(2)]
        cache[0][:10] = [1, 2, 3, 3, 3, 4, 5, 5, 6, 7]
        cache[1][:10] = [0, 0, 1, 1, 1, 2, 3, 3, 3, 4]

        return self.count_valid(n, 1)
