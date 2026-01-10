import { TreeNode } from "../common/TreeNode";
import { generateTrees } from "../2022_10/UniqueBinarySearchTreesII";
import { subArrayRangesI } from "../2022_10/SumOfSubarrayRangesI";
import { subArrayRangesII } from "../2022_10/SumOfSubarrayRangesII";
import { sumSubarrayMins } from "../2022_10/SumOfSubarrayMinimums";
import { smallestNumber } from "../2022_10/ConstructSmallestNumberFromDIString";
import { minSteps } from "../2022_10/MinimumNumberOfStepsToMakeTwoStringsAnagramII";
import { waysToMakeFair } from "../2022_10/WaysToMakeAFairArray";

describe("2022_10 test", () => {
  it("unique binary search tree II", () => {
    const tree00 = TreeNode.make([1, null, 2, null, 3]);
    const tree01 = TreeNode.make([1, null, 3, 2]);
    const tree02 = TreeNode.make([2, 1, 3]);
    const tree03 = TreeNode.make([3, 1, null, null, 2]);
    const tree04 = TreeNode.make([3, 2, null, 1]);
    const tree10 = TreeNode.make([1]);

    const n0 = 3;
    const n1 = 1;

    const ans0 = [tree00, tree01, tree02, tree03, tree04];
    const ans1 = [tree10];

    const ret0 = generateTrees(n0);
    const ret1 = generateTrees(n1);

    const compare0 = TreeNode.isSameListIgnoringOrder(ans0, ret0);
    const compare1 = TreeNode.isSameListIgnoringOrder(ans1, ret1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("sum of subarray ranges I", () => {
    const nums0 = [1, 2, 3];
    const nums1 = [1, 3, 3];
    const nums2 = [4, -2, -3, 4, 1];

    const ans0 = 4;
    const ans1 = 4;
    const ans2 = 59;

    const ret0 = subArrayRangesI(nums0);
    const ret1 = subArrayRangesI(nums1);
    const ret2 = subArrayRangesI(nums2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("sum of subarray ranges II", () => {
    const nums0 = [1, 2, 3];
    const nums1 = [1, 3, 3];
    const nums2 = [4, -2, -3, 4, 1];

    const ans0 = 4;
    const ans1 = 4;
    const ans2 = 59;

    const ret0 = subArrayRangesII(nums0);
    const ret1 = subArrayRangesII(nums1);
    const ret2 = subArrayRangesII(nums2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("sum of subarray minimums", () => {
    const arr0 = [3, 1, 2, 4];
    const arr1 = [11, 81, 94, 43, 3];

    const ans0 = 17;
    const ans1 = 444;

    const ret0 = sumSubarrayMins(arr0);
    const ret1 = sumSubarrayMins(arr1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("construct smallest number from di string", () => {
    const pattern0 = "IIIDIDDD";
    const pattern1 = "DDD";

    const ans0 = "123549876";
    const ans1 = "4321";

    const ret0 = smallestNumber(pattern0);
    const ret1 = smallestNumber(pattern1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("minimum number of steps to make two strings anagram II", () => {
    const s0 = "leetcode";
    const t0 = "coats";

    const s1 = "night";
    const t1 = "thing";

    const ans0 = 7;
    const ans1 = 0;

    const ret0 = minSteps(s0, t0);
    const ret1 = minSteps(s1, t1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("ways to make a fair array", () => {
    const nums0 = [2, 1, 6, 4];
    const nums1 = [1, 1, 1];
    const nums2 = [1, 2, 3];
    const nums3 = [4, 1, 1, 2, 5, 1, 5, 4];

    const ans0 = 1;
    const ans1 = 3;
    const ans2 = 0;
    const ans3 = 2;

    const ret0 = waysToMakeFair(nums0);
    const ret1 = waysToMakeFair(nums1);
    const ret2 = waysToMakeFair(nums2);
    const ret3 = waysToMakeFair(nums3);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });
});
