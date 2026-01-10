import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_list_nodes

import year_twenty_three.march.break_a_palindrome as break_a_palindrome
import year_twenty_three.march.largest_sum_of_averages as largest_sum_of_averages
import year_twenty_three.march.maximum_width_of_binary_tree as maximum_width_of_binary_tree
import year_twenty_three.march.merge_in_between_linked_lists as merge_in_between_linked_lists
import year_twenty_three.march.predict_the_winner as predict_the_winner
import year_twenty_three.march.minimum_deletions_to_make_array_beautiful as min_deletion

from common.list_node import ListNode
from common.tree_node import TreeNode


def test_predict_the_winner():
    solution0 = predict_the_winner.Solution()
    solution1 = predict_the_winner.Solution()

    nums0 = [1, 5, 2]
    nums1 = [1, 5, 233, 7]

    result0 = solution0.predict_the_winner(nums0)
    result1 = solution1.predict_the_winner(nums1)

    answer0 = False
    answer1 = True

    assert result0 == answer0
    assert result1 == answer1


def test_break_palindrome():
    solution0 = break_a_palindrome.Solution()
    solution1 = break_a_palindrome.Solution()
    solution2 = break_a_palindrome.Solution()
    solution3 = break_a_palindrome.Solution()
    solution4 = break_a_palindrome.Solution()

    palindrome0 = "abccba"
    palindrome1 = "a"
    palindrome2 = "bccaccb"
    palindrome3 = "aa"
    palindrome4 = "aba"

    result0 = solution0.break_palindrome(palindrome0)
    result1 = solution1.break_palindrome(palindrome1)
    result2 = solution2.break_palindrome(palindrome2)
    result3 = solution3.break_palindrome(palindrome3)
    result4 = solution4.break_palindrome(palindrome4)

    answer0 = "aaccba"
    answer1 = ""
    answer2 = "accaccb"
    answer3 = "ab"
    answer4 = "abb"

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2
    assert result3 == answer3
    assert result4 == answer4


def test_largest_sum_of_averages():
    solution0 = largest_sum_of_averages.Solution()
    solution1 = largest_sum_of_averages.Solution()
    solution2 = largest_sum_of_averages.Solution()

    nums0 = [9, 1, 2, 3, 9]
    k0 = 3

    nums1 = [1, 2, 3, 4, 5, 6, 7]
    k1 = 4

    nums2 = [4, 1, 7, 5, 6, 2, 3]
    k2 = 4

    result0 = solution0.largest_sum_of_averages(nums0, k0)
    result1 = solution1.largest_sum_of_averages(nums1, k1)
    result2 = solution2.largest_sum_of_averages(nums2, k2)

    answer0 = 20.00000
    answer1 = 20.50000
    answer2 = 18.16667

    assert round(result0, 5) == answer0
    assert round(result1, 5) == answer1
    assert round(result2, 5) == answer2


def test_width_of_binary_tree():
    solution0 = maximum_width_of_binary_tree.Solution()
    solution1 = maximum_width_of_binary_tree.Solution()
    solution2 = maximum_width_of_binary_tree.Solution()

    root0 = TreeNode.make([1, 3, 2, 5, 3, None, 9])
    root1 = TreeNode.make([1, 3, 2, 5, None, None, 9, 6, None, 7])
    root2 = TreeNode.make([1, 3, 2, 5])

    answer0 = 4
    answer1 = 7
    answer2 = 2

    result0 = solution0.width_of_binary_tree(root0)
    result1 = solution1.width_of_binary_tree(root1)
    result2 = solution2.width_of_binary_tree(root2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_merge_in_between_linked_lists():
    solution0 = merge_in_between_linked_lists.Solution()
    solution1 = merge_in_between_linked_lists.Solution()

    list01 = ListNode.make([0, 1, 2, 3, 4, 5])
    list02 = ListNode.make([1000000, 1000001, 1000002])
    a0, b0 = 3, 4

    list11 = ListNode.make([0, 1, 2, 3, 4, 5, 6])
    list12 = ListNode.make([1000000, 1000001, 1000002, 1000003, 1000004])
    a1, b1 = 2, 5

    answer0 = ListNode.make([0, 1, 2, 1000000, 1000001, 1000002, 5])
    answer1 = ListNode.make([0, 1, 1000000, 1000001, 1000002, 1000003, 1000004, 6])

    result0 = solution0.merge_in_between(list01, a0, b0, list02)
    result1 = solution1.merge_in_between(list11, a1, b1, list12)

    compare0 = is_same_list_nodes(result0, answer0)
    compare1 = is_same_list_nodes(result1, answer1)

    assert compare0 is True
    assert compare1 is True


def test_min_deletion():
    solution0 = min_deletion.Solution()
    solution1 = min_deletion.Solution()

    nums0 = [1, 1, 2, 3, 5]
    nums1 = [1, 1, 2, 2, 3, 3]

    answer0 = 1
    answer1 = 2

    result0 = solution0.min_deletion(nums0)
    result1 = solution1.min_deletion(nums1)

    assert result0 == answer0
    assert result1 == answer1
