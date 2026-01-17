/** 189. Rotate Array
Given an integer array nums, rotate the array to the right by k steps, where k
is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Constraints:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^5

Follow up:
Try to come up with as many solutions as you can. There are at least three
different ways to solve this problem. Could you do it in-place with O(1) extra
space? */

#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

using namespace std;

void rotate_v2(vector<int>& nums, int k) {
  int n = nums.size();
  k %= n;

  reverse(nums.begin(), nums.end());
  reverse(nums.begin(), nums.begin() + k);
  reverse(nums.begin() + k, nums.end());
}

void rotate(vector<int>& nums, int k) {
  int n = nums.size();
  int numCycles = gcd(n, k);
  int elemsPerCycle = n / numCycles;

  for (int start = 0; start < numCycles; start++) {
    int cur = nums[start];
    int idx = (start + k) % n;

    for (int step = 0; step < elemsPerCycle; step++) {
      int temp = nums[idx];

      nums[idx] = cur;
      cur = temp;

      idx = (idx + k) % n;
    }
  }
}

int main() {
  vector<int> nums0 = {1, 2, 3, 4, 5, 6, 7};
  vector<int> nums1 = {-1, -100, 3, 99};
  vector<int> nums2 = {1};

  int k0 = 3;
  int k1 = 2;
  int k2 = 1;

  // rotate(nums0, k0);
  // rotate(nums1, k1);
  // rotate(nums2, k2);

  rotate_v2(nums0, k0);
  rotate_v2(nums1, k1);
  rotate_v2(nums2, k2);

  vector<int> ans0 = {5, 6, 7, 1, 2, 3, 4};
  vector<int> ans1 = {3, 99, -1, -100};
  vector<int> ans2 = {1};

  assert(nums0 == ans0);
  assert(nums1 == ans1);
  assert(nums2 == ans2);

  return 0;
}
