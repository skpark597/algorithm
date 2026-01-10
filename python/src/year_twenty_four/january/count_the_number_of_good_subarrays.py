"""
2537. Count the Number of Good Subarrays
Given an integer array nums and an integer k, return the number of good subarrays of nums.
A subarray arr is good if it there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.

Example 2:
Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.

Constraints:
1 <= nums.length <= 10^5
1 <= nums[i], k <= 10^9
"""


from typing import List


class Solution:
    def count_good(self, nums: List[int], k: int) -> int:
        start, end, pair_count, answer, length = 0, 0, 0, 0, len(nums)
        num_count = {num: 0 for num in nums}

        while end < length:
            if pair_count < k:
                num_count[nums[end]] += 1
                pair_count += num_count[nums[end]] - 1
            else:
                num_count[nums[start - 1]] -= 1
                pair_count -= num_count[nums[start - 1]]

            if pair_count < k:
                end += 1
            else:
                answer += length - end
                start += 1

        return answer
