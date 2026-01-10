"""
1262. Greatest Sum Divisible by Three
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

Example 1:
Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

Example 2:
Input: nums = [4]
Output: 0
Explanation: Since 4 is not divisible by 3, do not pick any number.

Example 3:
Input: nums = [1,2,3,4,4]
Output: 12
Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).


Constraints:
1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4
"""


class Solution:
    def maxSumDivThree(self, nums: list[int]) -> int:
        n = len(nums)
        dp = [[-1] * 3 for _ in range(n)]

        dp[0][0] = 0
        dp[0][nums[0] % 3] = nums[0]

        for i in range(1, n):
            for rem in range(3):
                num = nums[i]
                without_num = dp[i - 1][rem]
                with_num = -1

                if dp[i - 1][(rem - num) % 3] != -1:
                    with_num = dp[i - 1][(rem - num) % 3] + num
                elif num % 3 == rem % 3:
                    with_num = num

                dp[i][rem] = max(with_num, without_num)

        return dp[n - 1][0]
