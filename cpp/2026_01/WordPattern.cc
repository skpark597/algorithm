/** 290. Word Pattern
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in s. Specifically:

Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.

Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Explanation:
The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

Constraints:
1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space. */

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool wordPattern(string pattern, string s) {
  vector<string> words;

  stringstream ss(s);
  string word;

  while (ss >> word) words.push_back(word);
  if (pattern.size() != words.size()) return false;

  unordered_map<char, string> letterToWord;
  unordered_map<string, char> wordToLetter;

  for (int i = 0; i < words.size(); ++i) {
    char letter = pattern[i];
    string word = words[i];

    if ((letterToWord.count(letter) && letterToWord[letter] != word) ||
        (wordToLetter.count(word) && wordToLetter[word] != letter))
      return false;

    letterToWord[letter] = word;
    wordToLetter[word] = letter;
  }

  return true;
}

int main() {
  unordered_map<string, int> test;

  string pattern0 = "abba";
  string pattern1 = "abba";
  string pattern2 = "aaaa";
  string pattern3 = "aba";

  string s0 = "dog cat cat dog";
  string s1 = "dog cat cat fish";
  string s2 = "dog cat cat dog";
  string s3 = "dog cat cat";

  bool ret0 = wordPattern(pattern0, s0);
  bool ret1 = wordPattern(pattern1, s1);
  bool ret2 = wordPattern(pattern2, s2);
  bool ret3 = wordPattern(pattern3, s3);

  assert(ret0 == true);
  assert(ret1 == false);
  assert(ret2 == false);
  assert(ret3 == false);

  return 0;
}