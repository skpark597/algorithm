/**136. Single Number
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
* 1 <= nums.length <= 3 * 10^4
* -3 * 10^4 <= nums[i] <= 3 * 10^4
* Each element in the array appears twice except for one element which appears only once. */

#include <cassert>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
  int ret = 0;
  for (int num : nums) ret ^= num;

  return ret;
}

int main() {
  vector<int> nums0{2, 2, 1};
  vector<int> nums1{4, 1, 2, 1, 2};
  vector<int> nums2{1};

  int ret0 = singleNumber(nums0);
  int ret1 = singleNumber(nums1);
  int ret2 = singleNumber(nums2);

  assert(ret0 == 1);
  assert(ret1 == 4);
  assert(ret2 == 1);

  return 0;
}