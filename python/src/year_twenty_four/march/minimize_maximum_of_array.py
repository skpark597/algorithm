"""
2439. Minimize Maximum of Array
You are given a 0-indexed array nums comprising of n non-negative integers.
In one operation, you must:

Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.

Example 1:
Input: nums = [3,7,1,6]
Output: 5
Explanation:
One set of optimal operations is as follows:
1. Choose i = 1, and nums becomes [4,6,1,6].
2. Choose i = 3, and nums becomes [4,6,2,5].
3. Choose i = 1, and nums becomes [5,5,2,5].
The maximum integer of nums is 5. It can be shown that the maximum number cannot be less than 5.
Therefore, we return 5.

Example 2:
Input: nums = [10,1]
Output: 10
Explanation:
It is optimal to leave nums as is, and since 10 is the maximum value, we return 10.

Constraints:
n == nums.length
2 <= n <= 10^5
0 <= nums[i] <= 10^9
"""


from math import floor
from typing import List


class Solution:
    def can_be_maximum(self, nums: List[int], target: int) -> bool:
        current = nums[-1]

        for num in reversed(nums[:-1]):
            current = num + max(0, current - target)

        return current <= target

    def minimize_array_value(self, nums: List[int]) -> int:
        left, right = min(nums), max(nums)

        while left <= right:
            middle = floor(left + (right - left) / 2)

            if self.can_be_maximum(nums, middle):
                right = middle - 1
            else:
                left = middle + 1

        return left
