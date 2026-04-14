"""
106. Construct Binary Tree from Inorder and Postorder Traversal
Given two integer arrays inorder and postorder where inorder is the inorder traversal of
a binary tree and postorder is the postorder traversal of the same tree,
construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.
"""

from common.tree_node import TreeNode


class Solution:
    def _build_recursive(self, inorder: list[int], postorder: list[int], i: int, left: TreeNode | None = None):
        if i == len(inorder):
            return left

        cur = TreeNode(val=inorder[i], left=left)

        if inorder[i] == postorder[i]:
            return self._build_recursive(inorder, postorder, i + 1, cur)

        nums = set()

        for j in range(i, len(inorder)):
            nums.add(inorder[j])
            nums.add(postorder[j])

            if len(nums) == j - i + 1:
                cur.right = self._build_recursive(inorder[i + 1 : j + 1], postorder[i:j], 0)
                break

        return self._build_recursive(inorder, postorder, j + 1, cur)

    def build_tree(self, inorder: list[int], postorder: list[int]) -> TreeNode:
        return self._build_recursive(inorder, postorder, 0)
