"""
1123. Lowest Common Ancestor of Deepest Leaves
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:
- The node of a binary tree is a leaf if and only if it has no children
- The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
- The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.

Example 2:
Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.

Example 3:
Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.

Constraints:
The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.
"""

# pylint: disable=E0401
from queue import Queue
from typing import Dict, List
from common.tree_node import TreeNode


class Solution:
    def extract_deepest_nodes(self, root: TreeNode) -> List[TreeNode]:
        queue = Queue()
        queue.put(root)

        while queue.qsize() > 0:
            current_size, deepest = queue.qsize(), []

            for _ in range(current_size):
                node = queue.get()
                deepest.append(node)

                if node.left is not None:
                    queue.put(node.left)

                if node.right is not None:
                    queue.put(node.right)

        return deepest

    def _create_child_parent_relation(self, root: TreeNode) -> Dict[TreeNode, TreeNode]:
        queue, parents = Queue(), {}
        queue.put(root)

        while queue.qsize() > 0:
            current_size = queue.qsize()

            for _ in range(current_size):
                node = queue.get()

                if node.left is not None:
                    queue.put(node.left)
                    parents[node.left] = node

                if node.right is not None:
                    queue.put(node.right)
                    parents[node.right] = node

        return parents

    def find_lowest_common_ancestor(self, root: TreeNode, nodes: List[TreeNode]) -> TreeNode:
        parents = self._create_child_parent_relation(root)

        while len(nodes) != 1:
            nodes = list(set([parents[node] for node in nodes]))

        return nodes[0]

    def lca_deepest_leaves(self, root: TreeNode) -> TreeNode:
        deepest_nodes = self.extract_deepest_nodes(root)
        return self.find_lowest_common_ancestor(root, deepest_nodes)
