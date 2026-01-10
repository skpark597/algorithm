import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
from common.tree_node import TreeNode
import year_twenty_four.january.count_the_number_of_good_subarrays as count_the_number
import year_twenty_four.january.edit_distance as edit_distance
import year_twenty_four.january.remove_duplicates_from_sorted_array as remove_duplicates
import year_twenty_four.january.two_sum_iv as two_sum_iv
import year_twenty_four.january.divisor_game as divisor_game
import year_twenty_four.january.minimum_string_length_after_removing_substrings as min_length


def test_maximum_the_confusion():
    solution0 = count_the_number.Solution()
    solution1 = count_the_number.Solution()

    nums0, k0 = [1, 1, 1, 1, 1], 10
    nums1, k1 = [3, 1, 4, 3, 2, 2, 4], 2

    result0 = solution0.count_good(nums0, k0)
    result1 = solution1.count_good(nums1, k1)

    assert result0 == 1
    assert result1 == 4


def test_min_distance():
    solution0 = edit_distance.Solution()
    solution1 = edit_distance.Solution()

    word01, word02 = "horse", "ros"
    word11, word12 = "intention", "execution"

    result0 = solution0.min_distance(word01, word02)
    result1 = solution1.min_distance(word11, word12)

    assert result0 == 3
    assert result1 == 5


def test_remove_duplicates():
    solution0 = remove_duplicates.Solution()
    solution1 = remove_duplicates.Solution()

    nums0 = [1, 1, 2]
    nums1 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    result0 = solution0.remove_duplicates(nums0)
    result1 = solution1.remove_duplicates(nums1)

    answer0 = 2
    answer1 = 5

    assert result0 == answer0
    assert result1 == answer1


def test_find_target():
    solution0 = two_sum_iv.Solution()
    solution1 = two_sum_iv.Solution()

    nums0, k0 = [5, 3, 6, 2, 4, None, 7], 9
    nums1, k1 = [5, 3, 6, 2, 4, None, 7], 28

    root0 = TreeNode.make(nums0)
    root1 = TreeNode.make(nums1)

    result0 = solution0.find_target(root0, k0)
    result1 = solution1.find_target(root1, k1)

    assert result0 is True
    assert result1 is False


def test_divisor_game():
    solution0 = divisor_game.Solution()
    solution1 = divisor_game.Solution()

    n0, n1 = 2, 3

    result0 = solution0.divisor_game(n0)
    result1 = solution1.divisor_game(n1)

    assert result0 is True
    assert result1 is False


def test_min_length():
    solution0 = min_length.Solution()
    solution1 = min_length.Solution()

    s0, s1 = "ABFCACDB", "ACBBD"

    result0 = solution0.min_length(s0)
    result1 = solution1.min_length(s1)

    assert result0 == 2
    assert result1 == 5
