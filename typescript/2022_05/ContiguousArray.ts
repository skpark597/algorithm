/** 525. Contiguous Array */
/** Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

Example 1:
Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

Example 2:
Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Constraints:
1 <= nums.length <= 10^5
nums[i] is either 0 or 1. */

function findMaxLength(nums: number[]): number {
  const sumToIndex: Record<number, number> = {};
  let sum = 0;
  let max = 0;

  for (let i = 0; i < nums.length; ++i) {
    sum += nums[i] === 1 ? 1 : -1;

    if (sum === 0) {
      max = i + 1;
    } else if (sumToIndex[sum] !== undefined) {
      max = Math.max(max, i - sumToIndex[sum]);
    } else {
      sumToIndex[sum] = i;
    }
  }

  return max;
}

export { findMaxLength };
