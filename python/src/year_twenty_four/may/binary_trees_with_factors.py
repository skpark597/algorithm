"""
823. Binary Trees With Factors
Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
We make a binary tree using these integers, and each number may be used for any number of times.
Each non-leaf node's value should be equal to the product of the values of its children.
Return the number of binary trees we can make. The answer may be too large so return the answer modulo 10^9 + 7.

Example 1:
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]

Example 2:
Input: arr = [2,4,5,10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].

Constraints:
1 <= arr.length <= 1000
2 <= arr[i] <= 10^9
All the values of arr are unique.
"""


from typing import List

MODULO = 10**9 + 7

# pylint: disable=C0200
class Solution:
    def num_factored_binary_trees(self, nums: List[int]) -> int:
        nums_sorted = sorted(nums)
        nums_indice = {num: i for i, num in enumerate(nums_sorted)}
        cache, answer = (len(nums) + 1) * [1], 0

        for i, num_first in enumerate(nums_sorted):
            for j, num_second in enumerate(nums_sorted[:i]):
                quotient = num_first / num_second

                if quotient.is_integer() and quotient in nums_indice:
                    cache[i] += cache[j] * cache[nums_indice[quotient]]

            answer = (answer + cache[i]) % MODULO

        return answer
