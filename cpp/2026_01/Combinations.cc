/* 77. Combinations
Given two integers n and k, return all possible combinations of k numbers chosen
from the range [1, n].

You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be
the same combination.

Example 2:
Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

Constraints:
1 <= n <= 20
1 <= k <= n */

#include <cassert>
#include <vector>

using namespace std;

void backtracking(vector<vector<int>>& result, vector<int>& comb, int n, int k,
                  int cur) {
  if (comb.size() == k) {
    result.push_back(comb);
    return;
  }

  if ((k - (int)comb.size()) > (n - cur + 1)) return;

  comb.push_back(cur);
  backtracking(result, comb, n, k, cur + 1);

  comb.pop_back();
  backtracking(result, comb, n, k, cur + 1);
}

vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> result;
  vector<int> comb;

  comb.reserve(k);
  backtracking(result, comb, n, k, 1);

  return result;
}

int main() {
  int n0 = 4, k0 = 2;
  int n1 = 1, k1 = 1;

  vector<vector<int>> ret0 = combine(n0, k0);
  vector<vector<int>> ret1 = combine(n1, k1);

  vector<vector<int>> ans0{{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
  vector<vector<int>> ans1{{1}};

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
