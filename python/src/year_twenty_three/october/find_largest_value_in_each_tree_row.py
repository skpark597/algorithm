"""
515. Find Largest Value in Each Tree Row
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]

Constraints:
The number of nodes in the tree will be in the range [0, 10^4].
-2^31 <= Node.val <= 2^31-1
"""

import queue
import sys

from typing import List, Optional
from common.tree_node import TreeNode


class Solution:
    def largest_values(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        q = queue.Queue()
        q.put(root)

        count, row_max, result = 1, -sys.maxsize - 1, []

        while not q.empty():
            for _ in range(count):
                node = q.get()
                row_max = max(row_max, node.val)

                if node.left is not None:
                    q.put(node.left)

                if node.right is not None:
                    q.put(node.right)

            count = q.qsize()
            result.append(row_max)
            row_max = -sys.maxsize - 1

        return result
