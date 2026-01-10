/** 894. All Possible Full Binary Trees */
/** Given an integer n, return a list of all possible full binary trees with n nodes.
 *  Each node of each tree in the answer must have Node.val == 0.
 *  Each element of the answer is the root node of one possible tree.
 *  You may return the final list of trees in any order.
 *
 *  A full binary tree is a binary tree where each node has exactly 0 or 2 children.
 *
 *  Example 1:
 *  Input: n = 7
 *  Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 *
 *  Example 2:
 *  Input: n = 3
 *  Output: [[0,0,0]]
 *
 *  Constraints:
 *  1 <= n <= 20 */

import { TreeNode } from "../common/TreeNode";

function allPossibleFBT(n: number): (TreeNode | null)[] {
  const fullBinaryTrees: TreeNode[][] = new Array(21).fill(null).map(() => []);
  fullBinaryTrees[1].push(new TreeNode(0));

  for (let i = 2; i <= n; ++i) {
    for (let j = 1; j < i - 1; ++j) {
      const lefts = fullBinaryTrees[j];
      const rights = fullBinaryTrees[i - 1 - j];

      if (lefts.length === 0 || rights.length === 0) continue;

      for (const left of lefts) {
        for (const right of rights) {
          const newRoot = new TreeNode(0);
          newRoot.left = left;
          newRoot.right = right;

          fullBinaryTrees[i].push(newRoot);
        }
      }
    }
  }

  return fullBinaryTrees[n];
}

export { allPossibleFBT };
