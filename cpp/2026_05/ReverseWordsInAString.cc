/** 151. Reverse Words in a String
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only
have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Constraints:
1 <= s.length <= 10^4
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space? */

#include <algorithm>
#include <cassert>
#include <string>

using namespace std;

void trim(string& s) {
  int left = 0, right = 0;

  while (right < s.size()) {
    if (s[right] == ' ' && (left == 0 || s[left - 1] == ' ')) {
      right++;
    } else {
      s[left] = s[right];
      left++;
      right++;
    }
  }

  for (int i = 0; i < right - left; ++i) s.pop_back();
  if (s.back() == ' ') s.pop_back();
}

void reverseInPlace(string& s) {
  reverse(s.begin(), s.end());

  auto left = s.begin();

  for (auto right = s.begin(); right < s.end() + 1; ++right) {
    if (right == s.end() || *right == ' ') {
      reverse(left, right);
      left = right + 1;
    }
  }
}

string reverseWords(string s) {
  trim(s);
  reverseInPlace(s);

  return s;
}

int main() {
  string s0 = "the  sky   is blue";
  string s1 = "  hello world  ";
  string s2 = "a good   example";

  string ret0 = reverseWords(s0);
  string ret1 = reverseWords(s1);
  string ret2 = reverseWords(s2);

  string ans0 = "blue is sky the";
  string ans1 = "world hello";
  string ans2 = "example good a";

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);

  return 0;
}
