"""
253. Meeting Rooms II
Given an array of meeting time intervals intervals where intervals[i] = [start_i, end_i],
return the minimum number of conference rooms required.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2

Example 2:
Input: intervals = [[7,10],[2,4]]
Output: 1


Constraints:
1 <= intervals.length <= 10^4
0 <= start_i < end_i <= 10^6
"""

import bisect
import heapq
from typing import List


class Solution:
    def min_meeting_rooms_2(self, intervals: List[List[int]]) -> int:
        ends = []
        intervals.sort()

        heapq.heappush(ends, intervals[0][1])

        for start, end in intervals[1:]:
            if start >= ends[0]:
                heapq.heappop(ends)

            heapq.heappush(ends, end)

        return len(ends)

    def min_meeting_rooms(self, intervals: List[List[int]]) -> int:
        answer, ends = 1, []
        intervals.sort()

        for start, end in intervals:
            answer = max(answer, len(ends) - bisect.bisect_right(ends, start) + 1)
            ends.append(end)
            ends.sort()

        return answer
