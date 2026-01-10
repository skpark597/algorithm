"""
993. Cousins in Binary Tree
Given the root of a binary tree with unique values and the values of two different nodes
of the tree x and y, return true if the nodes corresponding to the values x and y in
the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.
Note that in a binary tree, the root node is at the depth 0,
and children of each depth k node are at the depth k + 1.

Example 1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Constraints:
The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.
"""


from queue import Queue

from common.tree_node import TreeNode


class Solution:
    def is_cousins(self, root: TreeNode, x: int, y: int) -> bool:
        children, parents = Queue(), Queue()
        children.put(root)
        parents.put(None)

        while not children.empty():
            count, x_parent, y_parent = children.qsize(), None, None

            for _ in range(count):
                child: TreeNode = children.get()
                parent: TreeNode = parents.get()

                if child.val == x:
                    x_parent = parent

                if child.val == y:
                    y_parent = parent

                if child.left is not None:
                    children.put(child.left)
                    parents.put(child)

                if child.right is not None:
                    children.put(child.right)
                    parents.put(child)

            if (
                x_parent is not None
                and y_parent is not None
                and x_parent.val != y_parent.val
            ):
                return True

        return False
