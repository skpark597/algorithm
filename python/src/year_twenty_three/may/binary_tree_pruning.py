"""
814. Binary Tree Pruning

Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
A subtree of a node node is node plus every node that is a descendant of node.

Example 1:
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation:
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.

Example 2:
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]

Example 3:
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]

Constraints:
The number of nodes in the tree is in the range [1, 200].
Node.val is either 0 or 1.

"""

from typing import Optional
from common.tree_node import TreeNode


class Solution:
    def prune_zero_subtrees(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return False

        is_left_contains_one = self.prune_zero_subtrees(root.left)
        is_right_contains_one = self.prune_zero_subtrees(root.right)

        if is_left_contains_one is False:
            root.left = None

        if is_right_contains_one is False:
            root.right = None

        return is_left_contains_one or is_right_contains_one or root.val == 1

    def prune_tree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None

        is_contains_one = self.prune_zero_subtrees(root)

        return None if is_contains_one is False else root
