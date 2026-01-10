/** 918. Maximum Sum Circular Subarray */
/** Given a circular integer array nums of length n,
 *  return the maximum possible sum of a non-empty subarray of nums.
 *  A circular array means the end of the array connects to the beginning of the array.
 *  Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
 *  A subarray may only include each element of the fixed buffer nums at most once.
 *  Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
 *
 *  Example 1:
 *  Input: nums = [1,-2,3,-2]
 *  Output: 3
 *  Explanation: Subarray [3] has maximum sum 3.
 *
 *  Example 2:
 *  Input: nums = [5,-3,5]
 *  Output: 10
 *  Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
 *
 *  Example 3:
 *  Input: nums = [-3,-2,-3]
 *  Output: -2
 *  Explanation: Subarray [-2] has maximum sum -2.
 *
 *  Constraints:
 *  n == nums.length
 *  1 <= n <= 3 * 10^4
 *  -3 * 10^4 <= nums[i] <= 3 * 10^4 */

/**
 * nums = [a[0], a[1], ... , a[n-1]]
 * S[i, j] = a[i] + a[i+1] + ... + a[j]
 * R[i] = S[0, i]
 * T[i] = max(S[i, n-1], S[i+1, n-1], ..., S[n-1, n-1])
 * L[i] = local maximum sum of ending at index i (not circular)
 */
function maxSubarraySumCircular(nums: number[]): number {
  const R = new Array(nums.length).fill(Number.MIN_SAFE_INTEGER);
  const L = new Array(nums.length).fill(Number.MIN_SAFE_INTEGER);
  const T = new Array(nums.length).fill(Number.MIN_SAFE_INTEGER);
  let sum = 0;
  let ret = Number.MIN_SAFE_INTEGER;

  for (let i = 0; i < nums.length; ++i) {
    R[i] = i === 0 ? nums[i] : nums[i] + R[i - 1];
  }

  for (let i = nums.length - 1; i >= 0; --i) {
    sum += nums[i];
    T[i] = i === nums.length - 1 ? sum : Math.max(T[i + 1], sum);
  }

  for (let i = 0; i < nums.length; ++i) {
    L[i] = i === 0 ? nums[i] : Math.max(nums[i], nums[i] + L[i - 1]);
  }

  for (let i = 0; i < nums.length; ++i) {
    ret =
      i < nums.length - 1
        ? Math.max(ret, Math.max(L[i], R[i] + T[i + 1]))
        : Math.max(ret, L[nums.length - 1]);
  }

  return ret;
}

export { maxSubarraySumCircular };
