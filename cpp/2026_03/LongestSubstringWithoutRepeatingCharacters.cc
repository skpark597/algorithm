/** 3. Longest Substring Without Repeating Characters
Given a string s, find the length of the longest substring without duplicate
characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and
"cab" are also correct answers.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.

Constraints:
0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces. */

#include <algorithm>
#include <cassert>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
  int last_pos[128] = {0};
  int left = 0, right = 0, result = 0;

  for (right = 0; right < s.size(); ++right) {
    left = max(left, last_pos[s[right]]);
    result = max(result, right - left + 1);
    last_pos[s[right]] = right + 1;
  }

  return result;
}

int lengthOfLongestSubstring_Initial(string s) {
  unordered_set<char> chars;
  int left = 0, right = 0, result = 0;

  while (right < s.size()) {
    if (chars.find(s[right]) != chars.end()) {
      chars.erase(s[left]);
      left++;
    } else {
      chars.insert(s[right]);
      result = max(result, right - left + 1);
      right++;
    }
  }

  return result;
}

int main() {
  string s0 = "abcabcbb";
  string s1 = "bbbbb";
  string s2 = "pwwkew";

  int ret0 = lengthOfLongestSubstring(s0);
  int ret1 = lengthOfLongestSubstring(s1);
  int ret2 = lengthOfLongestSubstring(s2);

  assert(ret0 == 3);
  assert(ret1 == 1);
  assert(ret2 == 3);

  return 0;
}
