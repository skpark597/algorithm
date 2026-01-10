/** 386. Lexicographical Numbers */
/* Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
 * You must write an algorithm that runs in O(n) time and uses O(1) extra space.
 *
 * Example 1:
 * Input: n = 13
 * Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
 *
 * Example 2:
 * Input: n = 2
 * Output: [1,2]
 *
 * Constraints:
 * 1 <= n <= 5 * 10^4 */

function lexicalOrderInternal(max: string, current: string, output: number[]) {
  const appendZero = `${current}0`;
  const length = current.length;
  const before = current.substring(0, length - 1);
  const end = current.charAt(length - 1);
  const next = before + (+end + 1).toString();

  output.push(+current);

  if (+appendZero <= +max) {
    lexicalOrderInternal(max, appendZero, output);
  }

  if (+next <= +max && end !== "9") {
    lexicalOrderInternal(max, next, output);
  }

  return output;
}

function lexicalOrder(n: number): number[] {
  const max = n.toString();
  const output: number[] = [];

  lexicalOrderInternal(max, "1", output);
  return output;
}
export { lexicalOrder };
