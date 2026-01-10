/** 795. Number of Subarrays with Bounded Maximum */
/** Given an integer array nums and two integers left and right,
 *  return the number of contiguous non-empty subarrays such that the value of
 *  the maximum array element in that subarray is in the range [left, right].
 *  The test cases are generated so that the answer will fit in a 32-bit integer.
 *
 *  Example 1:
 *  Input: nums = [2,1,4,3], left = 2, right = 3
 *  Output: 3
 *  Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
 *
 *  Example 2:
 *  Input: nums = [2,9,2,5,6], left = 2, right = 8
 *  Output: 7
 *
 *  Constraints:
 *  1 <= nums.length <= 10^5
 *  0 <= nums[i] <= 10^9
 *  0 <= left <= right <= 10^9 */

function numSubarrayBoundedMax(
  nums: number[],
  left: number,
  right: number
): number {
  let answer = 0;
  let max = -1;
  let length = 0;
  let lessThanLeft = 0;

  nums.push(Number.MAX_SAFE_INTEGER);

  for (const num of nums) {
    max = Math.max(max, num);

    if (num < left) {
      lessThanLeft++;
    } else {
      answer -= (lessThanLeft * (lessThanLeft + 1)) / 2;
      lessThanLeft = 0;
    }

    if (max <= right) {
      length++;
    } else {
      answer += (length * (length + 1)) / 2;
      length = 0;
      max = -1;
    }
  }

  return answer;
}

export { numSubarrayBoundedMax };
