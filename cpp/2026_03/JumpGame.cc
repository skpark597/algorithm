/**55. Jump Game
You are given an integer array nums. You are initially positioned at the array's
first index, and each element in the array represents your maximum jump length
at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump
length is 0, which makes it impossible to reach the last index.

Constraints:
1 <= nums.length <= 10^4
0 <= nums[i] <= 10^5 */

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

bool canJumpTo(vector<int>& nums, vector<int>& dp, int dest) {
  if (dp[dest] != -1) return dp[dest] == 1;

  for (int i = dest - 1; i >= 0; --i) {
    if (nums[i] >= dest - i && canJumpTo(nums, dp, i)) {
      dp[i] = 1;
      return true;
    }
  }

  dp[dest] = 0;
  return false;
}

bool canJumpDP(vector<int>& nums) {
  vector<int> dp(nums.size(), -1);
  dp[0] = 1;

  return canJumpTo(nums, dp, nums.size() - 1);
}

bool canJump(vector<int>& nums) {
  int maxReach = 0;

  for (int i = 0; i < nums.size(); ++i) {
    if (i > maxReach) return false;
    maxReach = max(maxReach, i + nums[i]);

    if (maxReach >= nums.size() - 1) return true;
  }

  return false;
}

int main() {
  vector<int> nums0{2, 3, 1, 1, 4};
  vector<int> nums1{3, 2, 1, 0, 4};

  bool ret0 = canJumpDP(nums0);
  bool ret1 = canJumpDP(nums1);

  assert(ret0 == true);
  assert(ret1 == false);

  return 0;
}
