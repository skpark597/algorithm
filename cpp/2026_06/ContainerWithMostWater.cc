/** 11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the
ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water
(blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1

Constraints:
n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4 */

#include <cassert>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
  int left = 0, right = height.size() - 1, area = 0;

  while (left < right) {
    if (height[left] <= height[right]) {
      area = max(area, (right - left) * height[left]);
      left++;
    } else {
      area = max(area, (right - left) * height[right]);
      right--;
    }
  }

  return area;
}

int main() {
  vector<int> height0{1, 8, 6, 2, 5, 4, 8, 3, 7};
  vector<int> height1{1, 1};
  vector<int> height2{8, 7, 2, 1};

  int ret0 = maxArea(height0);
  int ret1 = maxArea(height1);
  int ret2 = maxArea(height2);

  assert(ret0 == 49);
  assert(ret1 == 1);
  assert(ret2 == 7);

  return 0;
}