/** 5. Longest Palindromic Substring
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"

Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters. */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
  int len = s.size();
  int start = 0, max_len = 1;

  vector<vector<bool>> dp(len, vector<bool>(len, false));

  for (int i = len - 1; i >= 0; --i) {
    for (int j = i; j < len; ++j) {
      int cur_len = j - i + 1;
      dp[i][j] = (s[i] == s[j]) && (cur_len <= 2 || dp[i + 1][j - 1]);

      if (dp[i][j] && max_len < cur_len) {
        start = i;
        max_len = cur_len;
      }
    }
  }

  return s.substr(start, max_len);
}

int main() {
  string s0 = "babad";
  string s1 = "cbbd";
  string s2 = "a";
  string s3 = "bb";

  string ret0 = longestPalindrome(s0);
  string ret1 = longestPalindrome(s1);
  string ret2 = longestPalindrome(s2);
  string ret3 = longestPalindrome(s3);

  string ans0 = "aba";
  string ans1 = "bb";
  string ans2 = "a";
  string ans3 = "bb";

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);
  assert(ret3 == ans3);

  return 0;
}
