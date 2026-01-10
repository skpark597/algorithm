/** 698. Partition to K Equal Sum Subsets */
/** Given an integer array nums and an integer k,
 *  return true if it is possible to divide this array into k non-empty
 *  subsets whose sums are all equal.
 *
 *  Example 1:
 *  Input: nums = [4,3,2,3,5,2,1], k = 4
 *  Output: true
 *  Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 *
 *  Example 2:
 *  Input: nums = [1,2,3,4], k = 3
 *  Output: false
 *
 *  Constraints:
 *  1 <= k <= nums.length <= 16
 *  1 <= nums[i] <= 10^4
 *  The frequency of each element is in the range [1, 4]. */

function backtracking(
  nums: number[],
  visited: boolean[],
  currentSum: number,
  target: number,
  i: number,
  k: number
): boolean {
  if (k === 1) return true;
  if (currentSum === target)
    return backtracking(nums, visited, 0, target, 0, k - 1);

  if (i >= nums.length) return false;

  for (let j = i; j < nums.length; ++j) {
    if (visited[j] || currentSum + nums[j] > target) continue;

    visited[j] = true;
    if (backtracking(nums, visited, currentSum + nums[j], target, j + 1, k))
      return true;

    visited[j] = false;
  }

  return false;
}

function canPartitionKSubsets(nums: number[], k: number): boolean {
  const length = nums.length;
  const sum = nums.reduce((previous, current) => previous + current);

  if (sum % k !== 0) return false;

  const visited: boolean[] = new Array(length).fill(false);
  const target = sum / k;

  return backtracking(nums, visited, 0, target, 0, k);
}

export { canPartitionKSubsets };
