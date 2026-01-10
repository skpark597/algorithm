import { minDifference } from "../2025_06/MinimumDifferenceBetweenLargestAndSmallestValueInThreeMoves";
import { maximumGain } from "../2025_06/MaximumScoreFromRemovingSubstrings";
import { numDistinctIslands } from "../2025_06/NumberOfDistinctIslands";
import { expand } from "../2025_06/BraceExpansion";

describe("2025_06 test", () => {
  it("Minimum Difference Between Largest and Smallest Value in Three Moves", () => {
    const nums0 = [5, 3, 2, 4];
    const nums1 = [1, 5, 0, 10, 14];
    const nums2 = [3, 100, 20];

    const res0 = minDifference(nums0);
    const res1 = minDifference(nums1);
    const res2 = minDifference(nums2);

    expect(res0).toEqual(0);
    expect(res1).toEqual(1);
    expect(res2).toEqual(0);
  });

  it("Maximum Score From Removing Substrings", () => {
    const s0 = "cdbcbbaaabab";
    const x0 = 4;
    const y0 = 5;

    const s1 = "aabbaaxybbaabb";
    const x1 = 5;
    const y1 = 4;

    const res0 = maximumGain(s0, x0, y0);
    const res1 = maximumGain(s1, x1, y1);

    expect(res0).toEqual(19);
    expect(res1).toEqual(20);
  });

  it("Number Of Distinct Islands", () => {
    const grid0 = [
      [1, 1, 0, 0, 0],
      [1, 1, 0, 0, 0],
      [0, 0, 0, 1, 1],
      [0, 0, 0, 1, 1],
    ];
    const grid1 = [
      [1, 1, 0, 1, 1],
      [1, 0, 0, 0, 0],
      [0, 0, 0, 0, 1],
      [1, 1, 0, 1, 1],
    ];

    // prettier-ignore
    const grid2 = [
      [0,0,1,0,1,0,1,1,1,0,0,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,1,1,1,1,0],
      [0,0,1,0,0,1,1,1,0,0,1,0,1,0,0,1,1,0,0,1,0,0,0,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,0],
      [0,1,0,1,0,1,1,1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,1,0,1,1,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0],
      [1,0,1,0,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,1,1]
    ]

    const res0 = numDistinctIslands(grid0);
    const res1 = numDistinctIslands(grid1);
    const res2 = numDistinctIslands(grid2);

    expect(res0).toEqual(1);
    expect(res1).toEqual(3);
    expect(res2).toEqual(15);
  });
});

it("Brace Expansion", () => {
  const s0 = "{a,b}c{d,e}f";
  const s1 = "abcd";

  const res0 = expand(s0);
  const res1 = expand(s1);

  const ans0 = ["acdf", "acef", "bcdf", "bcef"];
  const ans1 = ["abcd"];

  expect(res0).toEqual(ans0);
  expect(res1).toEqual(ans1);
});
