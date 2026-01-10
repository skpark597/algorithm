"""
494. Target Sum

You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before
each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and
concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

Constraints:
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

"""

from typing import List
from collections import Counter

MAX = 1000


class Solution:
    def __init__(self) -> None:
        self.cache = [[0 for i in range(20001)] for j in range(21)]

    def save(self, index: int, target: int, value: int):
        self.cache[index + 1][target + MAX] = value

    def load(self, index: int, target: int):
        return self.cache[index + 1][target + MAX]

    def find_target_sum_ways_dp(self, nums: List[int], target: int) -> int:
        self.save(-1, 0, 1)

        for i, num in enumerate(nums):
            subsum = sum(nums[: i + 1])

            for j in range(-subsum, subsum + 1):
                a = self.load(i - 1, j - num)
                b = self.load(i - 1, j + num)
                self.save(i, j, a + b)

        return self.load(len(nums) - 1, target)

    def find_target_sum_ways(self, nums: List[int], target: int) -> int:
        counter = Counter({0: 1})

        for num in nums:
            step = Counter()

            for prev_sum, count in counter.items():
                step[prev_sum + num] += count
                step[prev_sum - num] += count

            counter = step

        return counter[target]
