/** 485. Max Consecutive Ones */
/** Given a binary array nums, return the maximum number of consecutive 1's in the array.
 *
 *  Example 1:
 *  Input: nums = [1,1,0,1,1,1]
 *  Output: 3
 *  Explanation: The first two digits or the last three digits are consecutive 1s.
 *  The maximum number of consecutive 1s is 3.
 *
 *  Example 2:
 *  Input: nums = [1,0,1,1,0,1]
 *  Output: 2
 *
 *  Constraints:
 *  1 <= nums.length <= 10^5
 *  nums[i] is either 0 or 1. */

function findMaxConsecutiveOnes(nums: number[]): number {
  let max = 0;
  let prevZeroIndex = -1;

  for (let i = 0; i <= nums.length; ++i) {
    if (i === nums.length || nums[i] === 0) {
      max = Math.max(max, i - prevZeroIndex - 1);
      prevZeroIndex = i;
    }
  }

  return max;
}

export { findMaxConsecutiveOnes };
