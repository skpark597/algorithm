/** 2375. Construct Smallest Number From DI String */
/** You are given a 0-indexed string pattern of length n consisting of the
 *  characters 'I' meaning increasing and 'D' meaning decreasing.
 *  A 0-indexed string num of length n + 1 is created using the following conditions:
 *
 *  num consists of the digits '1' to '9', where each digit is used at most once.
 *  If pattern[i] == 'I', then num[i] < num[i + 1].
 *  If pattern[i] == 'D', then num[i] > num[i + 1].
 *  Return the lexicographically smallest possible string num that meets the conditions.
 *
 *  Example 1:
 *  Input: pattern = "IIIDIDDD"
 *  Output: "123549876"
 *  Explanation:
 *  At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
 *  At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
 *  Some possible values of num are "245639871", "135749862", and "123849765".
 *  It can be proven that "123549876" is the smallest possible num that meets the conditions.
 *  Note that "123414321" is not possible because the digit '1' is used more than once.
 *
 *  Example 2:
 *  Input: pattern = "DDD"
 *  Output: "4321"
 *  Explanation:
 *  Some possible values of num are "9876", "7321", and "8742".
 *  It can be proven that "4321" is the smallest possible num that meets the conditions.
 *
 *  Constraints:
 *  1 <= pattern.length <= 8
 *  pattern consists of only the letters 'I' and 'D'. */

const digitUsed = new Array<boolean>(10).fill(false);

function smallestUpperBound(given: number) {
  return digitUsed.findIndex((used, digit) => !used && digit > given);
}

function smallestLowerBound(given: number) {
  return digitUsed.findIndex((used, digit) => !used && digit < given);
}

function backtracking(pattern: string, index: number, current: string): string {
  if (index === pattern.length) return current;

  const letter = pattern.charAt(index);
  const lastDigit = +current.charAt(current.length - 1);
  const nextStart =
    letter === "I"
      ? smallestUpperBound(lastDigit)
      : smallestLowerBound(lastDigit);
  const nextEnd = letter === "I" ? 9 : lastDigit - 1;

  if (nextStart === -1) return "";

  for (let next = nextStart; next <= nextEnd; ++next) {
    digitUsed[next] = true;
    const result = backtracking(pattern, index + 1, `${current}${next}`);
    digitUsed[next] = false;

    if (result.length > 0) return result;
  }

  return "";
}

function smallestNumber(pattern: string) {
  digitUsed[0] = true;
  const smallest = backtracking(`I${pattern}`, 0, "0");

  return (+smallest).toString();
}

export { smallestNumber };
