import {
  isConatinedIn,
  isTwoDimensionalArraySameIgnoringOrder,
} from "../common/Util";
import { TreeNode } from "../common/TreeNode";
import { minPairSum } from "../2022_08/MinimizeMaximumPairSumInArray";
import { pushDominoes } from "../2022_08/PushDominoes";
import { deepestLeavesSum } from "../2022_08/DeepestLeavesSum";
import { longestCommonSubsequence } from "../2022_08/LongestCommonSubsequence";
import { FindElements } from "../2022_08/FindElementsInAContaminatedBinaryTree";
import { findDifferentBinaryString } from "../2022_08/FindUniqueBinaryString";
import { flatten } from "../2022_08/FlattenBinaryTreeToLinkedList";
import { findSubsequences } from "../2022_08/IncreasingSubsequences";
import { equalPairs } from "../2022_08/EqualRowAndColumnPairs";
import { peakIndexInMountainArray } from "../2022_08/PeakIndexInAMountainArray";
import { maximumUniqueSubarray } from "../2022_08/MaximumErasureValue";
import { maxIceCream } from "../2022_08/MaximumIceCreamBars";
import { numSubarrayBoundedMax } from "../2022_08/NumberOfSubarraysWithBoundedMaximum";
import { isUnivalTree } from "../2022_08/UnivaluedBinaryTree";
import { numSplits } from "../2022_08/NumberOfGoodWaysToSplitAString";
import { getMaximumGold } from "../2022_08/PathWithMaximumGold";
import { maxDistance } from "../2022_08/AsFarFromLandAsPossible";

type TreeArr = (number | null)[];

