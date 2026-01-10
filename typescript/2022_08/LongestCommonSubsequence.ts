/** 1143. Longest Common Subsequence */
/** Given two strings text1 and text2, return the length of their longest common subsequence.
 *  If there is no common subsequence, return 0.
 *  A subsequence of a string is a new string generated from the original string with some characters
 *  (can be none) deleted without changing the relative order of the remaining characters.
 *
 *  For example, "ace" is a subsequence of "abcde".
 *  A common subsequence of two strings is a subsequence that is common to both strings.
 *
 *  Example 1:
 *  Input: text1 = "abcde", text2 = "ace"
 *  Output: 3
 *  Explanation: The longest common subsequence is "ace" and its length is 3.
 *
 *  Example 2:
 *  Input: text1 = "abc", text2 = "abc"
 *  Output: 3
 *  Explanation: The longest common subsequence is "abc" and its length is 3.
 *
 *  Example 3:
 *  Input: text1 = "abc", text2 = "def"
 *  Output: 0
 *  Explanation: There is no such common subsequence, so the result is 0.
 *
 *  Constraints:
 *  1 <= text1.length, text2.length <= 1000
 *  text1 and text2 consist of only lowercase English characters. */

function initialzeCache(row: number, col: number) {
  const cache: number[][] = new Array(row)
    .fill(null)
    .map(() => new Array(col).fill(-1));

  for (let i = 0; i < col; ++i) {
    cache[row - 1][i] = 0;
  }

  for (let j = 0; j < row; ++j) {
    cache[j][col - 1] = 0;
  }

  return cache;
}

function findCharFromText(text: string, char: string, start = 0) {
  for (let i = start; i < text.length; ++i) {
    if (char === text.charAt(i)) return i;
  }

  return -1;
}

function longestCommonSubsequence(text1: string, text2: string): number {
  const length1 = text1.length;
  const length2 = text2.length;
  const cache = initialzeCache(length1 + 1, length2 + 1);

  for (let i = length1 - 1; i >= 0; --i) {
    const firstChar = text1.charAt(i);

    for (let j = length2 - 1; j >= 0; --j) {
      const firstCharIndex = findCharFromText(text2, firstChar, j);

      cache[i][j] =
        firstCharIndex === -1
          ? cache[i + 1][j]
          : Math.max(cache[i + 1][j], cache[i + 1][firstCharIndex + 1] + 1);
    }
  }

  return cache[0][0];
}

export { longestCommonSubsequence };
