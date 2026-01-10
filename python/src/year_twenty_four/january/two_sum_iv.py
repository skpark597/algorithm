"""
653. Two Sum IV - Input is a BST
Given the root of a binary search tree and an integer k,
return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-10^4 <= Node.val <= 10^4
root is guaranteed to be a valid binary search tree.
-10^5 <= k <= 10^5
"""

# pylint: disable=E0401
from common.tree_node import TreeNode


class Solution:
    def dfs(self, node: TreeNode, k: int, values: set, completents: set):
        values.add(node.val)
        completents.add(k - node.val)

        if node.left is not None:
            self.dfs(node.left, k, values, completents)

        if node.right is not None:
            self.dfs(node.right, k, values, completents)

    def find_target(self, root: TreeNode, k: int) -> bool:
        values, complements = set(), set()
        self.dfs(root, k, values, complements)

        for value in values:
            if value != k / 2 and value in complements:
                return True

        return False
