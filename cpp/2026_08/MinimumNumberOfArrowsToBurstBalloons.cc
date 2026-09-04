/** 452. Minimum Number of Arrows to Burst Balloons
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a
2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between
xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A
balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of
arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:
Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].

Example 2:
Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.

Example 3:
Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].

Constraints:
1 <= points.length <= 10^5
points[i].length == 2
-2^31 <= x_start < x_end <= 2^31 - 1 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
  if (a[1] == b[1]) return a[0] < b[0];
  return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
  sort(points.begin(), points.end(), compare);

  int cur = points[0][1];
  int count = 1;

  for (vector<int>& point : points) {
    if (point[0] > cur) {
      cur = point[1];
      count++;
    }
  }

  return count;
}

int main() {
  vector<vector<int>> points0{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
  vector<vector<int>> points1{{1, 2}, {3, 4}, {5, 6}, {7, 8}};
  vector<vector<int>> points2{{1, 2}, {2, 3}, {3, 4}, {4, 5}};

  int ret0 = findMinArrowShots(points0);
  int ret1 = findMinArrowShots(points1);
  int ret2 = findMinArrowShots(points2);

  assert(ret0 == 2);
  assert(ret1 == 4);
  assert(ret2 == 2);

  return 0;
}
