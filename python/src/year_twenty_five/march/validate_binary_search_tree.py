"""
98. Validate Binary Search Tree
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
"""

from typing import Optional
from common.tree_node import TreeNode


class Solution:
    # all values of subtree > below and < above
    def dfs(self, root: Optional[TreeNode], below: int, above: int):
        if root is None:
            return True

        if root.val <= below or root.val >= above:
            return False

        is_left_valid = self.dfs(root.left, below, root.val)
        is_right_valid = self.dfs(root.right, root.val, above)

        return is_left_valid and is_right_valid

    def is_valid_bst(self, root: TreeNode) -> bool:
        min_val, max_val = -(2**31) - 1, 2**31
        return self.dfs(root, min_val, max_val)
