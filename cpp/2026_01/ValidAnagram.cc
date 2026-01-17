/**
 * 242. Valid Anagram
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * Example 1
 * Input: s = "anagram", t = "nagaram
 * Output: true
 *
 * Example 2
 * Input: s = "rat", t = "car
 * Output: false
 *
 * Constraints
 * 1 <= s.length, t.length <= 5 * 10
 * s and t consist of lowercase English letters
 * Follow up: What if the inputs contain Unicode characters? How would you adapt
 * your solution to such a case? */

#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;

  unordered_map<char, int> count;

  for (int i = 0; i < s.length(); ++i) {
    count[s[i]]++;
    count[t[i]]--;
  }

  for (const auto& [key, val] : count) {
    if (val != 0) return false;
  }

  return true;
}

int main() {
  string s0 = "anagram";
  string t0 = "nagaram";

  string s1 = "rat";
  string t1 = "car";

  bool ret0 = isAnagram(s0, t0);
  bool ret1 = isAnagram(s1, t1);

  assert(ret0 == true);
  assert(ret1 == false);

  return 0;
}