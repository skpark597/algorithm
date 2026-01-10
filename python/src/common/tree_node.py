from typing import List, Optional
from queue import Queue


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    @staticmethod
    def make(nums: List[Optional[int]]):
        if len(nums) == 0 or nums[0] is None:
            return None

        root = TreeNode(nums[0])
        queue = Queue()
        queue.put(root)

        for index in range(1, len(nums), 2):
            node = queue.get()

            if nums[index] is not None:
                node.left = TreeNode(nums[index])
            if index + 1 < len(nums) and nums[index + 1] is not None:
                node.right = TreeNode(nums[index + 1])

            if node.left is not None:
                queue.put(node.left)
            if node.right is not None:
                queue.put(node.right)

        return root
