"""
3355. Zero Array Transformation I
You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
For each queries[i]:

* select a subset of indices within the range [li, ri] in nums.
* decrement the values at the selected indices by 1.
* a zero array is an array where all elements are equal to 0.

return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.


Example 1:
Input: nums = [1,0,1], queries = [[0,2]]
Output: true

Explanation:
For i = 0:
select the subset of indices as [0, 2] and decrement the values at these indices by 1.
the array will become [0, 0, 0], which is a zero array.

Example 2:
Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
Output: false

Explanation:
For i = 0:
select the subset of indices as [1, 2, 3] and decrement the values at these indices by 1.
the array will become [4, 2, 1, 0].
For i = 1:
select the subset of indices as [0, 1, 2] and decrement the values at these indices by 1.
the array will become [3, 1, 0, 0], which is not a zero array.


Constraints:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
1 <= queries.length <= 10^5
queries[i].length == 2
0 <= li <= ri < nums.length
"""


# ruff: noqa: E741

from collections import defaultdict


class Solution:
    def is_zero_array(self, nums: list[int], queries: list[list[int]]) -> bool:
        prefix = [0] * (len(nums) + 1)

        for l, r in queries:
            prefix[l] -= 1
            prefix[r + 1] += 1

        for i in range(1, len(nums)):
            prefix[i] += prefix[i - 1]

        for i, num in enumerate(nums):
            if num + prefix[i] > 0:
                return False

        return True

    def is_zero_array_time_exceeded(self, nums: list[int], queries: list[list[int]]) -> bool:
        reduce = defaultdict(int)

        for l, r in queries:
            for i in range(l, r + 1):
                reduce[i] += 1

        for i, num in enumerate(nums):
            if num > reduce[i]:
                return False

        return True
