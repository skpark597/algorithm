"""
1802. Maximum Value at a Given Index in a Bounded Array
You are given three positive integers: n, index, and maxSum.
You want to construct an array nums (0-indexed) that satisfies the following conditions:

* nums.length == n
* nums[i] is a positive integer where 0 <= i < n.
* abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
* The sum of all the elements of nums does not exceed maxSum.
* nums[index] is maximized.

Return nums[index] of the constructed array.
Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:
Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:
Input: n = 6, index = 1,  maxSum = 10
Output: 3

Constraints:
1 <= n <= maxSum <= 10^9
0 <= index < n
"""


class Solution:
    def max_value(self, n: int, i: int, max_sum: int) -> int:
        def range_sum(start: int, end: int):
            return int((start + end) * (end - start + 1) / 2)

        def side_sum(peak: int, length: int):
            if peak > length:
                return range_sum(peak - length, peak - 1)

            return range_sum(1, peak - 1) + (length - peak + 1)

        left, right = 1, max_sum

        while left <= right:
            mid = (left + right) // 2
            total = mid + side_sum(mid, i) + side_sum(mid, n - i - 1)

            if total <= max_sum:
                left = mid + 1
            else:
                right = mid - 1

        return right
