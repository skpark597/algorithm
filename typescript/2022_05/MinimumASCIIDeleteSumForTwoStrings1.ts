/** 712. Minimum ASCII Delete Sum for Two Strings */
/** Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

Example 1:
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

Example 2:
Input: s1 = "delete", s2 = "leet"
Output: 403
Explanation: Deleting "dee" from "delete" to turn the string into "let",
adds 100[d] + 101[e] + 101[e] to the sum.
Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

Constraints:
1 <= s1.length, s2.length <= 1000
s1 and s2 consist of lowercase English letters. */

const cache: number[][] = new Array(1001)
  .fill(0)
  .map(() => new Array(1001).fill(0));

function initialize(s1: string, s2: string) {
  for (let i = 0; i < cache.length; ++i) {
    cache[i].fill(0);
  }

  for (let i = s2.length - 1; i >= 0; --i) {
    cache[s1.length][i] = cache[s1.length][i + 1] + s2.charAt(i).charCodeAt(0);
  }

  for (let i = s1.length - 1; i >= 0; --i) {
    cache[i][s2.length] = cache[i + 1][s2.length] + s1.charAt(i).charCodeAt(0);
  }
}

function minimumDeleteSum1(s1: string, s2: string): number {
  initialize(s1, s2);

  for (let i = s1.length - 1; i >= 0; --i) {
    const first = s1.charAt(i).charCodeAt(0);

    for (let j = s2.length - 1; j >= 0; --j) {
      const notStartedAtFirst = first + cache[i + 1][j];
      let startedAtFirst = Number.MAX_SAFE_INTEGER;
      let beforeFirst = 0;

      for (let k = j; k < s2.length; ++k) {
        if (first === s2.charAt(k).charCodeAt(0)) {
          startedAtFirst = Math.min(
            startedAtFirst,
            beforeFirst + cache[i + 1][k + 1]
          );
        }

        beforeFirst += s2.charAt(k).charCodeAt(0);
      }

      cache[i][j] = Math.min(notStartedAtFirst, startedAtFirst);
    }
  }

  return cache[0][0];
}

export { minimumDeleteSum1 };
