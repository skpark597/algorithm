/** 46. Permutations
Given an array nums of distinct integers, return all the possible permutations.
You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique. */

#include <algorithm>
#include <cassert>
#include <set>
#include <vector>

#include "Util.h"

using namespace std;
using namespace util;

void backtracking(vector<int>& nums, vector<vector<int>>& perms,
                  vector<int>& perm) {
  if (perm.size() == nums.size()) {
    perms.push_back(perm);
    return;
  }

  for (int i = 0; i < nums.size(); ++i) {
    if (find(perm.begin(), perm.end(), nums[i]) != perm.end()) continue;

    perm.push_back(nums[i]);
    backtracking(nums, perms, perm);
    perm.pop_back();
  }
}

vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> perms;
  vector<int> perm;

  backtracking(nums, perms, perm);

  return perms;
}

int main() {
  vector<int> nums0{1, 2, 3};
  vector<int> nums1{0, 1};
  vector<int> nums2{1};

  vector<vector<int>> ret0 = permute(nums0);
  vector<vector<int>> ret1 = permute(nums1);
  vector<vector<int>> ret2 = permute(nums2);

  vector<vector<int>> ans0{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                           {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
  vector<vector<int>> ans1{{0, 1}, {1, 0}};
  vector<vector<int>> ans2{{1}};

  assert(isEqualUnordered(ret0, ans0));
  assert(isEqualUnordered(ret1, ans1));
  assert(isEqualUnordered(ret2, ans2));

  return 0;
}
