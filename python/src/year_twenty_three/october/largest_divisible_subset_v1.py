"""
368. Largest Divisible Subset

Given a set of distinct positive integers nums, 
return the largest subset answer such that every pair (answer[i], answer[j]) 
of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0

If there are multiple solutions, return any of them.

Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.

Example 2:
Input: nums = [1,2,4,8]
Output: [1,2,4,8]

Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 10^9
All the integers in nums are unique.
"""

from typing import List


class Solution:
    """
    Timeout Solution - Brute Force
    """

    def find_divisible_subset(self, divisor: int, nums: List[int], subset: List[int]):
        if len(nums) == 0:
            return subset

        largest = subset

        for index, num in enumerate(nums):
            result, next_nums, next_subset = [], nums[index + 1 :], subset + [num]

            if num % divisor == 0:
                result = self.find_divisible_subset(num, next_nums, next_subset)

            if len(result) > len(largest):
                largest = result

        return largest

    def largest_divisible_subset(self, nums: List[int]) -> List[int]:
        return self.find_divisible_subset(1, sorted(nums), [])
