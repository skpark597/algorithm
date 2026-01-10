"""
1002. Find Common Characters

Given a string array words, return an array of all characters that show up in all strings
within the words (including duplicates). You may return the answer in any order.

Example 1:
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

Example 2:
Input: words = ["cool","lock","cook"]
Output: ["c","o"]

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists of lowercase English letters.

"""

from typing import List


class Solution:
    def common_chars(self, words: List[str]) -> List[str]:
        common = list(words[0])

        for word in words[1:]:
            common_new = []

            for char in word:
                if char in common:
                    common_new.append(char)
                    common.remove(char)

            common = common_new

        return common
