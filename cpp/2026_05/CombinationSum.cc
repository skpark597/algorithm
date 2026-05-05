/** 39. Combination Sum
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of
candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency
of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150
combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []

Constraints:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40 */

#include <cassert>
#include <vector>

#include "Util.h"

using namespace std;
using namespace util;

void backtracking(vector<vector<int>>& result, vector<int>& comb, vector<int>& candidates, int idx, int cur) {
  if (cur == 0) {
    result.push_back(comb);
    return;
  }

  for (int i = idx; i < candidates.size(); ++i) {
    if (cur - candidates[i] < 0) continue;

    comb.push_back(candidates[i]);
    backtracking(result, comb, candidates, i, cur - candidates[i]);
    comb.pop_back();
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> result;
  vector<int> comb;

  backtracking(result, comb, candidates, 0, target);

  return result;
}

int main() {
  vector<int> candidates0{2, 3, 6, 7};
  vector<int> candidates1{2, 3, 5};
  vector<int> candidates2{2};

  int target0 = 7;
  int target1 = 8;
  int target2 = 1;

  vector<vector<int>> ret0 = combinationSum(candidates0, target0);
  vector<vector<int>> ret1 = combinationSum(candidates1, target1);
  vector<vector<int>> ret2 = combinationSum(candidates2, target2);

  vector<vector<int>> ans0 = {{2, 2, 3}, {7}};
  vector<vector<int>> ans1 = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
  vector<vector<int>> ans2 = {};

  assert(isEqualUnordered(ret0, ans0));
  assert(isEqualUnordered(ret1, ans1));
  assert(isEqualUnordered(ret2, ans2));

  return 0;
}
