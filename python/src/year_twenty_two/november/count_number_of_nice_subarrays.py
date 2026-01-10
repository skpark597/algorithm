"""
1248. Count Number of Nice Subarrays

Given an array of integers nums and an integer k.
A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

Example 1:
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

Example 3:
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

Constraints:
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

"""
from typing import List


class Solution:
    def number_of_subarrays(self, nums: List[int], k: int) -> int:
        start, end, odd_count, result = 0, 0, 0, 0

        for index, num in enumerate(nums):
            if num % 2 == 1:
                odd_count += 1
            if odd_count == k:
                end = index
                break

        if odd_count < k:
            return 0

        while start <= end < len(nums):
            prev_start = start
            prev_end = end

            while True:
                start += 1
                if start >= len(nums) or nums[start - 1] % 2 == 1:
                    break

            while True:
                end += 1
                if end >= len(nums) or nums[end] % 2 == 1:
                    break

            result += (start - prev_start) * (end - prev_end)

        return result
