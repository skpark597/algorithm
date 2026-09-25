/** 6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display
this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);


Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:
Input: s = "A", numRows = 1
Output: "A"

Constraints:
1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000 */

#include <cassert>
#include <string>

using namespace std;

string convert(string s, int numRows) {
  if (numRows == 1 || numRows >= s.size()) return s;

  string result;
  result.reserve(s.length());

  int cycle = 2 * numRows - 2;

  for (int i = 0; i < numRows; ++i) {
    for (int j = i; j < s.length(); j += cycle) {
      result += s[j];

      int secondaryIndex = j + cycle - 2 * i;

      if (i != 0 && i != numRows - 1 && secondaryIndex < s.length()) {
        result += s[secondaryIndex];
      }
    }
  }

  return result;
}

int main() {
  string s0 = "PAYPALISHIRING";
  string s1 = "PAYPALISHIRING";
  string s2 = "A";

  int numRows0 = 3;
  int numRows1 = 4;
  int numRows2 = 2;

  string ans0 = "PAHNAPLSIIGYIR";
  string ans1 = "PINALSIGYAHRPI";
  string ans2 = "A";

  string ret0 = convert(s0, numRows0);
  string ret1 = convert(s1, numRows1);
  string ret2 = convert(s2, numRows2);

  assert(ret0 == ans0);
  assert(ret1 == ans1);
  assert(ret2 == ans2);
}
