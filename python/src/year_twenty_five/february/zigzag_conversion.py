"""
6. Zigzag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

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
1 <= numRows <= 1000
"""

from math import ceil


directions = [[1, 0], [-1, 1], [0, 1]]


class Solution:
    def convert(self, s: str, num_rows: int) -> str:
        if num_rows == 1:
            return s

        sections = ceil(len(s) / (2 * num_rows - 2))
        num_cols = sections * (num_rows - 1)
        letters = [[""] * num_cols for _ in range(num_rows)]
        row, col, direction = 0, 0, directions[0]

        for letter in s:
            letters[row][col] = letter

            if row == num_rows - 1:
                direction = directions[1]
            elif row == 0:
                direction = directions[0]

            row += direction[0]
            col += direction[1]

        return "".join("".join(row) for row in letters)
