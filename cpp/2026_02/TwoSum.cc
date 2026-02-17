/** 1. Two Sum
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n2) time
complexity? */

#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> num_to_idx;

  for (int i = 0; i < nums.size(); ++i) {
    int complement = target - nums[i];

    if (num_to_idx.count(complement) > 0)
      return vector<int>{num_to_idx[complement], i};

    num_to_idx[nums[i]] = i;
  }

  return {};
}

int main() {
  vector<int> nums0{2, 7, 11, 15};
  vector<int> nums1{3, 2, 4};
  vector<int> nums2{3, 3};

  vector<int> ret0 = twoSum(nums0, 9);
  vector<int> ret1 = twoSum(nums1, 6);
  vector<int> ret2 = twoSum(nums2, 6);

  vector<int> ans0{0, 1};
  vector<int> ans1{1, 2};
  vector<int> ans2{0, 1};

  assert(is_permutation(ret0.begin(), ret0.end(), ans0.begin()));
  assert(is_permutation(ret1.begin(), ret1.end(), ans1.begin()));
  assert(is_permutation(ret2.begin(), ret2.end(), ans2.begin()));

  return 0;
}
