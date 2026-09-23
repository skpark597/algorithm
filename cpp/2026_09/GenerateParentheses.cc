/** 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Constraints:
1 <= n <= 8 */

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

void backtracking(vector<string>& combs, string& cur, int left, int right, int n) {
  if (cur.size() == 2 * n) {
    combs.push_back(cur);
    return;
  }

  if (left < n) {
    cur.push_back('(');
    backtracking(combs, cur, left + 1, right, n);
    cur.pop_back();
  }

  if (left > right) {
    cur.push_back(')');
    backtracking(combs, cur, left, right + 1, n);
    cur.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  vector<string> combs;
  string cur = "";

  backtracking(combs, cur, 0, 0, n);

  return combs;
}

int main() {
  int n0 = 3;
  int n1 = 1;

  vector<string> ret0 = generateParenthesis(n0);
  vector<string> ret1 = generateParenthesis(n1);

  sort(ret0.begin(), ret0.end());
  sort(ret1.begin(), ret1.end());

  vector<string> ans0{"((()))", "(()())", "(())()", "()(())", "()()()"};
  vector<string> ans1{"()"};

  sort(ans0.begin(), ans0.end());
  sort(ans1.begin(), ans1.end());

  assert(ret0 == ans0);
  assert(ret1 == ans1);
}