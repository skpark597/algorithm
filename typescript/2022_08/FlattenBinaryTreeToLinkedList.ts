/** 114. Flatten Binary Tree to Linked List */
/** Given the root of a binary tree, flatten the tree into a "linked list":
 *  The "linked list" should use the same TreeNode class where the right child pointer points to the next
 *  node in the list and the left child pointer is always null.
 *  The "linked list" should be in the same order as a pre-order traversal of the binary tree.
 *
 *  Example 1:
 *  Input: root = [1,2,5,3,4,null,6]
 *  Output: [1,null,2,null,3,null,4,null,5,null,6]
 *
 *  Example 2:
 *  Input: root = []
 *  Output: []
 *
 *  Example 3:
 *  Input: root = [0]
 *  Output: [0]
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [0, 2000].
 *  -100 <= Node.val <= 100 */

import { TreeNode } from "../common/TreeNode";

function traversePreorder(root: TreeNode | null, nodes: TreeNode[]) {
  if (root === null) return;

  nodes.push(root);

  traversePreorder(root.left, nodes);
  traversePreorder(root.right, nodes);
}

function toLinkedList(nodes: TreeNode[]) {
  const root = nodes[0];
  let prev: TreeNode = nodes[0];

  for (let i = 1; i < nodes.length; ++i) {
    const node = nodes[i];
    prev.left = null;
    prev.right = node;
    prev = node;
  }

  return root;
}

function flatten(root: TreeNode | null): void {
  if (root === null) return;

  const nodesInPreorder: TreeNode[] = [];
  traversePreorder(root, nodesInPreorder);
  toLinkedList(nodesInPreorder);
}

export { flatten };
