/** 238. Product of Array Except Self
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of
nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:
2 <= nums.length <= 10^5
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for
space complexity analysis.) */

#include <cassert>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> result(nums.size(), 1);
  int prefix = 1, suffix = 1;

  for (int i = 0; i < nums.size(); ++i) {
    result[i] *= prefix;
    prefix *= nums[i];
  }

  for (int i = nums.size() - 1; i >= 0; --i) {
    result[i] *= suffix;
    suffix *= nums[i];
  }

  return result;
}

int main() {
  vector<int> nums0{1, 2, 3, 4};
  vector<int> nums1{-1, 1, 0, -3, 3};

  vector<int> ret0 = productExceptSelf(nums0);
  vector<int> ret1 = productExceptSelf(nums1);

  vector<int> ans0{24, 12, 8, 6};
  vector<int> ans1{0, 0, 9, 0, 0};

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
