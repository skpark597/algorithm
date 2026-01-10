import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
from common.tree_node import TreeNode
import year_twenty_three.december.maximum_the_confusion_of_an_exam as maximum_the_confusion
import year_twenty_three.december.cousins_in_binary_tree as cousins_in_binary_tree
import year_twenty_three.december.longest_zigzag_path_in_a_binary_tree as longest_zigzag_path
import year_twenty_three.december.delete_operation_for_two_strings as delete_operation
import year_twenty_three.december.number_of_1_bits as number_of_1_bits


def test_maximum_the_confusion():
    solution0 = maximum_the_confusion.Solution()
    solution1 = maximum_the_confusion.Solution()
    solution2 = maximum_the_confusion.Solution()

    key0, k0 = "TTFF", 2
    key1, k1 = "TFFT", 1
    key2, k2 = "TTFTTFTT", 1

    result0 = solution0.max_consecutive_answers(key0, k0)
    result1 = solution1.max_consecutive_answers(key1, k1)
    result2 = solution2.max_consecutive_answers(key2, k2)

    answer0 = 4
    answer1 = 3
    answer2 = 5

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_is_cousins():
    solution0 = cousins_in_binary_tree.Solution()
    solution1 = cousins_in_binary_tree.Solution()
    solution2 = cousins_in_binary_tree.Solution()

    root0 = TreeNode.make([1, 2, 3, 4])
    x0, y0 = 4, 3

    root1 = TreeNode.make([1, 2, 3, None, 4, None, 5])
    x1, y1 = 5, 4

    root2 = TreeNode.make([1, 2, 3, None, 4])
    x2, y2 = 2, 2

    result0 = solution0.is_cousins(root0, x0, y0)
    result1 = solution1.is_cousins(root1, x1, y1)
    result2 = solution2.is_cousins(root2, x2, y2)

    assert result0 is False
    assert result1 is True
    assert result2 is False


def test_longest_zigzag():
    solution0 = longest_zigzag_path.Solution()
    solution1 = longest_zigzag_path.Solution()
    solution2 = longest_zigzag_path.Solution()

    root0 = TreeNode.make([1, None, 1, 1, 1, None, None, 1, 1, None, 1, None, None, None, 1])
    root1 = TreeNode.make([1, 1, 1, None, 1, None, None, 1, 1, None, 1])
    root2 = TreeNode.make([1])

    result0 = solution0.longest_zigzag(root0)
    result1 = solution1.longest_zigzag(root1)
    result2 = solution2.longest_zigzag(root2)

    assert result0 == 3
    assert result1 == 4
    assert result2 == 0


def test_delete_operation():
    solution0 = delete_operation.Solution()
    solution1 = delete_operation.Solution()

    word01, word02 = "sea", "eat"
    word11, word12 = "leetcode", "etco"

    result0 = solution0.min_distance(word01, word02)
    result1 = solution1.min_distance(word11, word12)

    assert result0 == 2
    assert result1 == 4


def test_number_of_1_bits():
    solution0 = number_of_1_bits.Solution()
    solution1 = number_of_1_bits.Solution()

    n0 = 11
    n1 = pow(2, 7)

    result0 = solution0.hamming_weight(n0)
    result1 = solution1.hamming_weight(n1)

    assert result0 == 3
    assert result1 == 1
