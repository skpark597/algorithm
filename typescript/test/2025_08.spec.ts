import { smallestCommonElement } from "../2025_08/FindSmallestCommonElementInAllRows";
import { minCost } from "../2025_08/PaintHouse";
import { verticalOrder } from "../2025_08/BinaryTreeVerticalOrderTraversal";
import { pathSum } from "../2025_08/PathSumIII";
import { TreeNode } from "../common/TreeNode";
import { isTwoDimensionalArraySame } from "../common/Util";
import { FileSystem } from "../2025_08/DesignFileSystem";

describe("2025_08 test", () => {
  it("Find Smallest Common Element in All Rows", () => {
    const mat0 = [
      [1, 2, 3, 4, 5],
      [2, 4, 5, 8, 10],
      [3, 5, 7, 9, 11],
      [1, 3, 5, 7, 9],
    ];
    const mat1 = [
      [1, 2, 3],
      [2, 3, 4],
      [2, 3, 5],
    ];

    const ret0 = smallestCommonElement(mat0);
    const ret1 = smallestCommonElement(mat1);

    expect(ret0).toEqual(5);
    expect(ret1).toEqual(2);
  });

  it("Paint House", () => {
    const costs0 = [
      [17, 2, 17],
      [16, 16, 5],
      [14, 3, 19],
    ];
    const costs1 = [[7, 6, 2]];

    const ret0 = minCost(costs0);
    const ret1 = minCost(costs1);

    expect(ret0).toEqual(10);
    expect(ret1).toEqual(2);
  });

  it("Binary Tree Vertical Order Traversal", () => {
    const root0 = TreeNode.make([3, 9, 20, null, null, 15, 7]);
    const root1 = TreeNode.make([3, 9, 8, 4, 0, 1, 7]);
    const root2 = TreeNode.make([1, 2, 3, 4, 10, 9, 11, null, 5, null, null, null, null, null, null, null, 6]);

    const ret0 = verticalOrder(root0);
    const ret1 = verticalOrder(root1);
    const ret2 = verticalOrder(root2);

    const ans0 = [[9], [3, 15], [20], [7]];
    const ans1 = [[4], [9], [3, 0, 1], [8], [7]];
    const ans2 = [[4], [2, 5], [1, 10, 9, 6], [3], [11]];

    expect(isTwoDimensionalArraySame(ret0, ans0)).toEqual(true);
    expect(isTwoDimensionalArraySame(ret1, ans1)).toEqual(true);
    expect(isTwoDimensionalArraySame(ret2, ans2)).toEqual(true);
  });

  it("Path Sum III", () => {
    const root0 = TreeNode.make([10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]);
    const targetSum0 = 8;

    const root1 = TreeNode.make([5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]);
    const targetSum1 = 22;

    const root2 = TreeNode.make([0, 1, 1]);
    const targetSum2 = 1;

    const ret0 = pathSum(root0, targetSum0);
    const ret1 = pathSum(root1, targetSum1);
    const ret2 = pathSum(root2, targetSum2);

    expect(ret0).toEqual(3);
    expect(ret1).toEqual(3);
    expect(ret2).toEqual(4);
  });

  it("File System", () => {
    const system0 = new FileSystem();

    const ret0 = system0.createPath("/a", 1);
    const ret1 = system0.get("/a");

    const system1 = new FileSystem();
    const ret2 = system1.createPath("/leet", 1);
    const ret3 = system1.createPath("/leet/code", 2);
    const ret4 = system1.get("/leet/code");
    const ret5 = system1.createPath("/c/d", 1);
    const ret6 = system1.get("/c");

    const system2 = new FileSystem();
    const ret7 = system2.createPath("/a", 1);
    const ret8 = system2.createPath("/a", 2);
    const ret9 = system2.get("/a");

    expect(ret0).toEqual(true);
    expect(ret1).toEqual(1);
    expect(ret2).toEqual(true);
    expect(ret3).toEqual(true);
    expect(ret4).toEqual(2);
    expect(ret5).toEqual(false);
    expect(ret6).toEqual(-1);
    expect(ret7).toEqual(true);
    expect(ret8).toEqual(false);
    expect(ret9).toEqual(1);
  });
});
