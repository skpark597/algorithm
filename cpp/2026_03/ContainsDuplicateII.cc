/** 219. Contains Duplicate II
Given an integer array nums and an integer k, return true if there are two
distinct indices i and j in the array such that nums[i] == nums[j] and abs(i -
j)
<= k.

Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false

Constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
0 <= k <= 10^5 */

#include <cassert>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> idxs;

  for (int i = 0; i < nums.size(); ++i) {
    int cur = nums[i];

    if (idxs.find(cur) != idxs.end() && abs(idxs[cur] - i) <= k) return true;
    idxs[cur] = i;
  }

  return false;
}

int main() {
  vector<int> nums0{1, 2, 3, 1};
  vector<int> nums1{1, 0, 1, 1};
  vector<int> nums2{1, 2, 3, 1, 2, 3};

  int k0 = 3;
  int k1 = 1;
  int k2 = 2;

  bool ret0 = containsNearbyDuplicate(nums0, k0);
  bool ret1 = containsNearbyDuplicate(nums1, k1);
  bool ret2 = containsNearbyDuplicate(nums2, k2);

  assert(ret0 == true);
  assert(ret1 == true);
  assert(ret2 == false);

  return 0;
}
