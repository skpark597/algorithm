/**17. Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = "2"
Output: ["a","b","c"]


Constraints:
1 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9']. */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void backtracking(const string& digits, int index, string& cur,
                  vector<string>& result, const vector<string>& table) {
  if (index == digits.length()) {
    result.push_back(cur);
    return;
  }

  for (char letter : table[digits[index] - '0']) {
    cur.push_back(letter);
    backtracking(digits, index + 1, cur, result, table);
    cur.pop_back();
  }
}

vector<string> letterCombinations(string digits) {
  static const vector<string> table{"",    "",    "abc",  "def", "ghi",
                                    "jkl", "mno", "pqrs", "tuv", "wxyz"};

  vector<string> result;
  string cur;
  cur.reserve(digits.length());

  backtracking(digits, 0, cur, result, table);

  return result;
}

int main() {
  string digits0 = "23";
  string digits1 = "2";

  vector<string> ret0 = letterCombinations(digits0);
  vector<string> ret1 = letterCombinations(digits1);

  vector<string> ans0{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  vector<string> ans1{"a", "b", "c"};

  sort(ret0.begin(), ret0.end());
  sort(ret1.begin(), ret1.end());

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
