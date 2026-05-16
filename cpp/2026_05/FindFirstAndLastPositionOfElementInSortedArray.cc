/** 34. Find First and Last Position of Element in Sorted Array
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target
value.

If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9 */

#include <cassert>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
  auto binarySearch = [&](bool is_start) {
    int left = 0, right = nums.size() - 1;
    int result = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        result = mid;

        if (is_start) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      };
    }

    return result;
  };

  return vector<int>{binarySearch(true), binarySearch(false)};
}

int main() {
  vector<int> nums0{5, 7, 7, 8, 8, 10};
  vector<int> nums1{5, 7, 7, 8, 8, 10};
  vector<int> nums2{};
  vector<int> nums3{2, 2};

  int target0 = 8;
  int target1 = 6;
  int target2 = 0;
  int target3 = 3;

  vector<int> ret0 = searchRange(nums0, target0);
  vector<int> ret1 = searchRange(nums1, target1);
  vector<int> ret2 = searchRange(nums2, target2);
  vector<int> ret3 = searchRange(nums3, target3);

  vector<int> ans0{3, 4};
  vector<int> ans1{-1, -1};
  vector<int> ans2{-1, -1};
  vector<int> ans3{-1, -1};

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);
  assert(ret3 == ans3);

  return 0;
}
