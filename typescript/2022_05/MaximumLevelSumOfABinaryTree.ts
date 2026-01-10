/** 1161. Maximum Level Sum of a Binary Tree */
/** Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
 *  Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
 *  Example 1:
 *  Input: root = [1,7,0,7,-8,null,null]
 *  Output: 2
 *
 *  Explanation:
 *  Level 1 sum = 1.
 *  Level 2 sum = 7 + 0 = 7.
 *  Level 3 sum = 7 + -8 = -1.
 *  So we return the level with the maximum sum which is level 2.
 *
 *  Example 2:
 *  Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 *  Output: 2
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  -10^5 <= Node.val <= 10^5 */

import { TreeNode } from "../common/TreeNode";

function maxLevelSum(root: TreeNode | null): number {
  // root cannot be null. specify the type of root as "TreeNode"
  const queue: TreeNode[] = [root as TreeNode];
  const levelSums: number[] = [];
  let max = Number.MIN_SAFE_INTEGER;

  while (queue.length > 0) {
    const length = queue.length;
    let levelSum = 0;

    for (let i = 0; i < length; ++i) {
      // current cannot be null since it is shifted element of array of type "TreeNode"
      const current = queue.shift() as TreeNode;
      levelSum += current.val;

      if (current.left) {
        queue.push(current.left);
      }

      if (current.right) {
        queue.push(current.right);
      }
    }

    levelSums.push(levelSum);
    max = Math.max(max, levelSum);
  }

  for (let i = 0; i < levelSums.length; ++i) {
    if (levelSums[i] === max) return i + 1;
  }

  return 0;
}

export { maxLevelSum };
