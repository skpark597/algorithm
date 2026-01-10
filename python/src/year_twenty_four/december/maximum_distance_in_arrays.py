"""
624. Maximum Distance in Arrays
You are given m arrays, where each array is sorted in ascending order.
You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
Return the maximum distance.


Example 1:
Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

Example 2:
Input: arrays = [[1],[1]]
Output: 0


Constraints:
m == arrays.length
2 <= m <= 10^5
1 <= arrays[i].length <= 500
-10^4 <= arrays[i][j] <= 10^4
arrays[i] is sorted in ascending order.
There will be at most 10^5 integers in all the arrays.
"""

import heapq


class Solution:
    def max_distance(self, arrays: list[list[int]]) -> int:
        result, min_val, max_val = 0, arrays[0][0], arrays[0][-1]

        for array in arrays[1:]:
            result = max(result, array[-1] - min_val, max_val - array[0])
            min_val = min(min_val, array[0])
            max_val = max(max_val, array[-1])

        return result

    def max_distance_old(self, arrays: list[list[int]]) -> int:
        result, first_nums, final_nums = 0, [], []

        for i, array in enumerate(arrays):
            heapq.heappush(first_nums, (array[0], i))
            heapq.heappush(final_nums, (-array[-1], i))

        first_min0, idx0 = heapq.heappop(first_nums)
        final_max0, idx1 = heapq.heappop(final_nums)

        if idx0 != idx1:
            result = -final_max0 - first_min0
        else:
            first_min1, _ = heapq.heappop(first_nums)
            final_max1, _ = heapq.heappop(final_nums)
            result = max(-final_max0 - first_min1, -final_max1 - first_min0)

        return result
