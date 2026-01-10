/** 1302. Deepest Leaves Sum */
/** Given the root of a binary tree, return the sum of values of its deepest leaves.
 *
 *  Example 1:
 *  Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 *  Output: 15
 *
 *  Example 2:
 *  Input: root = [7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 *  Output: 19
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  1 <= Node.val <= 100 */
import { TreeNode } from "../common/TreeNode";

function sumOfMaxDepth(
  root: TreeNode | null,
  maxDepth: number,
  previousDepth = 0
): number {
  let sum = 0;

  if (root === null) return 0;
  if (previousDepth + 1 === maxDepth) sum += root.val;

  sum += sumOfMaxDepth(root.left, maxDepth, previousDepth + 1);
  sum += sumOfMaxDepth(root.right, maxDepth, previousDepth + 1);

  return sum;
}

function getMaxDepth(root: TreeNode | null, previousDepth = 0): number {
  if (root === null) return previousDepth;

  const leftMax = getMaxDepth(root.left, previousDepth + 1);
  const rightMax = getMaxDepth(root.right, previousDepth + 1);

  return Math.max(leftMax, rightMax);
}

function deepestLeavesSum(root: TreeNode | null): number {
  const maxDepth = getMaxDepth(root);
  return sumOfMaxDepth(root, maxDepth);
}

export { deepestLeavesSum };
