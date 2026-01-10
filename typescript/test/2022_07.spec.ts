import { ListNode } from "../common/ListNode";
import { pairSum } from "../2022_07/MaximumTwinSumOfALinkedList";
import { maxScoreSightseeingPair } from "../2022_07/BestSightseeingPair";
import { selfDividingNumbers } from "../2022_07/SelfDividingNumbers";
import { isIsomorphic } from "../2022_07/IsomorphicStrings";
import { isArraySame } from "../common/Util";
import { TreeNode } from "../common/TreeNode";
import { rangeSumBST } from "../2022_07/RangeSumOfBST";
import { findLHS } from "../2022_07/LongestHarmoniousSubsequence";
import { findMaxAverage } from "../2022_07/MaximumAverageSubarrayI";
import { maximumSum } from "../2022_07/MaximumSubarraySumWithOneDeletion";
import { findMaxConsecutiveOnes } from "../2022_07/MaxConsecutiveOnes";
import { minMutation } from "../2022_07/MinimumGeneticMutation";

describe("2022_07 test", () => {
  it("maximum twin sum of a linked list", () => {
    const arr0 = [5, 4, 2, 1];
    const arr1 = [4, 2, 2, 3];
    const arr2 = [1, 100000];

    const list0 = ListNode.makeList(arr0);
    const list1 = ListNode.makeList(arr1);
    const list2 = ListNode.makeList(arr2);

    const ret0 = pairSum(list0);
    const ret1 = pairSum(list1);
    const ret2 = pairSum(list2);

    const ans0 = 6;
    const ans1 = 7;
    const ans2 = 100001;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("best sightseeing pair", () => {
    const values0 = [8, 1, 5, 2, 6];
    const values1 = [1, 2];

    const ans0 = 11;
    const ans1 = 2;

    const ret0 = maxScoreSightseeingPair(values0);
    const ret1 = maxScoreSightseeingPair(values1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("self dividing number", () => {
    const left0 = 1;
    const right0 = 22;

    const left1 = 47;
    const right1 = 85;

    const ret0 = selfDividingNumbers(left0, right0);
    const ret1 = selfDividingNumbers(left1, right1);

    const ans0 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22];
    const ans1 = [48, 55, 66, 77];

    const compare0 = isArraySame(ret0, ans0);
    const compare1 = isArraySame(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("isomorphic strings", () => {
    const s0 = "egg";
    const t0 = "add";

    const s1 = "foo";
    const t1 = "bar";

    const s2 = "paper";
    const t2 = "title";

    const s3 = "badc";
    const t3 = "baba";

    const ret0 = isIsomorphic(s0, t0);
    const ret1 = isIsomorphic(s1, t1);
    const ret2 = isIsomorphic(s2, t2);
    const ret3 = isIsomorphic(s3, t3);

    const ans0 = true;
    const ans1 = false;
    const ans2 = true;
    const ans3 = false;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });

  it("range sum of BST", () => {
    const arr0 = [10, 5, 15, 3, 7, null, 18];
    const low0 = 7;
    const high0 = 15;

    const arr1 = [10, 5, 15, 3, 7, 13, 18, 1, null, 6];
    const low1 = 6;
    const high1 = 10;

    const root0 = TreeNode.make(arr0);
    const root1 = TreeNode.make(arr1);

    const ans0 = 32;
    const ans1 = 23;

    const ret0 = rangeSumBST(root0, low0, high0);
    const ret1 = rangeSumBST(root1, low1, high1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("longest harmonious subsequence", () => {
    const nums0 = [1, 3, 2, 2, 5, 2, 3, 7];
    const nums1 = [1, 2, 3, 4];
    const nums2 = [1, 1, 1, 1];

    const ans0 = 5;
    const ans1 = 2;
    const ans2 = 0;

    const ret0 = findLHS(nums0);
    const ret1 = findLHS(nums1);
    const ret2 = findLHS(nums2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("maximum average subarray I", () => {
    const nums0 = [1, 12, -5, -6, 50, 3];
    const k0 = 4;

    const nums1 = [5];
    const k1 = 1;

    const nums2 = [0, 4, 0, 3, 2];
    const k2 = 1;

    const nums3 = [9, 7, 3, 5, 6, 2, 0, 8, 1, 9];
    const k3 = 6;

    const ret0 = findMaxAverage(nums0, k0);
    const ret1 = findMaxAverage(nums1, k1);
    const ret2 = findMaxAverage(nums2, k2);
    const ret3 = findMaxAverage(nums3, k3);

    const ans0 = 12.75;
    const ans1 = 5;
    const ans2 = 4;
    const ans3 = 5.333333333333333;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });

  it("maximum subarray sum with one deletion", () => {
    const arr0 = [1, -2, 0, 3];
    const arr1 = [1, -2, -2, 3];
    const arr2 = [-1, -1, -1, -1];

    const ans0 = 4;
    const ans1 = 3;
    const ans2 = -1;

    const ret0 = maximumSum(arr0);
    const ret1 = maximumSum(arr1);
    const ret2 = maximumSum(arr2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("max consecutive ones", () => {
    const nums0 = [1, 1, 0, 1, 1, 1];
    const nums1 = [1, 0, 1, 1, 0, 1];

    const ans0 = 3;
    const ans1 = 2;

    const ret0 = findMaxConsecutiveOnes(nums0);
    const ret1 = findMaxConsecutiveOnes(nums1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("minimum genetic mutation", () => {
    const start0 = "AACCGGTT";
    const end0 = "AACCGGTA";
    const bank0 = ["AACCGGTA"];

    const start1 = "AACCGGTT";
    const end1 = "AAACGGTA";
    const bank1 = ["AACCGGTA", "AACCGCTA", "AAACGGTA"];

    const start2 = "AAAAACCC";
    const end2 = "AACCCCCC";
    const bank2 = ["AAAACCCC", "AAACCCCC", "AACCCCCC"];

    const ret0 = minMutation(start0, end0, bank0);
    const ret1 = minMutation(start1, end1, bank1);
    const ret2 = minMutation(start2, end2, bank2);

    const ans0 = 1;
    const ans1 = 2;
    const ans2 = 3;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });
});
