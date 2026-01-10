/* 1457. Pseudo-Palindromic Paths in a Binary Tree **/
/*  Given a binary tree where node values are digits from 1 to 9.
 *  A path in the binary tree is said to be pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
 *  Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
 *
 *  Example 1:
 *  Input: root = [2,3,1,3,1,null,1]
 *  Output: 2
 *  Explanation: The figure above represents the given binary tree.
 *  There are three paths going from the root node to leaf nodes: the red path [2,3,3], the green path [2,1,1], and the path [2,3,1].
 *  Among these paths only red path and green path are pseudo-palindromic paths since the red path [2,3,3] can be rearranged in [3,2,3]
 *  (palindrome) and the green path [2,1,1] can be rearranged in [1,2,1] (palindrome).
 *
 *  Example 2:
 *  Input: root = [2,1,1,1,3,null,null,null,null,null,1]
 *  Output: 1
 *  Explanation: The figure above represents the given binary tree. There are three paths going from the root node to leaf nodes:
 *  the green path [2,1,1], the path [2,1,3,1], and the path [2,1].
 *  Among these paths only the green path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] (palindrome).
 *
 *  Example 3:
 *  Input: root = [9]
 *  Output: 1
 *
 *  Constraints:
 *  The number of nodes in the tree is in the range [1, 10^5].
 *  1 <= Node.val <= 9 */

import { TreeNode } from "../common/TreeNode";

function isPseudoPalindrom(valueCounts: number[]) {
  let oddCount = 0;

  for (const valueCount of valueCounts) {
    if (valueCount % 2 === 1) {
      oddCount++;
    }

    if (oddCount === 2) return false;
  }

  return true;
}

function findPseudoPalindrom(node: TreeNode | null, valueCounts: number[]) {
  let palindromCount = 0;

  if (node === null) return 0;

  valueCounts[node.val]++;
  if (node.left === null && node.right === null) {
    return isPseudoPalindrom(valueCounts) ? 1 : 0;
  }

  if (node.left) {
    palindromCount += findPseudoPalindrom(node.left, valueCounts);
    valueCounts[node.left.val]--;
  }

  if (node.right) {
    palindromCount += findPseudoPalindrom(node.right, valueCounts);
    valueCounts[node.right.val]--;
  }

  return palindromCount;
}

function pseudoPalindromicPaths(root: TreeNode | null): number {
  return findPseudoPalindrom(root, new Array(10).fill(0));
}

export { pseudoPalindromicPaths };
