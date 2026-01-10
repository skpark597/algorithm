import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_tree
from common.tree_node import TreeNode

import year_twenty_three.may.binary_tree_pruning as binary_tree_pruning
import year_twenty_three.may.find_all_numbers_disappeared_in_an_array as find_all_numbers


def test_binary_tree_pruning():
    solution0 = binary_tree_pruning.Solution()
    solution1 = binary_tree_pruning.Solution()
    solution2 = binary_tree_pruning.Solution()
    solution3 = binary_tree_pruning.Solution()

    root0 = TreeNode.make([1, None, 0, 0, 1])
    root1 = TreeNode.make([1, 0, 1, 0, 0, 0, 1])
    root2 = TreeNode.make([1, 1, 0, 1, 1, 0, 1, 0])
    root3 = TreeNode.make([0, None, 0, 0, 0])

    answer0 = TreeNode.make([1, None, 0, None, 1])
    answer1 = TreeNode.make([1, None, 1, None, 1])
    answer2 = TreeNode.make([1, 1, 0, 1, 1, None, 1])
    answer3 = TreeNode.make([])

    result0 = solution0.prune_tree(root0)
    result1 = solution1.prune_tree(root1)
    result2 = solution2.prune_tree(root2)
    result3 = solution3.prune_tree(root3)

    compare0 = is_same_tree(result0, answer0)
    compare1 = is_same_tree(result1, answer1)
    compare2 = is_same_tree(result2, answer2)
    compare3 = is_same_tree(result3, answer3)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True
    assert compare3 is True


# def test_find_maximum_xor():
#    solution0 = maximum_xor.Solution()
#    solution1 = maximum_xor.Solution()
#
#    nums0 = [3, 10, 5, 25, 2, 8]
#    nums1 = [14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70]
#
#    answer0 = 28
#    answer1 = 127
#
#    result0 = solution0.find_maximum_xor(nums0)
#    result1 = solution1.find_maximum_xor(nums1)
#
#    assert answer0 == result0
#    assert answer1 == result1


def test_find_disappeared_numbers():
    solution0 = find_all_numbers.Solution()
    solution1 = find_all_numbers.Solution()

    nums0 = [4, 3, 2, 7, 8, 2, 3, 1]
    nums1 = [1, 1]

    answer0 = [5, 6]
    answer1 = [2]

    result0 = solution0.find_disappeared_numbers(nums0)
    result1 = solution1.find_disappeared_numbers(nums1)

    assert answer0 == result0
    assert answer1 == result1
