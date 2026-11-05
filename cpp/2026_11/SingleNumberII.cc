/** 137. Single Number II
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the
single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99

Constraints:
* 1 <= nums.length <= 3 * 10^4
* -2^31 <= nums[i] <= 2^31 - 1
* Each element in nums appears exactly three times except for one element which appears once. */

#include <cassert>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
  int ones = 0, twos = 0;

  for (int num : nums) {
    int zero_to_one = num ^ (ones | twos);
    int one_to_two = num & ones;
    int two_to_three = num & twos;

    ones |= zero_to_one;
    ones ^= one_to_two;

    twos |= one_to_two;
    twos ^= two_to_three;
  }

  return ones;
}

int main() {
  vector<int> nums0{2, 2, 3, 2};
  vector<int> nums1{0, 1, 0, 1, 0, 1, 99};

  int ret0 = singleNumber(nums0);
  int ret1 = singleNumber(nums1);

  assert(ret0 == 3);
  assert(ret1 == 99);

  return 0;
}
