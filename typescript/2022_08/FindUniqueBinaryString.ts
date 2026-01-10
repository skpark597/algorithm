/** 1980. Find Unique Binary String */
/** Given an array of strings nums containing n unique binary strings each of length n,
 *  return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
 *
 *  Example 1:
 *  Input: nums = ["01","10"]
 *  Output: "11"
 *  Explanation: "11" does not appear in nums. "00" would also be correct.
 *
 *  Example 2:
 *  Input: nums = ["00","01"]
 *  Output: "11"
 *  Explanation: "11" does not appear in nums. "10" would also be correct.
 *
 *  Example 3:
 *  Input: nums = ["111","011","001"]
 *  Output: "101"
 *  Explanation: "101" does not appear in nums. "000", "010", "100", and "110" would also be correct.
 *
 *  Constraints:
 *  n == nums.length
 *  1 <= n <= 16
 *  nums[i].length == n
 *  nums[i] is either '0' or '1'.
 *  All the strings of nums are unique. */

function addLeadingZeros(binary: string, length: number) {
  let leadingZeros = "";

  for (let i = 0; i < length - binary.length; ++i) {
    leadingZeros += "0";
  }

  return leadingZeros + binary;
}

function getBinaryString(number: number) {
  let currentNumber = number;
  let binaryString = "";

  while (currentNumber > 0) {
    const remainder = currentNumber % 2;

    binaryString = remainder + binaryString;
    currentNumber = (currentNumber - remainder) / 2;
  }

  return binaryString;
}

function findDifferentBinaryString(nums: string[]): string {
  const length = nums.length;
  const set = new Set(nums);

  for (let i = 0; i < Math.pow(2, length); ++i) {
    const binary = getBinaryString(i);
    const addedZeros = addLeadingZeros(binary, length);

    if (!set.has(addedZeros)) return addedZeros;
  }

  return "-";
}

export { findDifferentBinaryString };
