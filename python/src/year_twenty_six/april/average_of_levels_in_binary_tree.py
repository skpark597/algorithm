"""
637. Average of Levels in Binary Tree
Given the root of a binary tree, return the average value of the nodes on each level
in the form of an array. Answers within 10-5 of the actual answer will be accepted.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:
Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]

Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-2^31 <= Node.val <= 2^31 - 1
"""

from collections import deque

from common.tree_node import TreeNode


class Solution:
    def average_of_levels(self, root: TreeNode) -> list[float]:
        queue = deque([root])
        result = []

        while queue:
            cur_sum, q_len = 0, len(queue)

            for _ in range(q_len):
                node = queue.popleft()
                cur_sum += node.val

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

            result.append(cur_sum / q_len)

        return result
