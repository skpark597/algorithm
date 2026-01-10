"""
259. 3Sum Smaller
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with
0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example 1:
Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]

Example 2:
Input: nums = [], target = 0
Output: 0

Example 3:
Input: nums = [0], target = 0
Output: 0

Constraints:
n == nums.length
0 <= n <= 3500
-100 <= nums[i] <= 100
-100 <= target <= 100
"""


class Solution0:
    def _make_freqs(self, nums: list[int]) -> dict[int, int]:
        prev, freqs = nums[0] - 1, {}

        for i, cur in enumerate(nums):
            for j in range(prev + 1, cur + 1):
                freqs[j] = i

            prev = cur

        return freqs

    def _two_sum_smaller(self, nums: list[int], start_idx: int, target: int, freqs: dict[int, int]):
        freq_sum, lo, hi = 0, nums[start_idx], nums[-1]

        def get_freq(upper, num):
            if upper <= lo:
                return 0

            freq = len(nums) if upper > hi else freqs[upper]
            return freq - start_idx - (num < upper)

        freq_sum = sum(get_freq(target - nums[i], nums[i]) for i in range(start_idx, len(nums)))
        return freq_sum // 2

    def three_sum_smaller(self, nums: list[int], target: int) -> int:
        if len(nums) < 3:
            return 0

        nums.sort()
        freqs = self._make_freqs(nums)
        return sum(self._two_sum_smaller(nums, i + 1, target - nums[i], freqs) for i in range(len(nums) - 1))


class Solution1:
    def three_sum_smaller(self, nums: list[int], target: int) -> int:
        nums.sort()
        answer, n = 0, len(nums)

        for i, num in enumerate(nums):
            left, right = i + 1, n - 1

            while left < right:
                if nums[left] + nums[right] + num >= target:
                    right -= 1
                else:
                    answer += right - left
                    left += 1

        return answer
