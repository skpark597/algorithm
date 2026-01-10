/** 863. All Nodes Distance K in Binary Tree */
/** Given the root of a binary tree, the value of a target node target, and an integer k,
 *  return an array of the values of all nodes that have a distance k from the target node.
 *  You can return the answer in any order.
 *
 *  Example 1:
 *  Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
 *  Output: [7,4,1]
 *  Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
 *
 *  Example 2:
 *  Input: root = [1], target = 1, k = 3
 *  Output: []
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 500].
 *  0 <= Node.val <= 500
 *  All the values Node.val are unique.
 *  target is the value of one of the nodes in the tree.
 *  0 <= k <= 1000 */

import { TreeNode } from "../common/TreeNode";

function getValues(
  start: TreeNode | null,
  k: number,
  parents: Record<number, TreeNode | null>
) {
  if (start === null) return [];

  let distance = 0;
  const discovered = new Set<number>();
  const values: number[] = [];
  const queue: TreeNode[] = [start];

  while (queue.length > 0) {
    const length = queue.length;

    for (let i = 0; i < length; ++i) {
      const current = queue.shift() as TreeNode;
      const parent = parents[current.val];
      const left = current.left;
      const right = current.right;

      discovered.add(current.val);

      if (distance === k) values.push(current.val);
      if (parent !== null && !discovered.has(parent.val)) queue.push(parent);
      if (left !== null && !discovered.has(left.val)) queue.push(left);
      if (right !== null && !discovered.has(right.val)) queue.push(right);
    }

    distance++;
  }

  return values;
}

function setParent(
  current: TreeNode,
  target: TreeNode,
  parents: Record<number, TreeNode | null>
): TreeNode | null {
  let fromLeftSubtree: TreeNode | null = null;
  let fromRightSubtree: TreeNode | null = null;
  let currentNode: TreeNode | null = null;

  if (current.val === target.val) {
    currentNode = current;
  }

  if (current.left) {
    parents[current.left.val] = current;
    fromLeftSubtree = setParent(current.left, target, parents);
  }

  if (current.right) {
    parents[current.right.val] = current;
    fromRightSubtree = setParent(current.right, target, parents);
  }

  return currentNode || fromLeftSubtree || fromRightSubtree;
}

function distanceK(
  root: TreeNode | null,
  target: TreeNode | null,
  k: number
): number[] {
  if (target === null) return [];
  if (root === null) return [];

  const parents: Record<number, TreeNode | null> = { [root.val]: null };
  const start = setParent(root, target, parents);
  return getValues(start, k, parents);
}

export { distanceK };
