"""
1214. Two Sum BSTs
Given the roots of two binary search trees, root1 and root2, return true if and only if
there is a node in the first tree and a node in the second tree whose values sum up to a given integer target.

Example 1:
Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
Output: true
Explanation: 2 and 3 sum up to 5.

Example 2:
Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
Output: false


Constraints:
The number of nodes in each tree is in the range [1, 5000].
-10^9 <= Node.val, target <= 10^9
"""

from common.tree_node import TreeNode


class Solution:
    def two_sum_bsts(self, root0: TreeNode, root1: TreeNode, target: int) -> bool:
        def inorder(root: TreeNode | None):
            if root:
                yield from inorder(root.left)
                yield root.val
                yield from inorder(root.right)

        nums0, nums1 = list(inorder(root0)), list(inorder(root1))
        left, right = 0, len(nums1) - 1

        while left < len(nums0) and right >= 0:
            sum = nums0[left] + nums1[right]

            if sum == target:
                return True
            elif sum < target:
                left += 1
            else:
                right -= 1

        return False
