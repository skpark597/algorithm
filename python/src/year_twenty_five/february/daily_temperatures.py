"""
739. Daily Temperatures
Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Constraints:
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100
"""

from typing import List

import heapq


class Solution:
    def daily_temperatures(self, temperatures: List[int]) -> List[int]:
        if len(temperatures) == 0:
            return []

        answer, min_heap = [0] * len(temperatures), []

        for i, temperature in enumerate(temperatures):
            while len(min_heap) > 0 and min_heap[0][0] < temperature:
                min_temperature = heapq.heappop(min_heap)
                answer[min_temperature[1]] = i - min_temperature[1]

            heapq.heappush(min_heap, (temperature, i))

        return answer
