/** 965. Univalued Binary Tree */
/** A binary tree is uni-valued if every node in the tree has the same value.
 *  Given the root of a binary tree, return true if the given tree is uni-valued,
 *  or false otherwise.
 *
 *  Example 1:
 *  Input: root = [1,1,1,1,1,null,1]
 *  Output: true
 *
 *  Example 2:
 *  Input: root = [2,2,2,5,2]
 *  Output: false
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 100].
 *  0 <= Node.val < 100 */

import { TreeNode } from "../common/TreeNode";

function isUnival(root: TreeNode, value: number): boolean {
  if (root.val !== value) return false;
  if (root.left && !isUnival(root.left, value)) return false;
  if (root.right && !isUnival(root.right, value)) return false;

  return true;
}

function isUnivalTree(root: TreeNode | null): boolean {
  if (root === null) return true;
  return isUnival(root, root.val);
}

export { isUnivalTree };
