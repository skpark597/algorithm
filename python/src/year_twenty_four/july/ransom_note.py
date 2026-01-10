"""
383. Ransom Note
Given two strings ransomNote and magazine,
return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote.

Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true


Constraints:
1 <= ransomNote.length, magazine.length <= 10^5
ransomNote and magazine consist of lowercase English letters.
"""

from collections import Counter


class Solution:
    def _get_char_count(self, chars: str):
        count = {}

        for char in chars:
            if char in count:
                count[char] += 1
            else:
                count[char] = 1

        return count

    def can_construct(self, note: str, magazine: str) -> bool:
        char_count_note = self._get_char_count(note)
        char_count_magazine = self._get_char_count(magazine)

        for char, count in char_count_note.items():
            if char not in char_count_magazine:
                return False

            if count > char_count_magazine[char]:
                return False

        return True

    def can_construct_2(self, note: str, magazine: str) -> bool:
        st1, st2 = Counter(note), Counter(magazine)

        if st1 & st2 == st1:
            return True

        return False
