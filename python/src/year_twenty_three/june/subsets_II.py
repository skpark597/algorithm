"""
90. Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
"""

from typing import List


class Solution:
    def make_partitions(self, nums: List[int], partitions: List[int]):
        nums_sorted = sorted(nums)
        partition, current = [], nums_sorted[0]

        for num in nums_sorted:
            if num == current:
                partition.append(num)
            else:
                partitions.append(partition)
                partition, current = [num], num

        partitions.append(partition)

    def make_subsets(
        self,
        partitions: List[List[int]],
        subsets: List[List[int]],
        subset: List[int],
        index: int,
    ):
        if index == len(partitions):
            subsets.append(subset)
            return

        for i in range(len(partitions[index]) + 1):
            new_subset = subset + [partitions[index][0]] * i
            self.make_subsets(partitions, subsets, new_subset, index + 1)

    def subsets_with_dup(self, nums: List[int]) -> List[List[int]]:
        partitions, subsets = [], []
        self.make_partitions(nums, partitions)
        self.make_subsets(partitions, subsets, [], 0)

        return subsets
