/** 856. Score of Parentheses */
/** Given a balanced parentheses string s, compute the score of the string based on the following rule:
 * 
 *  () has score 1
 *  AB has score A + B, where A and B are balanced parentheses strings.
 *  (A) has score 2 * A, where A is a balanced parentheses string.
 * 
 *  Example 1:
 *  Input: s = "()"
 *  Output: 1
 * 
 *  Example 2:
 *  Input: s = "(())"
 *  Output: 2
 * 
 *  Example 3:
 *  Input: s = "()()"
 *  Output: 2
 * 
 *  Example 4:
 *  Input: s = "(()(()))"
 *  Output: 6
 * 
 *  Note:
 *  s is a balanced parentheses string, containing only ( and ).
 *  2 <= s.length <= 50 **/

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

int scoreOfParentheses(const string &s, int &index) {
    string stack;
    int answer = 0;
    int sum = 0;
    
    stack += s[index];
    index++;

    while (stack.length() > 0) {
        if (s[index] == '(') {
            sum += scoreOfParentheses(s, index);
        } else {
            sum = sum == 0 ? 1 : sum * 2;
            stack.pop_back();
            index++;
        }
    }

    return sum;
}

int scoreOfParentheses(string s) {
    int index = 0;
    int answer = 0;

    while (index < s.length()) {
        answer += scoreOfParentheses(s, index);
    }

    return answer;
}

int main() {
    string s0 = "()";
    string s1 = "(())";
    string s2 = "()()";
    string s3 = "(()(()))";

    int ans0 = scoreOfParentheses(s0);
    int ans1 = scoreOfParentheses(s1);
    int ans2 = scoreOfParentheses(s2);
    int ans3 = scoreOfParentheses(s3);

    cout << ans0 << endl; // 1
    cout << ans1 << endl; // 2
    cout << ans2 << endl; // 2
    cout << ans3 << endl; // 6

    return 0;
}
