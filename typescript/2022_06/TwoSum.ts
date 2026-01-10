/** 1. Two Sum */
/** Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *  You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *  You can return the answer in any order.
 *
 *  Example 1:
 *  Input: nums = [2,7,11,15], target = 9
 *  Output: [0,1]
 *  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *  Example 2:
 *  Input: nums = [3,2,4], target = 6
 *  Output: [1,2]
 *
 *  Example 3:
 *  Input: nums = [3,3], target = 6
 *  Output: [0,1]
 *
 *  Constraints:
 *  2 <= nums.length <= 10^4
 *  -10^9 <= nums[i] <= 10^9
 *  -10^9 <= target <= 10^9
 *  Only one valid answer exists. */

function twoSum(nums: number[], target: number): number[] {
  let start = 0;
  let end = nums.length - 1;
  const twoNums: number[] = [];
  const indices = [];
  const sorted = [...nums].sort((a, b) => a - b);

  while (start < end) {
    const sum = sorted[start] + sorted[end];

    if (sum === target) {
      twoNums.push(sorted[start]);
      twoNums.push(sorted[end]);
      break;
    }

    if (sum > target) {
      end--;
    } else {
      start++;
    }
  }

  for (let i = 0; i < nums.length; ++i) {
    if (twoNums.includes(nums[i])) indices.push(i);
  }

  return indices;
}

export { twoSum };
