import { maxSubarraySumCircular } from "../2023_01_02/MaximumSumCircularSubarray";
import { countKDifference } from "../2023_01_02/CountNumberOfPairsWithAbsoluteDifferenceK";
import { maxCoins } from "../2023_01_02/MaximumNumberOfCoinsYouCanGet";
import { countMaxOrSubsets } from "../2023_01_02/CountNumberOfMaximumBitwiseORSubsets";
import { getHappyString } from "../2023_01_02/TheKthLexicographicalStringOfAllHappyStringsOfLengthN";
import { removeStars } from "../2023_01_02/RemovingStarsFromAString";
import { allPossibleFBT } from "../2023_01_02/AllPossibleFullBinaryTrees";
import { longestBeautifulSubstring } from "../2023_01_02/LongestSubstringOfAllVowelsInOrder";
import { TreeNode } from "../common/TreeNode";

describe("2023_01_02 test", () => {
  it("maximum sum circular subarray", () => {
    const nums0 = [1, -2, 3, -2];
    const nums1 = [5, -3, 5];
    const nums2 = [-3, -2, -3];
    const nums3 = [1, 3, -1, -4, 6];
    const nums4 = [-2, -3, -1];

    const ans0 = 3;
    const ans1 = 10;
    const ans2 = -2;
    const ans3 = 10;
    const ans4 = -1;

    const ret0 = maxSubarraySumCircular(nums0);
    const ret1 = maxSubarraySumCircular(nums1);
    const ret2 = maxSubarraySumCircular(nums2);
    const ret3 = maxSubarraySumCircular(nums3);
    const ret4 = maxSubarraySumCircular(nums4);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
    expect(ret4).toEqual(ans4);
  });

  it("count number of pairs with absolute difference K", () => {
    const nums0 = [1, 2, 2, 1];
    const nums1 = [1, 3];
    const nums2 = [3, 2, 1, 5, 4];

    const k0 = 1;
    const k1 = 3;
    const k2 = 2;

    const ret0 = countKDifference(nums0, k0);
    const ret1 = countKDifference(nums1, k1);
    const ret2 = countKDifference(nums2, k2);

    const ans0 = 4;
    const ans1 = 0;
    const ans2 = 3;

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("maximum number of coins you can get", () => {
    const piles0 = [2, 4, 1, 2, 7, 8];
    const piles1 = [2, 4, 5];
    const piles2 = [9, 8, 7, 6, 5, 1, 2, 3, 4];

    const ans0 = 9;
    const ans1 = 4;
    const ans2 = 18;

    const ret0 = maxCoins(piles0);
    const ret1 = maxCoins(piles1);
    const ret2 = maxCoins(piles2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("count number of maximum bitwise or subsets", () => {
    const nums0 = [3, 1];
    const nums1 = [2, 2, 2];
    const nums2 = [3, 2, 1, 5];

    const answer0 = 2;
    const answer1 = 7;
    const answer2 = 6;

    const result0 = countMaxOrSubsets(nums0);
    const result1 = countMaxOrSubsets(nums1);
    const result2 = countMaxOrSubsets(nums2);

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
  });

  it("the kth lexicographical string of all happy strings of length n", () => {
    const n0 = 1;
    const k0 = 3;

    const n1 = 1;
    const k1 = 4;

    const n2 = 3;
    const k2 = 9;

    const answer0 = "c";
    const answer1 = "";
    const answer2 = "cab";

    const result0 = getHappyString(n0, k0);
    const result1 = getHappyString(n1, k1);
    const result2 = getHappyString(n2, k2);

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
  });

  it("removing stars from a string", () => {
    const s0 = "leet**cod*e";
    const s1 = "erase*****";

    const result0 = removeStars(s0);
    const result1 = removeStars(s1);

    const answer0 = "lecoe";
    const answer1 = "";

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
  });

  it("all possible full binary trees", () => {
    const n0 = 7;
    const n1 = 3;

    const result0 = allPossibleFBT(n0);
    const result1 = allPossibleFBT(n1);

    const answer0 = [
      TreeNode.make([0, 0, 0, null, null, 0, 0, null, null, 0, 0]),
      TreeNode.make([0, 0, 0, null, null, 0, 0, 0, 0]),
      TreeNode.make([0, 0, 0, 0, 0, 0, 0]),
      TreeNode.make([0, 0, 0, 0, 0, null, null, null, null, 0, 0]),
      TreeNode.make([0, 0, 0, 0, 0, null, null, 0, 0]),
    ];

    const answer1 = [TreeNode.make([0, 0, 0])];

    const compare0 = TreeNode.isSameListIgnoringOrder(result0, answer0);
    const compare1 = TreeNode.isSameListIgnoringOrder(result1, answer1);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
  });

  it("longest substring of all vowels in order", () => {
    const word0 = "aeiaaioaaaaeiiiiouuuooaauuaeiu";
    const word1 = "aeeeiiiioooauuuaeiou";
    const word2 = "a";
    const word3 = "aeiou";

    const result0 = longestBeautifulSubstring(word0);
    const result1 = longestBeautifulSubstring(word1);
    const result2 = longestBeautifulSubstring(word2);
    const result3 = longestBeautifulSubstring(word3);

    const answer0 = 13;
    const answer1 = 5;
    const answer2 = 0;
    const answer3 = 5;

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
    expect(result3).toEqual(answer3);
  });
});
