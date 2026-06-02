/* 28. Find the Index of the First Occurrence in a String

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:
1 <= haystack.length, needle.length <= 10^4
haystack and needle consist of only lowercase English characters. */

#include <cassert>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
  int n = haystack.size(), m = needle.size();

  for (int i = 0; i <= n - m; ++i) {
    if (haystack.substr(i, m) == needle) return i;
  }

  return -1;
}

int main() {
  string haystack0 = "sadbutsad";
  string haystack1 = "leetcode";

  string needle0 = "sad";
  string needle1 = "leeto";

  int ret0 = strStr(haystack0, needle0);
  int ret1 = strStr(haystack1, needle1);

  assert(ret0 == 0);
  assert(ret1 == -1);

  return 0;
}
