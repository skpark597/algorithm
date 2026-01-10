"""
958. Check Completeness of a Binary Tree
Given the root of a binary tree, determine if it is a complete binary tree.
In a complete binary tree, every level, except possibly the last, is completely filled,
and all nodes in the last level are as far left as possible.
It can have between 1 and 2h nodes inclusive at the last level h.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: true
Explanation:
Every level before the last is full
(ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Example 2:
Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


Constraints:
The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
"""

from common.tree_node import TreeNode
from collections import deque


class Solution:
    def is_complete_tree(self, root: TreeNode) -> bool:
        queue, reached_end = deque([root]), False

        while len(queue) > 0:
            node = queue.popleft()

            if not node:
                reached_end = True
            elif node and reached_end:
                return False
            elif node and not reached_end:
                queue.append(node.left)
                queue.append(node.right)

        return True
