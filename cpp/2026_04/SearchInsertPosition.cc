/** 35. Search Insert Position
Given a sorted array of distinct integers and a target value, return the index
if the target is found. If not, return the index where it would be if it were
inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4 */

#include <cassert>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  int left = 0, right = nums.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return left;
}

int main() {
  vector<int> nums0{1, 3, 5, 6};
  vector<int> nums1{1, 3, 5, 6};
  vector<int> nums2{1, 3, 5, 6};

  int target0 = 5;
  int target1 = 2;
  int target2 = 7;

  int ret0 = searchInsert(nums0, target0);
  int ret1 = searchInsert(nums1, target1);
  int ret2 = searchInsert(nums2, target2);

  assert(ret0 == 2);
  assert(ret1 == 1);
  assert(ret2 == 4);

  return 0;
}
