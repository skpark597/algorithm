"""
137. Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once.
Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
1 <= nums.length <= 3 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
Each element in nums appears exactly three times except for one element which appears once.
"""

from typing import List


class Solution:
    def single_number_sort(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]

        left, right, found = 0, 1, True
        nums.sort()

        while right < len(nums):
            if nums[left] != nums[right] and found:
                break
            elif nums[left] != nums[right] and not found:
                left = right
                found = True
            elif nums[left] == nums[right]:
                found = False

            right += 1

        return nums[left]

    def single_number(self, nums: List[int]) -> int:
        return 0
