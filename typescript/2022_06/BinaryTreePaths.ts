/** 257. Binary Tree Paths */
/** Given the root of a binary tree, return all root-to-leaf paths in any order.
 *  A leaf is a node with no children.
 *
 *  Example 1:
 *  Input: root = [1,2,3,null,5]
 *  Output: ["1->2->5","1->3"]
 *
 *  Example 2:
 *  Input: root = [1]
 *  Output: ["1"]
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 100].
 *  -100 <= Node.val <= 100 */
import { TreeNode } from "../common/TreeNode";

function addPath(currentPath: string, root: TreeNode) {
  let ret: string = currentPath;

  if (currentPath.length === 0) {
    ret += `${root.val}`;
  } else {
    ret += `->${root.val}`;
  }

  return ret;
}

function dfs(root: TreeNode, currentPath: string, paths: string[]) {
  if (root.left === null && root.right === null) {
    paths.push(addPath(currentPath, root));
    return;
  }

  if (root.left) {
    dfs(root.left, addPath(currentPath, root), paths);
  }

  if (root.right) {
    dfs(root.right, addPath(currentPath, root), paths);
  }
}

function binaryTreePaths(root: TreeNode | null): string[] {
  if (root === null) return [];

  const paths: string[] = [];
  const currentPath = "";

  dfs(root, currentPath, paths);

  return paths;
}

export { binaryTreePaths };
