"""
199. Binary Tree Right Side View
Given the root of a binary tree, imagine yourself standing on the right side of it,
return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]

Example 3:
Input: root = [1,null,3]
Output: [1,3]

Example 4:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
"""

from collections import deque
from common.tree_node import TreeNode


class Solution:
    def right_side_view(self, root: TreeNode | None) -> list[int]:
        if not root:
            return []

        queue = deque([root])
        answer = []

        while queue:
            count = len(queue)

            for i in range(count):
                node = queue.popleft()

                if i == count - 1:
                    answer.append(node.val)

                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

        return answer
