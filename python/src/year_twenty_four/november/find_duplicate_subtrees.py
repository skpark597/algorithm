"""
652. Find Duplicate Subtrees
Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:
Input: root = [2,1,1]
Output: [[1]]

Example 3:
Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]


Constraints:
The number of the nodes in the tree will be in the range [1, 5000]
-200 <= Node.val <= 200
"""

from common.tree_node import TreeNode


class Solution:
    def find_duplicate_subtrees(self, root: TreeNode) -> list[TreeNode]:
        serializes = {}
        duplicates = []

        def serialize(node: TreeNode) -> str:
            if not node:
                return "#"

            left = serialize(node.left)
            right = serialize(node.right)

            value = f"{node.val},{left},{right}"
            serializes[value] = serializes.get(value, 0) + 1

            if serializes[value] == 2:
                duplicates.append(node)

            return f"{node.val},{left},{right}"

        serialize(root)

        return duplicates
