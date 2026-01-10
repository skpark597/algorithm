"""
2024. Maximize the Confusion of an Exam
A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false.
He wants to confuse the students by maximizing the number of consecutive questions with the same answer
(multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question.
In addition, you are given an integer k, the maximum number of times you may perform the following operation:

Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
Return the maximum number of consecutive 'T's or 'F's
in the answer key after performing the operation at most k times.

Example 1:
Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:
Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

Example 3:
Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT".
In both cases, there are five consecutive 'T's.

Constraints:
n == answerKey.length
1 <= n <= 5 * 10^4
answerKey[i] is either 'T' or 'F'
1 <= k <= n
"""


from math import floor
from typing import List


class Solution:
    def _find_leftmost_index(self, current_index: int, k: int, cnt: List[int]) -> int:
        left, right = 0, current_index

        if cnt[0] - cnt[right] <= k:
            return 0

        while left <= right:
            middle = left + floor((right - left) / 2)

            if cnt[middle] - cnt[current_index] > k:
                left = middle + 1
            else:
                right = middle - 1

        return left

    def max_consecutive_answers(self, answer: str, k: int) -> int:
        result = 1
        t_cnt, f_cnt = [0] * (len(answer) + 1), [0] * (len(answer) + 1)

        if len(answer) == 1:
            return 1

        for idx in range(len(answer) - 1, -1, -1):
            t_cnt[idx] = t_cnt[idx + 1] + 1 if answer[idx] == "T" else t_cnt[idx + 1]
            f_cnt[idx] = f_cnt[idx + 1] + 1 if answer[idx] == "F" else f_cnt[idx + 1]

        for idx, letter in enumerate(answer):
            cnt = t_cnt if letter == "T" else f_cnt
            opposite_cnt = f_cnt if letter == "T" else t_cnt

            index1 = self._find_leftmost_index(idx, k, opposite_cnt)
            index2 = self._find_leftmost_index(idx, k - 1, cnt)

            result = max(result, max(idx - index1 + 1, idx - index2 + 1))

        return result
