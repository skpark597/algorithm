/** 45. Jump Game II
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index
i, you can jump to any index (i + j) where:

* 0 <= j <= nums[i] and
* i + j < n

Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index
n-1.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to
the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1]. */

#include <cassert>
#include <climits>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
  int jumps = 0;
  int current_end = 0;
  int max_reach = 0;

  for (int i = 0; i < nums.size() - 1; ++i) {
    max_reach = max(max_reach, i + nums[i]);

    if (i == current_end) {
      jumps++;
      current_end = max_reach;
    }
  }

  return jumps;
}

int jump_dp(vector<int>& nums) {
  int n = nums.size();
  vector<int> dp(n, INT_MAX);

  dp[n - 1] = 0;

  for (int i = n - 2; i >= 0; --i) {
    for (int j = 1; j <= nums[i]; ++j) {
      if (i + j >= n || dp[i + j] == INT_MAX) continue;
      dp[i] = min(dp[i], dp[i + j] + 1);
    }
  }

  return dp[0];
}

int main() {
  vector<int> nums0{2, 3, 1, 1, 4};
  vector<int> nums1{2, 3, 0, 1, 4};

  int ret0 = jump(nums0);
  int ret1 = jump(nums1);

  assert(ret0 == 2);
  assert(ret1 == 2);

  return 0;
}