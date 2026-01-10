/** 95. Unique Binary Search Trees II */
/** Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of
 *  unique values from 1 to n. Return the answer in any order.
 *
 *  Example 1:
 *  Input: n = 3
 *  Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *  Example 2:
 *  Input: n = 1
 *  Output: [[1]]
 *  Constraints: 1 <= n <= 8  */

import { TreeNode } from "../common/TreeNode";

// numbers에 들어오는 값은 정렬이 되어있어야 한다
function generateTreeFromList(values: number[]) {
  if (values.length === 0) return [null];
  if (values.length === 1) return [new TreeNode(values[0])];

  const trees: TreeNode[] = [];

  for (let i = 0; i < values.length; ++i) {
    const leftTrees = generateTreeFromList(values.slice(0, i));
    const rightTrees = generateTreeFromList(values.slice(i + 1));

    for (const left of leftTrees) {
      for (const right of rightTrees) {
        trees.push(new TreeNode(values[i], left, right));
      }
    }
  }

  return trees;
}

function generateTrees(n: number) {
  const oneToN = Array.from({ length: n }, (_, i) => i + 1);
  return generateTreeFromList(oneToN);
}

export { generateTrees };
