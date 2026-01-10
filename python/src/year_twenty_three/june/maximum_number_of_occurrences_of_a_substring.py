"""
1297. Maximum Number of Occurrences of a Substring

Given a string s, return the maximum number of occurrences of any substring under the following rules:
The number of unique characters in the substring must be less than or equal to maxLetters.
The substring size must be between minSize and maxSize inclusive.

Example 1:
Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
Output: 2
Explanation: Substring "aab" has 2 occurrences in the original string.
It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).

Example 2:
Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
Output: 2
Explanation: Substring "aaa" occur 2 times in the string. It can overlap.

Constraints:
1 <= s.length <= 10^5
1 <= maxLetters <= 26
1 <= minSize <= maxSize <= min(26, s.length)
s consists of only lowercase English letters.

"""


# pylint: disable=W0613
class Solution:
    def max_freq(self, s: str, max_letters: int, min_size: int, max_size: int) -> int:
        freq, result = {}, 0

        if len(s) < min_size:
            return 0

        for i in range(0, len(s) - min_size + 1):
            word = s[i : i + min_size]

            if len(set(word)) > max_letters:
                continue

            if freq.get(word) is None:
                freq[word] = 1
            else:
                freq[word] += 1

            result = max(result, freq[word])

        return result
