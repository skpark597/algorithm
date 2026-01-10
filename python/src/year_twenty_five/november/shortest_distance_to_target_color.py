"""
1182. Shortest Distance to Target Color
You are given an array colors, in which there are three colors: 1, 2 and 3.
You are also given some queries. Each query consists of two integers i and c,
return the shortest distance between the given index i and the target color c. If there is no solution return -1.

Example 1:
Input: colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
Output: [3,0,3]
Explanation:
The nearest 3 from index 1 is at index 4 (3 steps away).
The nearest 2 from index 2 is at index 2 itself (0 steps away).
The nearest 1 from index 6 is at index 3 (3 steps away).

Example 2:
Input: colors = [1,2], queries = [[0,3]]
Output: [-1]
Explanation: There is no 3 in the array.


Constraints:
1 <= colors.length <= 5*10^4
1 <= colors[i] <= 3
1 <= queries.length <= 5*10^4
queries[i].length == 2
0 <= queries[i][0] < colors.length
1 <= queries[i][1] <= 3
"""

import bisect
import sys
from collections import defaultdict


INF = sys.maxsize


class Solution:
    def shortest_distance_color(self, colors: list[int], queries: list[list[int]]) -> list[int]:
        def find_distance(idxs: list[int], j: int):
            pos = bisect.bisect_left(idxs, j)
            right = idxs[pos] if pos < len(idxs) else INF
            left = idxs[pos - 1] if pos >= 1 else -INF

            return min(j - left, right - j)

        idx_map = defaultdict(list[int])
        answer = []

        for i, color in enumerate(colors):
            idx_map[color].append(i)

        for j, color in queries:
            if color not in idx_map:
                answer.append(-1)
            else:
                answer.append(find_distance(idx_map[color], j))

        return answer
