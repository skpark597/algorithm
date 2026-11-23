/** 150. Evaluate Reverse Polish Notation
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
* The valid operators are '+', '-', '*', and '/'.
* Each operand may be an integer or another expression.
* The division between two integers always truncates toward zero.
* There will not be any division by zero.
* The input represents a valid arithmetic expression in a reverse polish notation.
* The answer and all the intermediate calculations can be represented in a 32-bit integer.

Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:
Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

Constraints:
* 1 <= tokens.length <= 10^4
* tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200]. */

#include <cassert>
#include <functional>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const static unordered_map<string, function<int(int, int)>> ops{
    {"+", plus<int>()},
    {"-", minus<int>()},
    {"*", multiplies<int>()},
    {"/", divides<int>()},
};

int evalRPN(vector<string>& tokens) {
  stack<int> st;

  for (const string& token : tokens) {
    if (auto it = ops.find(token); it != ops.end()) {
      int rhs = st.top();
      st.pop();

      int lhs = st.top();
      st.pop();

      st.push(it->second(lhs, rhs));
    } else {
      st.push(stoi(token));
    }
  }

  return st.top();
}

int main() {
  vector<string> tokens0{"2", "1", "+", "3", "*"};
  vector<string> tokens1{"4", "13", "5", "/", "+"};
  vector<string> tokens2{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

  int ret0 = evalRPN(tokens0);
  int ret1 = evalRPN(tokens1);
  int ret2 = evalRPN(tokens2);

  assert(ret0 == 9);
  assert(ret1 == 6);
  assert(ret2 == 22);

  return 0;
}
