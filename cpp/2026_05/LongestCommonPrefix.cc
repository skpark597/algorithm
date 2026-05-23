/** 14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty. */

#include <cassert>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefixNew(vector<string>& strs) {
  if (strs.size() == 1) return strs[0];

  string result = strs[0];

  for (auto it = strs.begin() + 1; it != strs.end(); ++it) {
    const string& str = *it;
    int i = 0;

    while (i < result.size() && i < str.size() && result[i] == str[i]) i++;
    result = result.substr(0, i);

    if (result.empty()) return "";
  }

  return result;
}

string longestCommonPrefix(vector<string>& strs) {
  if (strs.size() == 1) return strs[0];

  string result = strs[0];

  for (const auto& str : strs) {
    int i = 0, cur_size = result.size();

    for (i = 0; i < cur_size; ++i)
      if (i >= str.size() || result[i] != str[i]) break;

    for (int j = 0; j < cur_size - i; ++j) result.pop_back();
  }

  return result;
}

int main() {
  vector<string> strs0{"flower", "flow", "flight"};
  vector<string> strs1{"dog", "racecar", "car"};

  string ret0 = longestCommonPrefixNew(strs0);
  string ret1 = longestCommonPrefixNew(strs1);

  string ans0 = "fl";
  string ans1 = "";

  assert(ret0 == ans0);
  assert(ret1 == ans1);

  return 0;
}
