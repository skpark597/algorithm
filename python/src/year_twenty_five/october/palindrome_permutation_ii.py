"""
267. Palindrome Permutation II
Given a string s, return all the palindromic permutations (without duplicates) of it.
You may return the answer in any order. If s has no palindromic permutation, return an empty list.



Example 1:
Input: s = "aabb"
Output: ["abba","baab"]

Example 2:
Input: s = "abc"
Output: []


Constraints:
1 <= s.length <= 16
s consists of only lowercase English letters.
"""

from collections import Counter


class Solution:
    def generate_palindromes(self, s: str) -> list[str]:
        counter = Counter(s)
        chars, halfs = [], set()
        odd_count, middle = 0, ""

        for char, count in counter.items():
            if count % 2 == 1:
                odd_count += 1
                middle = char

            chars.extend(char * (count // 2))

        if odd_count > 1:
            return []

        def generate_permutaions(cur: str = ""):
            if len(cur) == len(s) // 2:
                halfs.add(cur)
                return

            for idx, char in enumerate(chars):
                if char == "-":
                    continue

                chars[idx] = "-"
                generate_permutaions(cur + char)
                chars[idx] = char

        generate_permutaions()

        return [half + middle + half[::-1] for half in halfs]