describe("2022_08 test", () => {
  it("push dominoes", () => {
    const dominoes0 = "RR.L";
    const dominoes1 = ".L.R...LR..L..";

    const ans0 = "RR.L";
    const ans1 = "LL.RR.LLRRLL..";

    const ret0 = pushDominoes(dominoes0);
    const ret1 = pushDominoes(dominoes1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("minimize maximum pair sum in array", () => {
    const nums0 = [3, 5, 2, 3];
    const nums1 = [3, 5, 4, 2, 4, 6];

    const ans0 = 7;
    const ans1 = 8;

    const ret0 = minPairSum(nums0);
    const ret1 = minPairSum(nums1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("deepest leaves sum", () => {
    const arr0 = [1, 2, 3, 4, 5, null, 6, 7, null, null, null, null, 8];
    const arr1 = [6, 7, 8, 2, 7, 1, 3, 9, null, 1, 4, null, null, null, 5];

    const root0 = TreeNode.make(arr0);
    const root1 = TreeNode.make(arr1);

    const ans0 = 15;
    const ans1 = 19;

    const ret0 = deepestLeavesSum(root0);
    const ret1 = deepestLeavesSum(root1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("longest common subsequence", () => {
    const text01 = "abcde";
    const text02 = "ace";

    const text11 = "abc";
    const text12 = "abc";

    const text21 = "abc";
    const text22 = "def";

    const text31 = "ezupkr";
    const text32 = "ubmrapg";

    const text41 = "pmjghexybyrgzczy";
    const text42 = "hafcdqbgncrcbihkd";

    const ans0 = 3;
    const ans1 = 3;
    const ans2 = 0;
    const ans3 = 2;
    const ans4 = 4;

    const ret0 = longestCommonSubsequence(text01, text02);
    const ret1 = longestCommonSubsequence(text11, text12);
    const ret2 = longestCommonSubsequence(text21, text22);
    const ret3 = longestCommonSubsequence(text31, text32);
    const ret4 = longestCommonSubsequence(text41, text42);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
    expect(ret4).toEqual(ans4);
  });

  it("find element in a contaminated binary tree", () => {
    const arr0 = [-1, null, -1];
    const root0 = TreeNode.make(arr0);
    const class0 = new FindElements(root0);

    const ret00 = class0.find(1);
    const ret01 = class0.find(2);

    expect(ret00).toEqual(false);
    expect(ret01).toEqual(true);

    const arr1 = [-1, -1, -1, -1, -1];
    const root1 = TreeNode.make(arr1);
    const class1 = new FindElements(root1);

    const ret10 = class1.find(1);
    const ret11 = class1.find(3);
    const ret12 = class1.find(5);

    expect(ret10).toEqual(true);
    expect(ret11).toEqual(true);
    expect(ret12).toEqual(false);

    const arr2 = [-1, null, -1, -1, null, -1];
    const root2 = TreeNode.make(arr2);
    const class2 = new FindElements(root2);

    const ret20 = class2.find(2);
    const ret21 = class2.find(3);
    const ret22 = class2.find(4);
    const ret23 = class2.find(5);

    expect(ret20).toEqual(true);
    expect(ret21).toEqual(false);
    expect(ret22).toEqual(false);
    expect(ret23).toEqual(true);
  });

  it("find unique binary string", () => {
    const nums0 = ["01", "10"];
    const nums1 = ["00", "01"];
    const nums2 = ["111", "011", "001"];
    const nums3 = ["1"];

    const ret0 = findDifferentBinaryString(nums0);
    const ret1 = findDifferentBinaryString(nums1);
    const ret2 = findDifferentBinaryString(nums2);
    const ret3 = findDifferentBinaryString(nums3);

    const compare0 = isConatinedIn(ret0, ["00", "11"]);
    const compare1 = isConatinedIn(ret1, ["10", "11"]);
    const compare2 = isConatinedIn(ret2, ["000", "010", "100", "101", "110"]);
    const compare3 = isConatinedIn(ret3, ["0"]);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
    expect(compare3).toEqual(true);
  });

  it("flatten binary tree to linked list", () => {
    const nums0: TreeArr = [1, 2, 5, 3, 4, null, 6];
    const nums1: TreeArr = [];
    const nums2: TreeArr = [0];

    const answerNums0: TreeArr = [
      1,
      null,
      2,
      null,
      3,
      null,
      4,
      null,
      5,
      null,
      6,
    ];
    const answerNums1: TreeArr = [];
    const answerNums2: TreeArr = [0];

    const root0 = TreeNode.make(nums0);
    const root1 = TreeNode.make(nums1);
    const root2 = TreeNode.make(nums2);

    const ans0 = TreeNode.make(answerNums0);
    const ans1 = TreeNode.make(answerNums1);
    const ans2 = TreeNode.make(answerNums2);

    flatten(root0);
    flatten(root1);
    flatten(root2);

    const compare0 = TreeNode.isSame(root0, ans0);
    const compare1 = TreeNode.isSame(root1, ans1);
    const compare2 = TreeNode.isSame(root2, ans2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("increasing subsequences", () => {
    const nums0 = [4, 6, 7, 7];
    const nums1 = [4, 4, 3, 2, 1];

    const ans0 = [
      [4, 6],
      [4, 6, 7],
      [4, 6, 7, 7],
      [4, 7],
      [4, 7, 7],
      [6, 7],
      [6, 7, 7],
      [7, 7],
    ];
    const ans1 = [[4, 4]];

    const ret0 = findSubsequences(nums0);
    const ret1 = findSubsequences(nums1);

    const compare0 = isTwoDimensionalArraySameIgnoringOrder(ret0, ans0);
    const compare1 = isTwoDimensionalArraySameIgnoringOrder(ret1, ans1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("peak index in a mountain array", () => {
    const arr0 = [0, 1, 0];
    const arr1 = [0, 2, 1, 0];
    const arr2 = [0, 10, 5, 2];
    const arr3 = [3, 4, 5, 1];

    const ans0 = 1;
    const ans1 = 1;
    const ans2 = 1;
    const ans3 = 2;

    const ret0 = peakIndexInMountainArray(arr0);
    const ret1 = peakIndexInMountainArray(arr1);
    const ret2 = peakIndexInMountainArray(arr2);
    const ret3 = peakIndexInMountainArray(arr3);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });

  it("equal row and column pairs", () => {
    const grid0 = [
      [3, 2, 1],
      [1, 7, 6],
      [2, 7, 7],
    ];
    const grid1 = [
      [3, 1, 2, 2],
      [1, 4, 4, 5],
      [2, 4, 2, 2],
      [2, 4, 2, 2],
    ];

    const ans0 = 1;
    const ans1 = 3;

    const ret0 = equalPairs(grid0);
    const ret1 = equalPairs(grid1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("maximum erasure value", () => {
    const nums0 = [4, 2, 4, 5, 6];
    const nums1 = [5, 2, 1, 2, 5, 2, 1, 2, 5];

    const ans0 = 17;
    const ans1 = 8;

    const ret0 = maximumUniqueSubarray(nums0);
    const ret1 = maximumUniqueSubarray(nums1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("maximum ice cream bars", () => {
    const costs0 = [1, 3, 2, 4, 1];
    const costs1 = [10, 6, 8, 7, 7, 8];
    const costs2 = [1, 6, 3, 1, 2, 5];

    const coins0 = 7;
    const coins1 = 5;
    const coins2 = 20;

    const ans0 = 4;
    const ans1 = 0;
    const ans2 = 6;

    const ret0 = maxIceCream(costs0, coins0);
    const ret1 = maxIceCream(costs1, coins1);
    const ret2 = maxIceCream(costs2, coins2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("number of subarrays with bounded maximum", () => {
    const nums0 = [2, 1, 4, 3];
    const left0 = 2;
    const right0 = 3;

    const nums1 = [2, 9, 2, 5, 6];
    const left1 = 2;
    const right1 = 8;

    const nums2 = [16, 69, 88, 85, 79, 87, 37, 33, 39, 34];
    const left2 = 55;
    const right2 = 57;

    const ret0 = numSubarrayBoundedMax(nums0, left0, right0);
    const ret1 = numSubarrayBoundedMax(nums1, left1, right1);
    const ret2 = numSubarrayBoundedMax(nums2, left2, right2);

    const ans0 = 3;
    const ans1 = 7;
    const ans2 = 0;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("univalued binary tree", () => {
    const arr0 = [1, 1, 1, 1, 1, null, 1];
    const arr1 = [2, 2, 2, 5, 2];

    const root0 = TreeNode.make(arr0);
    const root1 = TreeNode.make(arr1);

    const ans0 = true;
    const ans1 = false;

    const ret0 = isUnivalTree(root0);
    const ret1 = isUnivalTree(root1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("number of good ways to split a string", () => {
    const s0 = "aacaba";
    const s1 = "abcd";

    const ans0 = 2;
    const ans1 = 1;

    const ret0 = numSplits(s0);
    const ret1 = numSplits(s1);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
  });

  it("path with maximum gold", () => {
    const grid0 = [
      [0, 6, 0],
      [5, 8, 7],
      [0, 9, 0],
    ];

    const grid1 = [
      [1, 0, 7],
      [2, 0, 6],
      [3, 4, 5],
      [0, 3, 0],
      [9, 0, 20],
    ];

    const grid2 = [
      [0, 0, 19, 5, 8],
      [11, 20, 14, 1, 0],
      [0, 0, 1, 1, 1],
      [0, 2, 0, 2, 0],
    ];

    const ans0 = 24;
    const ans1 = 28;
    const ans2 = 77;

    const ret0 = getMaximumGold(grid0);
    const ret1 = getMaximumGold(grid1);
    const ret2 = getMaximumGold(grid2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("as far from land as possible", () => {
    const grid0 = [
      [1, 0, 1],
      [0, 0, 0],
      [1, 0, 1],
    ];
    const grid1 = [
      [1, 0, 0],
      [0, 0, 0],
      [0, 0, 0],
    ];
    const grid2 = [
      [0, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 0, 0, 0],
      [0, 0, 0, 0],
    ];
    const grid3 = [
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
      [1, 1, 1, 1, 1],
    ];

    const ans0 = 2;
    const ans1 = 4;
    const ans2 = -1;
    const ans3 = -1;

    const ret0 = maxDistance(grid0);
    const ret1 = maxDistance(grid1);
    const ret2 = maxDistance(grid2);
    const ret3 = maxDistance(grid3);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });
});
