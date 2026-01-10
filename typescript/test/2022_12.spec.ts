import { balanceBST } from "../2022_12/BalanceABinarySearchTree";
import { customSortString } from "../2022_12/CustomSortString";
import { TreeNode } from "../common/TreeNode";

describe("2022_12 test", () => {
  it("balance a binary search tree", () => {
    const root0 = TreeNode.make([1, null, 2, null, 3, null, 4, null, null]);
    const root1 = TreeNode.make([2, 1, 3]);
    const root2 = TreeNode.make([14, 9, 16, 2, 13]);

    const answer0 = TreeNode.make([2, 1, 3, null, null, null, 4]);
    const answer1 = TreeNode.make([2, 1, 3]);
    const answer2 = TreeNode.make([13, 2, 14, null, 9, null, 16]);

    const result0 = balanceBST(root0);
    const result1 = balanceBST(root1);
    const result2 = balanceBST(root2);

    const compare0 = TreeNode.isSame(result0, answer0);
    const compare1 = TreeNode.isSame(result1, answer1);
    const compare2 = TreeNode.isSame(result2, answer2);

    expect(compare0).toEqual(true);
    expect(compare1).toEqual(true);
    expect(compare2).toEqual(true);
  });

  it("custom sort string", () => {
    const order0 = "cba";
    const order1 = "cbafg";
    const order2 = "kqep";

    const s0 = "abcd";
    const s1 = "abcd";
    const s2 = "pekeq";

    const result0 = customSortString(order0, s0);
    const result1 = customSortString(order1, s1);
    const result2 = customSortString(order2, s2);

    const answer0 = "cbad";
    const answer1 = "cbad";
    const answer2 = "kqeep";

    expect(result0).toEqual(answer0);
    expect(result1).toEqual(answer1);
    expect(result2).toEqual(answer2);
  });
});
