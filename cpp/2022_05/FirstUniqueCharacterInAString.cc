/** 387. First Unique Character in a String */
/** Given a string s, find the first non-repeating character in it and return
its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:
1 <= s.length <= 10^5
s consists of only lowercase English letters.*/

#include <cstring>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
  bool isUnique[26];
  unordered_map<char, int> charIndices;
  int minIndex = -1;

  memset(isUnique, 0, sizeof(isUnique));

  for (int i = 0; i < s.length(); ++i) {
    if (charIndices.find(s[i]) != charIndices.end()) {
      isUnique[s[i] - 'a'] = false;
    } else {
      charIndices.insert({s[i], i});
      isUnique[s[i] - 'a'] = true;
    }
  }

  for (auto &it : charIndices) {
    if (!isUnique[it.first - 'a']) {
      continue;
    }

    if (minIndex == -1) {
      minIndex = it.second;
    } else {
      minIndex = min(minIndex, it.second);
    }
  }

  return minIndex;
}

int main() {
  string s0 = "leetcode";
  string s1 = "loveleetcode";
  string s2 = "aabb";

  int ans0 = firstUniqChar(s0);
  int ans1 = firstUniqChar(s1);
  int ans2 = firstUniqChar(s2);

  cout << ans0 << endl; // 0
  cout << ans1 << endl; // 2
  cout << ans2 << endl; // -1

  return 0;
}