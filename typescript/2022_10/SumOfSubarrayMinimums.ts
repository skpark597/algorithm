/** 907. Sum of Subarray Minimums */
/** Given an array of integers arr, find the sum of min(b),
 *  where b ranges over every (contiguous) subarray of arr.
 *  Since the answer may be large, return the answer modulo 10^9 + 7.
 *
 *  Example 1:
 *  Input: arr = [3,1,2,4]
 *  Output: 17
 *  Explanation:
 *  Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
 *  Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 *  Sum is 17.
 *
 *  Example 2:
 *  Input: arr = [11,81,94,43,3]
 *  Output: 444
 *
 *  Constraints:
 *  1 <= arr.length <= 3 * 10^4
 *  1 <= arr[i] <= 3 * 10^4 */

class Stack {
  private elems: number[] = [];

  static create() {
    return new Stack();
  }

  push(elem: number) {
    return this.elems.push(elem);
  }

  empty() {
    return this.elems.length === 0;
  }

  top() {
    return this.empty() ? -1 : this.elems[this.elems.length - 1];
  }

  pop() {
    return this.elems.pop();
  }
}

const modulo = Math.pow(10, 9) + 7;

function sumSubarrayMins(arr: number[]) {
  let sum = 0;
  const stack = Stack.create();
  const newArr = [...arr, Number.MIN_SAFE_INTEGER];

  for (let i = 0; i < newArr.length; ++i) {
    while (!stack.empty() && newArr[stack.top()] > newArr[i]) {
      const cur = stack.pop() as number;
      const prev = stack.top();

      sum += (i - cur) * (cur - prev) * newArr[cur];
    }

    stack.push(i);
  }

  return sum % modulo;
}

export { sumSubarrayMins };
