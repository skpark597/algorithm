import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.tree_node import TreeNode
from common.util import is_same_tree
import year_twenty_six.april.construct_binary_tree_from_inorder_and_postorder_traversal as inorder_and_postorder_traversal


def test_inorder_and_postorder_traversal():
    solution = inorder_and_postorder_traversal.Solution()

    inorder0 = [9, 3, 15, 20, 7]
    postorder0 = [9, 15, 7, 20, 3]

    inorder1 = [-1]
    postorder1 = [-1]

    inorder2 = [8, 1, 4, 3, 15, 20, 2, 7, 9]
    postorder2 = [8, 4, 1, 15, 2, 9, 7, 20, 3]

    ret0 = solution.build_tree(inorder0, postorder0)
    ret1 = solution.build_tree(inorder1, postorder1)
    ret2 = solution.build_tree(inorder2, postorder2)

    ans0 = TreeNode.make([3, 9, 20, None, None, 15, 7])
    ans1 = TreeNode.make([-1])
    ans2 = TreeNode.make([3, 1, 20, 8, 4, 15, 7, None, None, None, None, None, None, 2, 9])

    assert is_same_tree(ret0, ans0)
    assert is_same_tree(ret1, ans1)
    assert is_same_tree(ret2, ans2)
