"""
238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.


Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.
"""

from math import prod


class Solution:
    def product_except_self(self, nums: list[int]) -> list[int]:
        zero_count = nums.count(0)
        all_prod = prod(num for num in nums if num != 0)

        return [
            int(all_prod / num) if zero_count == 0 else all_prod if zero_count == 1 and num == 0 else 0 for num in nums
        ]
