"""
250. Count Univalue Subtrees
A uni-value subtree means all nodes of the subtree have the same value.

Example 1:
Input: root = [5,1,5,5,5,null,5]
Output: 4

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [5,5,5,5,5,null,5]
Output: 6

Constraints:
The number of the node in the tree will be in the range [0, 1000].
-1000 <= Node.val <= 1000
"""

from typing import Optional

from common.tree_node import TreeNode


class Solution:
    def dfs(self, root: TreeNode) -> int:
        if root is None:
            return 0, True

        left, is_left_unival = self.dfs(root.left)
        right, is_right_unival = self.dfs(root.right)

        is_unival = (
            is_left_unival
            and is_right_unival
            and (not root.left or root.val == root.left.val)
            and (not root.right or root.val == root.right.val)
        )

        return left + right + int(is_unival), is_unival

    def count_unival_subtrees(self, root: Optional[TreeNode]) -> int:
        return self.dfs(root)[0]
