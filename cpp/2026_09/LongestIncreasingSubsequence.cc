/** 300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

Constraints:
1 <= nums.length <= 2500
-10^4 <= nums[i] <= 10^4

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity? */

#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
  vector<int> lis;

  for (int num : nums) {
    auto it = lower_bound(lis.begin(), lis.end(), num);

    if (it == lis.end()) {
      lis.push_back(num);
    } else {
      *it = num;
    }
  }

  return lis.size();
}

int main() {
  vector<int> nums0{10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> nums1{0, 1, 0, 3, 2, 3};
  vector<int> nums2{7, 7, 7, 7, 7, 7, 7};

  int ret0 = lengthOfLIS(nums0);
  int ret1 = lengthOfLIS(nums1);
  int ret2 = lengthOfLIS(nums2);

  assert(ret0 == 4);
  assert(ret1 == 4);
  assert(ret2 == 1);

  return 0;
}
