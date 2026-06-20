/** 57. Insert Interval
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still
does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].


Constraints:
0 <= intervals.length <= 10^4
intervals[i].length == 2
0 <= starti <= endi <= 10^5
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 10^5 */

#include <cassert>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval) {
  vector<vector<int>> result;
  int i = 0, n = intervals.size();

  while (i < n && intervals[i][1] < new_interval[0]) {
    result.push_back(intervals[i]);
    i++;
  }

  while (i < n && intervals[i][0] <= new_interval[1]) {
    new_interval[0] = min(new_interval[0], intervals[i][0]);
    new_interval[1] = max(new_interval[1], intervals[i][1]);
    i++;
  }

  result.push_back(new_interval);

  while (i < n && intervals[i][0] > new_interval[1]) {
    result.push_back(intervals[i]);
    i++;
  }

  return result;
}

int main() {
  vector<vector<int>> intervals0{{1, 3}, {6, 9}};
  vector<vector<int>> intervals1{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  vector<vector<int>> intervals2{{1, 5}};
  vector<vector<int>> intervals3{{2, 5}, {6, 7}, {8, 9}};

  vector<int> new_interval0{2, 5};
  vector<int> new_interval1{4, 8};
  vector<int> new_interval2{0, 3};
  vector<int> new_interval3{0, 1};

  vector<vector<int>> ret0 = insert(intervals0, new_interval0);
  vector<vector<int>> ret1 = insert(intervals1, new_interval1);
  vector<vector<int>> ret2 = insert(intervals2, new_interval2);
  vector<vector<int>> ret3 = insert(intervals3, new_interval3);

  vector<vector<int>> ans0{{1, 5}, {6, 9}};
  vector<vector<int>> ans1{{1, 2}, {3, 10}, {12, 16}};
  vector<vector<int>> ans2{{0, 5}};
  vector<vector<int>> ans3{{0, 1}, {2, 5}, {6, 7}, {8, 9}};

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);
  assert(ret3 == ans3);
}
