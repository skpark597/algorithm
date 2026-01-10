import { closedIsland } from "../2022_09/NumberOfClosedIslands";
import { possibleBipartition } from "../2022_09/PossibleBipartition";
import { minimumDeletions } from "../2022_09/MinimumDeletionsToMakeStringBalanced";

describe("2022_09 test", () => {
  it("push dominoes", () => {
    const grid0 = [
      [1, 1, 1, 1, 1, 1, 1, 0],
      [1, 0, 0, 0, 0, 1, 1, 0],
      [1, 0, 1, 0, 1, 1, 1, 0],
      [1, 0, 0, 0, 0, 1, 0, 1],
      [1, 1, 1, 1, 1, 1, 1, 0],
    ];

    const grid1 = [
      [0, 0, 1, 0, 0],
      [0, 1, 0, 1, 0],
      [0, 1, 1, 1, 0],
    ];

    const grid2 = [
      [1, 1, 1, 1, 1, 1, 1],
      [1, 0, 0, 0, 0, 0, 1],
      [1, 0, 1, 1, 1, 0, 1],
      [1, 0, 1, 0, 1, 0, 1],
      [1, 0, 1, 1, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 1],
    ];

    const grid3 = [
      [0, 0, 1, 1, 0, 1, 0, 0, 1, 0],
      [1, 1, 0, 1, 1, 0, 1, 1, 1, 0],
      [1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
      [0, 1, 1, 0, 0, 0, 0, 1, 0, 1],
      [0, 0, 0, 0, 0, 0, 1, 1, 1, 0],
      [0, 1, 0, 1, 0, 1, 0, 1, 1, 1],
      [1, 0, 1, 0, 1, 1, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 0, 0, 0, 0],
      [1, 1, 1, 0, 0, 1, 0, 1, 0, 1],
      [1, 1, 1, 0, 1, 1, 0, 1, 1, 0],
    ];

    const ans0 = 2;
    const ans1 = 1;
    const ans2 = 2;
    const ans3 = 5;

    const ret0 = closedIsland(grid0);
    const ret1 = closedIsland(grid1);
    const ret2 = closedIsland(grid2);
    const ret3 = closedIsland(grid3);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
    expect(ret3).toEqual(ans3);
  });

  it("possible bipartition", () => {
    const n0 = 4;
    const n1 = 3;
    const n2 = 5;

    const dislikes0 = [
      [1, 2],
      [1, 3],
      [2, 4],
    ];
    const dislikes1 = [
      [1, 2],
      [1, 3],
      [2, 3],
    ];
    const dislikes2 = [
      [1, 2],
      [2, 3],
      [3, 4],
      [4, 5],
      [1, 5],
    ];

    const ans0 = true;
    const ans1 = false;
    const ans2 = false;

    const ret0 = possibleBipartition(n0, dislikes0);
    const ret1 = possibleBipartition(n1, dislikes1);
    const ret2 = possibleBipartition(n2, dislikes2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });

  it("minimum deletion to make string balanced", () => {
    const s0 = "aababbab";
    const s1 = "bbaaaaabb";
    const s2 = "baababbaabbaaabaabbabbbabaaaaaabaabababaaababbb";

    const ans0 = 2;
    const ans1 = 2;
    const ans2 = 18;

    const ret0 = minimumDeletions(s0);
    const ret1 = minimumDeletions(s1);
    const ret2 = minimumDeletions(s2);

    expect(ret0).toEqual(ans0);
    expect(ret1).toEqual(ans1);
    expect(ret2).toEqual(ans2);
  });
});
