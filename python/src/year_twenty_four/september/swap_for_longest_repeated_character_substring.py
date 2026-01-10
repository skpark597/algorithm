"""
1156. Swap For Longest Repeated Character Substring
You are given a string text. You can swap two of the characters in the text.
Return the length of the longest substring with repeated characters.

Example 1:
Input: text = "ababa"
Output: 3
Explanation: We can swap the first 'b' with the last 'a', or the last 'b' with the first 'a'.
Then, the longest repeated character substring is "aaa" with length 3.

Example 2:
Input: text = "aaabaaa"
Output: 6
Explanation: Swap 'b' with the last 'a' (or the first 'a'), and we get longest repeated character substring "aaaaaa" with length 6.

Example 3:
Input: text = "aaaaa"
Output: 5
Explanation: No need to swap, longest repeated character substring is "aaaaa" with length is 5.


Constraints:
1 <= text.length <= 2 * 10^4
text consist of lowercase English characters only.
"""

import itertools
import collections


class Solution:
    def max_rep_opt1(self, text: str) -> int:
        groupby = [[c, len(list(g))] for c, g in itertools.groupby(text)]
        count = collections.Counter(text)
        result = max(min(k + 1, count[c]) for c, k in groupby)

        for i in range(1, len(groupby) - 1):
            if groupby[i - 1][0] == groupby[i + 1][0] and groupby[i][1] == 1:
                result = max(result, min(groupby[i - 1][1] + groupby[i + 1][1] + 1, count[groupby[i + 1][0]]))

        return result
