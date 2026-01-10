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


# pylint: disable=C0200
class Solution:
    def largest_divisible_subset(self, nums: List[int]) -> List[int]:
        length, max_index, max_count = len(nums), 0, 1
        cache, previous = [1] * length, list(range(length))

        nums.sort()

        for i in range(length):
            for j in range(i):
                if nums[i] % nums[j] == 0 and cache[j] + 1 > cache[i]:
                    cache[i] = cache[j] + 1
                    previous[i] = j
                    max_index = i if max_count < cache[i] else max_index
                    max_count = max(max_count, cache[i])

        result = []

        while True:
            if len(result) == max_count:
                break

            result.append(nums[max_index])
            max_index = previous[max_index]

        return result[::-1]
