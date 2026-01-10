/** 258. Add Digits */

import { sum } from "lodash";

/** Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
 *
 *  Example 1:
 *  Input: num = 38
 *  Output: 2
 *  Explanation: The process is
 *  38 --> 3 + 8 --> 11
 *  11 --> 1 + 1 --> 2
 *  Since 2 has only one digit, return it.
 *
 *  Example 2:
 *  Input: num = 0
 *  Output: 0
 *
 *  Constraints:
 *  0 <= num <= 2^31 - 1
 *  Follow up: Could you do it without any loop/recursion in O(1) runtime? */

function addDigitsOnce(num: number) {
  let sum = 0;

  while (num > 0) {
    sum += num % 10;
    num = Math.floor(num / 10);
  }

  return sum;
}

function addDigits(num: number): number {
  let sum = addDigitsOnce(num);

  while (sum >= 10) {
    sum = addDigitsOnce(sum);
  }

  return sum;
}

export { addDigits };
