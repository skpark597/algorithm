import { minimumSwap } from "../2022_06/MinimumSwapsToMakeStringsEqual";
import { numOfSubarrays } from "../2022_06/NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold";
import { kWeakestRows } from "../2022_06/TheKWeakestRowsInAMatrix";
import {
  isArraySame,
  isArraySameIgnoringOrder,
  isTwoDimensionalArraySame,
} from "../common/Util";
import { ListNode } from "../common/ListNode";
import { splitListToParts } from "../2022_06/SplitLinkedListInParts";
import { twoSum } from "../2022_06/TwoSum";
import { detectCycle } from "../2022_06/LinkedListCycleII";
import { invertTree } from "../2022_06/InvertBinaryTree";
import { TreeNode } from "../common/TreeNode";
import { minimumSize } from "../2022_06/MinimumLimitOfBallsInABag";
import { canPartitionKSubsets } from "../2022_06/PartitionToKEqualSumSubsets";
import { divideArray } from "../2022_06/DivideArrayIntoEqualPairs";
import { addDigits } from "../2022_06/AddDigits";
import { binaryTreePaths } from "../2022_06/BinaryTreePaths";
import { generateMatrix } from "../2022_06/SpiralMatrixII";

describe("2022_06 test", () => {
  it("minimum swaps to make strings equal", () => {
    const s00 = "xx";
    const s01 = "yy";

    const s10 = "xy";
    const s11 = "yx";

    const s20 = "xx";
    const s21 = "xy";

    const s30 = "xxyy";
    const s31 = "xyxy";

    const s40 = "xxyyxyxyxx";
    const s41 = "xyyxyxxxyx";

    const s50 = "xyyyyx";
    const s51 = "xxxxyy";

    const s60 = "xxxxyyyy";
    const s61 = "yyyyxyyx";

    const ret0 = minimumSwap(s00, s01);
    const ret1 = minimumSwap(s10, s11);
    const ret2 = minimumSwap(s20, s21);
    const ret3 = minimumSwap(s30, s31);
    const ret4 = minimumSwap(s40, s41);
    const ret5 = minimumSwap(s50, s51);
    const ret6 = minimumSwap(s60, s61);

    expect(ret0).toEqual(1);
    expect(ret1).toEqual(2);
    expect(ret2).toEqual(-1);
    expect(ret3).toEqual(2);
    expect(ret4).toEqual(4);
    expect(ret5).toEqual(3);
    expect(ret6).toEqual(3);
  });

  it("number of sub array of size k and average greater than or equal to threshold", () => {
    const arr0 = [2, 2, 2, 2, 5, 5, 5, 8];
    const k0 = 3;
    const threshold0 = 4;

    const arr1 = [11, 13, 17, 23, 29, 31, 7, 5, 2, 3];
    const k1 = 3;
    const threshold1 = 5;

    const ret0 = numOfSubarrays(arr0, k0, threshold0);
    const ret1 = numOfSubarrays(arr1, k1, threshold1);

    expect(ret0).toEqual(3);
    expect(ret1).toEqual(6);
  });

  it("k weakest rows", () => {
    const mat0 = [
      [1, 1, 0, 0, 0],
      [1, 1, 1, 1, 0],
      [1, 0, 0, 0, 0],
      [1, 1, 0, 0, 0],
      [1, 1, 1, 1, 1],
    ];
    const k0 = 3;

    const mat1 = [
      [1, 0, 0, 0],
      [1, 1, 1, 1],
      [1, 0, 0, 0],
      [1, 0, 0, 0],
    ];
    const k1 = 2;

    const mat2 = [
      [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0],
      [1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0],
      [1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
    ];
    const k2 = 1;

    const ret0 = kWeakestRows(mat0, k0);
    const ret1 = kWeakestRows(mat1, k1);
    const ret2 = kWeakestRows(mat2, k2);

    const ans0 = [2, 0, 3];
    const ans1 = [0, 2];
    const ans2 = [4];

    const compare0 = isArraySame(ret0, ans0);
    const compare1 = isArraySame(ret1, ans1);
    const compare2 = isArraySame(ret2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("split list to parts", () => {
    const arr0 = [1, 2, 3];
    const arr00 = [1];
    const arr01 = [2];
    const arr02 = [3];
    const arr03: number[] = [];
    const arr04: number[] = [];

    const arr1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const arr10 = [1, 2, 3, 4];
    const arr11 = [5, 6, 7];
    const arr12 = [8, 9, 10];

    const k0 = 5;
    const k1 = 3;

    const list0 = ListNode.makeList(arr0);
    const list00 = ListNode.makeList(arr00);
    const list01 = ListNode.makeList(arr01);
    const list02 = ListNode.makeList(arr02);
    const list03 = ListNode.makeList(arr03);
    const list04 = ListNode.makeList(arr04);

    const list1 = ListNode.makeList(arr1);
    const list10 = ListNode.makeList(arr10);
    const list11 = ListNode.makeList(arr11);
    const list12 = ListNode.makeList(arr12);

    const ret0 = splitListToParts(list0, k0);
    const ret1 = splitListToParts(list1, k1);

    const compare00 = ListNode.isSameList(list00, ret0[0]);
    const compare01 = ListNode.isSameList(list01, ret0[1]);
    const compare02 = ListNode.isSameList(list02, ret0[2]);
    const compare03 = ListNode.isSameList(list03, ret0[3]);
    const compare04 = ListNode.isSameList(list04, ret0[4]);

    const compare10 = ListNode.isSameList(list10, ret1[0]);
    const compare11 = ListNode.isSameList(list11, ret1[1]);
    const compare12 = ListNode.isSameList(list12, ret1[2]);

    expect(compare00).toEqual(true);
    expect(compare01).toEqual(true);
    expect(compare02).toEqual(true);
    expect(compare03).toEqual(true);
    expect(compare04).toEqual(true);
    expect(compare10).toEqual(true);
    expect(compare11).toEqual(true);
    expect(compare12).toEqual(true);
  });

  it("two sum", () => {
    const nums0 = [2, 7, 11, 15];
    const nums1 = [3, 2, 4];
    const nums2 = [3, 3];

    const target0 = 9;
    const target1 = 6;
    const target2 = 6;

    const ans0 = [0, 1];
    const ans1 = [1, 2];
    const ans2 = [0, 1];

    const ret0 = twoSum(nums0, target0);
    const ret1 = twoSum(nums1, target1);
    const ret2 = twoSum(nums2, target2);

    const compare0 = isArraySameIgnoringOrder(ret0, ans0);
    const compare1 = isArraySameIgnoringOrder(ret1, ans1);
    const compare2 = isArraySameIgnoringOrder(ret2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("detect cycle", () => {
    const arr0: [number[], number] = [[3, 2, 0, -4], 1];
    const arr1: [number[], number] = [[1, 2], 0];
    const arr2: [number[], number] = [[1], -1];
    const arr3: [number[], number] = [[2, 0, -4], 0];
    const arr4: [number[], number] = [[1, 2], 0];

    const list0 = ListNode.makeCircularList(arr0);
    const list1 = ListNode.makeCircularList(arr1);
    const list2 = ListNode.makeCircularList(arr2);
    const ans0 = ListNode.makeCircularList(arr3);
    const ans1 = ListNode.makeCircularList(arr4);
    const ans2 = null;

    const ret0 = detectCycle(list0);
    const ret1 = detectCycle(list1);
    const ret2 = detectCycle(list2);

    const compare0 = ListNode.isSameCircularList(ret0, ans0);
    const compare1 = ListNode.isSameCircularList(ret1, ans1);
    const compare2 = ListNode.isSameCircularList(ret2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("invert binary tree", () => {
    const arr0 = [4, 2, 7, 1, 3, 6, 9];
    const arr1 = [2, 1, 3];
    const arr2: number[] = [];
    const arr3 = [4, 7, 2, 9, 6, 3, 1];
    const arr4 = [2, 3, 1];
    const arr5: number[] = [];

    const tree0 = TreeNode.make(arr0);
    const tree1 = TreeNode.make(arr1);
    const tree2 = TreeNode.make(arr2);

    const ans0 = TreeNode.make(arr3);
    const ans1 = TreeNode.make(arr4);
    const ans2 = TreeNode.make(arr5);

    const ret0 = invertTree(tree0);
    const ret1 = invertTree(tree1);
    const ret2 = invertTree(tree2);

    const compare0 = TreeNode.isSame(ret0, ans0);
    const compare1 = TreeNode.isSame(ret1, ans1);
    const compare2 = TreeNode.isSame(ret2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("minimum limit of balls in a bag", () => {
    const nums0 = [9];
    const maxOperations0 = 2;

    const nums1 = [2, 4, 8, 2];
    const maxOperations1 = 4;

    const nums2 = [7, 17];
    const maxOperations2 = 2;

    const ret0 = minimumSize(nums0, maxOperations0);
    const ret1 = minimumSize(nums1, maxOperations1);
    const ret2 = minimumSize(nums2, maxOperations2);

    const ans0 = 3;
    const ans1 = 2;
    const ans2 = 7;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("partition to k equal sum subsets", () => {
    const nums0 = [4, 3, 2, 3, 5, 2, 1];
    const k0 = 4;

    const nums1 = [1, 2, 3, 4];
    const k1 = 3;

    const nums2 = [2, 2, 2, 2, 3, 4, 5];
    const k2 = 4;

    const ret0 = canPartitionKSubsets(nums0, k0);
    const ret1 = canPartitionKSubsets(nums1, k1);
    const ret2 = canPartitionKSubsets(nums2, k2);

    const ans0 = true;
    const ans1 = false;
    const ans2 = false;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("divide array into equal pairs", () => {
    const nums0 = [3, 2, 3, 2, 2, 2];
    const nums1 = [1, 2, 3, 4];

    const ans0 = true;
    const ans1 = false;

    const ret0 = divideArray(nums0);
    const ret1 = divideArray(nums1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("add digits", () => {
    const num0 = 38;
    const num1 = 0;

    const ans0 = 2;
    const ans1 = 0;

    const ret0 = addDigits(num0);
    const ret1 = addDigits(num1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("binary tree paths", () => {
    const arr0 = [1, 2, 3, null, 5];
    const arr1 = [1];

    const root0 = TreeNode.make(arr0);
    const root1 = TreeNode.make(arr1);

    const ans0 = ["1->2->5", "1->3"];
    const ans1 = ["1"];

    const ret0 = binaryTreePaths(root0);
    const ret1 = binaryTreePaths(root1);

    const compare0 = isArraySame(ret0, ans0);
    const compare1 = isArraySame(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("spiral matrix II", () => {
    const n0 = 3;
    const n1 = 1;

    const ans0 = [
      [1, 2, 3],
      [8, 9, 4],
      [7, 6, 5],
    ];
    const ans1 = [[1]];

    const ret0 = generateMatrix(n0);
    const ret1 = generateMatrix(n1);

    const compare0 = isTwoDimensionalArraySame(ret0, ans0);
    const compare1 = isTwoDimensionalArraySame(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });
});
