/** 56. Merge Intervals
Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals that
cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.

Constraints:
1 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^4 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
  sort(intervals.begin(), intervals.end());
  vector<vector<int>> result;

  for (const auto& interval : intervals) {
    if (result.empty() || result.back()[1] < interval[0]) {
      result.push_back(interval);
    } else {
      result.back()[1] = max(result.back()[1], interval[1]);
    }
  }

  return result;
}

int main() {
  vector<vector<int>> intervals0{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> intervals1{{1, 4}, {4, 5}};
  vector<vector<int>> intervals2{{4, 7}, {1, 4}};
  vector<vector<int>> intervals3{{1, 4}, {2, 3}};

  vector<vector<int>> ret0 = merge(intervals0);
  vector<vector<int>> ret1 = merge(intervals1);
  vector<vector<int>> ret2 = merge(intervals2);
  vector<vector<int>> ret3 = merge(intervals3);

  vector<vector<int>> ans0{{1, 6}, {8, 10}, {15, 18}};
  vector<vector<int>> ans1{{1, 5}};
  vector<vector<int>> ans2{{1, 7}};
  vector<vector<int>> ans3{{1, 4}};

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);
  assert(ret3 == ans3);

  return 0;
}
