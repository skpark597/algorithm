"""
1372. Longest ZigZag Path in a Binary Tree

You are given the root of a binary tree.
A ZigZag path for a binary tree is defined as follow:
Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 5 * 10^4].
1 <= Node.val <= 100
"""


from typing import List
from common.tree_node import TreeNode


class Solution:
    def dfs(self, node: TreeNode) -> List[int]:
        (_, to_right, max_right) = self.dfs(node.left) if node.left else (-1, -1, 0)
        (to_left, _, max_left) = self.dfs(node.right) if node.right else (-1, -1, 0)

        return (
            to_right + 1,
            to_left + 1,
            max(max_right, max_left, to_right + 1, to_left + 1),
        )

    def longest_zigzag(self, root: TreeNode) -> int:
        _, _, maximum = self.dfs(root)
        return maximum
