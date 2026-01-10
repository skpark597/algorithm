/* 22. Generate Parentheses */
/** Given n pairs of parentheses,
 *  write a function to generate all combinations of well-formed parentheses.
 *
 *  Example 1:
 *  Input: n = 3
 *  Output: ["((()))","(()())","(())()","()(())","()()()"]
 *
 *  Example 2:
 *  Input: n = 1
 *  Output: ["()"]
 *
 *  Constraints:
 *  1 <= n <= 8 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// left : the count of left parenthesis remained
// right : the count of right parenthesis remained
void generateParenthesisInternal(vector<string> &result, string parenthesis,
                                 int left, int right) {
  if (left == 0 && right == 0) {
    result.push_back(parenthesis);
    return;
  }

  if (left > 0)
    generateParenthesisInternal(result, parenthesis + '(', left - 1, right);

  if (right > 0 && left < right)
    generateParenthesisInternal(result, parenthesis + ')', left, right - 1);
}

vector<string> generateParenthesis(int n) {
  vector<string> result;
  string parenthesis = "";

  generateParenthesisInternal(result, parenthesis, n, n);
  return result;
}

int main() {
  int num0 = 3;
  int num1 = 1;

  vector<string> ans0 = generateParenthesis(num0);
  vector<string> ans1 = generateParenthesis(num1);

  for (string iter : ans0) {
    cout << iter;
  }
  cout << endl; // ["((()))","(()())","(())()","()(())","()()()"]

  for (string iter : ans1) {
    cout << iter;
  }
  cout << endl; // ["()"]
}