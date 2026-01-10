/** 1525. Number of Good Ways to Split a String */
/** You are given a string s.
 *  A split is called good if you can split s into two non-empty strings
 *  sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s)
 *  and the number of distinct letters in sleft and sright is the same.
 *
 *  Return the number of good splits you can make in s.
 *
 *  Example 1:
 *  Input: s = "aacaba"
 *  Output: 2
 *  Explanation: There are 5 ways to split "aacaba" and 2 of them are good.
 *  ("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
 *  ("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
 *  ("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
 *  ("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
 *  ("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
 *
 *  Example 2:
 *  Input: s = "abcd"
 *  Output: 1
 *  Explanation: Split the string as follows ("ab", "cd").
 *
 *  Constraints:
 *  1 <= s.length <= 10^5
 *  s consists of only lowercase English letters. */

function decrease(count: Record<string, number>, character: string) {
  count[character] = count[character] - 1;

  if (count[character] === 0) {
    delete count[character];
  }
}

function increase(count: Record<string, number>, character: string) {
  count[character] = count[character] ? count[character] + 1 : 1;
}

function hasSameDistinct(
  leftCount: Record<string, number>,
  rightCount: Record<string, number>
) {
  return Object.keys(leftCount).length === Object.keys(rightCount).length;
}

function getCountMap(s: string) {
  const count: Record<string, number> = {};
  for (const character of s) increase(count, character);

  return count;
}

function numSplits(s: string): number {
  const leftCount: Record<string, number> = {};
  const rightCount = getCountMap(s);
  let numberOfSplits = 0;

  for (const character of s) {
    increase(leftCount, character);
    decrease(rightCount, character);

    if (hasSameDistinct(leftCount, rightCount)) numberOfSplits++;
  }

  return numberOfSplits;
}

export { numSplits };
