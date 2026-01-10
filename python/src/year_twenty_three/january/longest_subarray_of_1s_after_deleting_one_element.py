from typing import List

"""
1493. Longest Subarray of 1's After Deleting One Element

Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array.
Return 0 if there is no such subarray.

Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1.
"""


## First Solution - Proved by Me, Correct but complicated
class Solution:
    # pylint: disable=R0912
    def longest_subarray(self, nums: List[int]) -> int:
        one_count, zero_count = 0, 0
        consecutive_ones: List[int] = []
        only_ones = True
        can_be_merged: List[bool] = []
        start = len(nums)

        for idx, num in enumerate(nums):
            if num == 1:
                start = idx
                break

        if start > 0:
            only_ones = False

        for idx in range(start, len(nums)):
            if nums[idx] == 1:
                if idx == len(nums) - 1 or nums[idx + 1] == 0:
                    consecutive_ones.append(one_count + 1)
                    one_count = 0
                else:
                    one_count += 1
            else:
                only_ones = False
                if idx == len(nums) - 1 or nums[idx + 1] == 1:
                    can_be_merged.append(zero_count == 0)
                    zero_count = 0
                else:
                    zero_count += 1

        if len(consecutive_ones) == 0:
            return 0

        longest_length = max(consecutive_ones)

        # pylint: disable=C0200
        for idx in range(len(can_be_merged)):
            if can_be_merged[idx] and idx < len(consecutive_ones) - 1:
                merged_length = consecutive_ones[idx] + consecutive_ones[idx + 1]
                longest_length = max(longest_length, merged_length)

        return longest_length - 1 if only_ones else longest_length
