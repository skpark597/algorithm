/** 1382. Balance a Binary Search Tree */
/** Given the root of a binary search tree, return a balanced binary search tree with the same node values.
 *  If there is more than one answer, return any of them.
 *  A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
 *
 *  Example 1:
 *  Input: root = [1,null,2,null,3,null,4,null,null]
 *  Output: [2,1,3,null,null,null,4]
 *  Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
 *
 *  Example 2:
 *  Input: root = [2,1,3]
 *  Output: [2,1,3]
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^4].
 *  1 <= Node.val <= 10^5
 */

import { TreeNode } from "../common/TreeNode";

function collectValues(node: TreeNode | null, values: number[] = []) {
  if (node === null) return [];

  collectValues(node.left, values);
  values.push(node.val);
  collectValues(node.right, values);

  return values;
}

function balanceBST(root: TreeNode | null): TreeNode | null {
  const values = collectValues(root);
  let newRoot: TreeNode | null = null;

  const generate = (i: number, j: number) => {
    if (i > j) return null;

    const middle = Math.floor((i + j) / 2);
    const node = new TreeNode(values[middle]);

    if (!newRoot) newRoot = node;

    node.left = generate(i, middle - 1);
    node.right = generate(middle + 1, j);

    return node;
  };

  generate(0, values.length - 1);
  return newRoot;
}

export { balanceBST };
