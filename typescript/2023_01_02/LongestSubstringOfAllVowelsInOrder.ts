/** 1839. Longest Substring Of All Vowels in Order */
/** A string is considered beautiful if it satisfies the following conditions:
 *  Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
 *  The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
 *  For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful,
 *  but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.
 *
 *  Given a string word consisting of English vowels, return the length of the longest beautiful substring of word.
 *  If no such substring exists, return 0.
 *
 *  A substring is a contiguous sequence of characters in a string.
 *
 *  Example 1:
 *  Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
 *  Output: 13
 *  Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
 *
 *  Example 2:
 *  Input: word = "aeeeiiiioooauuuaeiou"
 *  Output: 5
 *  Explanation: The longest beautiful substring in word is "aeiou" of length 5.
 *
 *  Example 3:
 *  Input: word = "a"
 *  Output: 0
 *  Explanation: There is no beautiful substring, so return 0.
 *
 *  Constraints:
 *  1 <= word.length <= 5 * 10^5
 *  word consists of characters 'a', 'e', 'i', 'o', and 'u'. */

const nextBeautiful: Record<string, string> = {
  a: "e",
  e: "i",
  i: "o",
  o: "u",
};

function longestBeautifulSubstring(word: string): number {
  if (word.length < 5) return 0;

  let result = 0;
  let start = -1;
  let previous = word.charAt(0);

  for (let end = 0; end < word.length; ++end) {
    const current = word[end];
    const next = end === word.length - 1 ? null : word[end + 1];

    if (start > -1 && current === nextBeautiful[previous]) {
      previous = current;
    } else if (start > -1 && current !== previous) {
      start = -1;
    }

    if (start === -1 && current === "a") {
      start = end;
      previous = current;
    } else if (start > -1 && current === "u" && next !== "u") {
      result = Math.max(result, end - start + 1);
      start = -1;
    }
  }

  return result;
}

export { longestBeautifulSubstring };
