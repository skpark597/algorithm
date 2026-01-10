/** 2104. Sum of Subarray Ranges */
/** You are given an integer array nums. The range of a subarray of nums is the difference
 *  between the largest and smallest element in the subarray.
 *
 *  Return the sum of all subarray ranges of nums.
 *  A subarray is a contiguous non-empty sequence of elements within an array.
 *
 *  Example 1:
 *  Input: nums = [1,2,3]
 *  Output: 4
 *  Explanation: The 6 subarrays of nums are the following:
 *  [1], range = largest - smallest = 1 - 1 = 0
 *  [2], range = 2 - 2 = 0
 *  [3], range = 3 - 3 = 0
 *  [1,2], range = 2 - 1 = 1
 *  [2,3], range = 3 - 2 = 1
 *  [1,2,3], range = 3 - 1 = 2
 *  So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
 *
 *  Example 2:
 *  Input: nums = [1,3,3]
 *  Output: 4
 *  Explanation: The 6 subarrays of nums are the following:
 *  [1], range = largest - smallest = 1 - 1 = 0
 *  [3], range = 3 - 3 = 0
 *  [3], range = 3 - 3 = 0
 *  [1,3], range = 3 - 1 = 2
 *  [3,3], range = 3 - 3 = 0
 *  [1,3,3], range = 3 - 1 = 2
 *  So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
 *
 *  Example 3:
 *  Input: nums = [4,-2,-3,4,1]
 *  Output: 59
 *  Explanation: The sum of all subarray ranges of nums is 59.
 *
 *  Constraints:
 *  1 <= nums.length <= 1000
 *  -10^9 <= nums[i] <= 10^9 */

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

function sumOfLocalMax(nums: number[]) {
  let sum = 0;
  const stack = Stack.create();
  const newNums = [...nums, Number.MAX_SAFE_INTEGER];

  for (let i = 0; i < newNums.length; ++i) {
    while (!stack.empty() && newNums[stack.top()] < newNums[i]) {
      const cur = stack.pop() as number;
      const prev = stack.top();

      sum += (i - cur) * (cur - prev) * newNums[cur];
    }

    stack.push(i);
  }

  return sum;
}

function sumOfLocalMin(nums: number[]) {
  let sum = 0;
  const stack = Stack.create();
  const newNums = [...nums, Number.MIN_SAFE_INTEGER];

  for (let i = 0; i < newNums.length; ++i) {
    while (!stack.empty() && newNums[stack.top()] > newNums[i]) {
      const cur = stack.pop() as number;
      const prev = stack.top();

      sum += (i - cur) * (cur - prev) * newNums[cur];
    }

    stack.push(i);
  }

  return sum;
}

function subArrayRangesII(nums: number[]) {
  return sumOfLocalMax(nums) - sumOfLocalMin(nums);
}

export { subArrayRangesII };
