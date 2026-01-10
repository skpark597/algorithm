/** 491. Increasing Subsequences */
/** Given an integer array nums, return all the different possible increasing subsequences of
 *  the given array with at least two elements. You may return the answer in any order.
 *  The given array may contain duplicates, and two equal integers should also be considered
 *  a special case of increasing sequence.
 *
 *  Example 1:
 *  Input: nums = [4,6,7,7]
 *  Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 *
 *  Example 2:
 *  Input: nums = [4,4,3,2,1]
 *  Output: [[4,4]]
 *
 *  Constraints:
 *  1 <= nums.length <= 15
 *  -100 <= nums[i] <= 100 */

function isConatinedIn(sequence: number[], sequences: number[][]) {
  for (const iter of sequences) {
    if (iter.length !== sequence.length) continue;

    const isNotSame = iter.some((num, index) => num !== sequence[index]);
    if (!isNotSame) return true;
  }

  return false;
}

function findStartedAt(
  nums: number[],
  startIndex: number,
  currentIndex: number,
  sequence: number[],
  sequences: number[][]
) {
  const currentNum = nums[currentIndex];
  const lastNumInSequence = sequence[sequence.length - 1];
  const sequenceAddedCurrentNum = [...sequence, nums[currentIndex]];
  const isIncreasing = currentNum >= lastNumInSequence;

  if (currentIndex === nums.length - 1) {
    if (!isConatinedIn(sequence, sequences) && sequence.length >= 2) {
      sequences.push(sequence);
    }

    if (!isConatinedIn(sequenceAddedCurrentNum, sequences) && isIncreasing) {
      sequences.push(sequenceAddedCurrentNum);
    }

    return;
  }

  findStartedAt(nums, startIndex, currentIndex + 1, sequence, sequences);

  if (isIncreasing) {
    findStartedAt(
      nums,
      startIndex,
      currentIndex + 1,
      sequenceAddedCurrentNum,
      sequences
    );
  }
}

function findSubsequences(nums: number[]): number[][] {
  if (nums.length === 1) return [];

  const sequences: number[][] = [];

  for (let i = 0; i < nums.length - 1; ++i) {
    findStartedAt(nums, i, i + 1, [nums[i]], sequences);
  }

  return sequences;
}

export { findSubsequences };
