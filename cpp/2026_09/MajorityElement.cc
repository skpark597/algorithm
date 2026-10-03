/** 169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element
always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
The input is generated such that a majority element will exist in the array.

Follow-up: Could you solve the problem in linear time and in O(1) space? */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
  int start = 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i <= nums.size(); ++i) {
    if (i == nums.size() || nums[i] != nums[start]) {
      if ((i - start) * 2 > nums.size()) return nums[start];
      start = i;
    }
  }

  return -1;
}

int main() {
  vector<int> nums0{3, 2, 3};
  vector<int> nums1{2, 2, 1, 1, 1, 2, 2};
  vector<int> nums2{1};

  int ret0 = majorityElement(nums0);
  int ret1 = majorityElement(nums1);
  int ret2 = majorityElement(nums2);

  assert(ret0 == 3);
  assert(ret1 == 2);
  assert(ret2 == 1);

  return 0;
}