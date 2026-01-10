/**
1717. Maximum Score From Removing Substrings
You are given a string s and two integers x and y. 
You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

Example 1:
Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.

Example 2:
Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

Constraints:
1 <= s.length <= 10^5
1 <= x, y <= 10^4
s consists of lowercase English letters. */

function countPattern(s: string, pattern: string) {
  let count = 0;
  const stack = [];

  for (const char of s) {
    if (stack.at(-1) === pattern[0] && char === pattern[1]) {
      count++;
      stack.pop();
    } else {
      stack.push(char);
    }
  }

  return { count, s: stack.join("") };
}

function maximumGain(s: string, x: number, y: number): number {
  const [first, second] = x > y ? ["ab", "ba"] : ["ba", "ab"];

  const { count: c1, s: rest } = countPattern(s, first);
  const { count: c2 } = countPattern(rest, second);

  return c1 * Math.max(x, y) + c2 * Math.min(x, y);
}

export { maximumGain };
