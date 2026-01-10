"""
1405. Longest Happy String
A string s is called happy if it satisfies the following conditions:
- s only contains the letters 'a', 'b', and 'c'.
- s does not contain any of "aaa", "bbb", or "ccc" as a substring.
- s contains at most a occurrences of the letter 'a'.
- s contains at most b occurrences of the letter 'b'.
- s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. 
If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
A substring is a contiguous sequence of characters within a string.


Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.

Example 2:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.

Constraints:
0 <= a, b, c <= 100
a + b + c > 0
"""


class Solution:
    def find_max(self, count: dict, exclude: str):
        chars = list(set(["a", "b", "c"]) - set([exclude]))
        max_char, max_count = "", -1

        for char in chars:
            if max_count < count[char]:
                max_char, max_count = char, count[char]

        return max_char, max_count

    def longest_diverse_string(self, a: int, b: int, c: int) -> str:
        char_count = {"a": a, "b": b, "c": c}
        exclude, answer = "", ""

        while True:
            exclude = answer[-1] if len(answer) >= 2 and answer[-1] == answer[-2] else ""
            max_char, max_count = self.find_max(char_count, exclude)

            if max_count <= 0:
                break

            answer += max_char
            char_count[max_char] -= 1

        return answer
