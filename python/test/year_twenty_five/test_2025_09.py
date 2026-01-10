import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.september.campus_bikes_ii as assign_bikes
import year_twenty_five.september.can_i_win as can_i_win
import year_twenty_five.september.check_if_a_number_is_majority_element_in_a_sorted_array as is_majority_element
import year_twenty_five.september.complete_binary_tree_inserter as cbt_inserter
import year_twenty_five.september.largest_unique_number as largest_unique_number
import year_twenty_five.september.maximum_distance_between_a_pair_of_values as max_distance
import year_twenty_five.september.number_of_matching_subsequences as num_matching_subseq
import year_twenty_five.september.number_of_wonderful_substrings as wonderful_substrings
import year_twenty_five.september.rotated_digits as rotated_digits
import year_twenty_five.september.shortest_way_to_form_string as shortest_way
import year_twenty_five.september.two_best_non_overlapping_events as max_two_events
from common.tree_node import TreeNode
from common.util import is_same_tree


def test_assign_bikes():
    solution = assign_bikes.Solution()

    workers0 = [[0, 0], [2, 1]]
    workers1 = [[0, 0], [1, 1], [2, 0]]
    workers2 = [[0, 0], [1, 0], [2, 0], [3, 0], [4, 0]]

    bikes0 = [[1, 2], [3, 3]]
    bikes1 = [[1, 0], [2, 2], [2, 1]]
    bikes2 = [[0, 999], [1, 999], [2, 999], [3, 999], [4, 999]]

    ret0 = solution.assign_bikes(workers0, bikes0)
    ret1 = solution.assign_bikes(workers1, bikes1)
    ret2 = solution.assign_bikes(workers2, bikes2)

    assert ret0 == 6
    assert ret1 == 4
    assert ret2 == 4995


def test_can_i_win():
    solution = can_i_win.Solution()

    max_int0, total0 = 10, 11
    max_int1, total1 = 10, 0
    max_int2, total2 = 10, 1
    max_int3, total3 = 5, 50

    ret0 = solution.can_i_win(max_int0, total0)
    ret1 = solution.can_i_win(max_int1, total1)
    ret2 = solution.can_i_win(max_int2, total2)
    ret3 = solution.can_i_win(max_int3, total3)

    assert ret0 is False
    assert ret1 is True
    assert ret2 is True
    assert ret3 is False


def test_largest_unique_number():
    solution = largest_unique_number.Solution()

    nums0 = [5, 7, 3, 9, 4, 9, 8, 3, 1]
    nums1 = [9, 9, 8, 8]

    ret0 = solution.largest_unique_number(nums0)
    ret1 = solution.largest_unique_number(nums1)

    assert ret0 == 8
    assert ret1 == -1


def test_num_matching_subseq():
    solution = num_matching_subseq.Solution()

    s0, words0 = "abcde", ["a", "bb", "acd", "ace"]
    s1, words1 = "dsahjpjauf", ["ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"]

    ret0 = solution.num_matching_subseq(s0, words0)
    ret1 = solution.num_matching_subseq(s1, words1)

    assert ret0 == 3
    assert ret1 == 2


def test_max_distance():
    solution = max_distance.Solution()

    nums01, nums02 = [55, 30, 5, 4, 2], [100, 20, 10, 10, 5]
    nums11, nums12 = [2, 2, 2], [10, 10, 1]
    nums21, nums22 = [30, 29, 19, 5], [25, 25, 25, 25, 25]

    ret0 = solution.max_distance(nums01, nums02)
    ret1 = solution.max_distance(nums11, nums12)
    ret2 = solution.max_distance(nums21, nums22)

    assert ret0 == 2
    assert ret1 == 1
    assert ret2 == 2


def test_shortest_way():
    solution = shortest_way.Solution()

    source0, target0 = "abc", "abcbc"
    source1, target1 = "abc", "acdbc"
    source2, target2 = "xyz", "xzyxz"
    source3, target3 = "aaaaa", "aaaaaaaaaaaaa"

    ret0 = solution.shortest_way(source0, target0)
    ret1 = solution.shortest_way(source1, target1)
    ret2 = solution.shortest_way(source2, target2)
    ret3 = solution.shortest_way(source3, target3)

    assert ret0 == 2
    assert ret1 == -1
    assert ret2 == 3
    assert ret3 == 3


def test_rotated_digits():
    solution = rotated_digits.Solution()

    n0 = 10
    n1 = 1
    n2 = 2
    n3 = 29
    n4 = 99
    n5 = 231

    ret0 = solution.rotated_digits(n0)
    ret1 = solution.rotated_digits(n1)
    ret2 = solution.rotated_digits(n2)
    ret3 = solution.rotated_digits(n3)
    ret4 = solution.rotated_digits(n4)
    ret5 = solution.rotated_digits(n5)

    assert ret0 == 4
    assert ret1 == 0
    assert ret2 == 1
    assert ret3 == 15
    assert ret4 == 40
    assert ret5 == 101


def test_cbt_inserter():
    root0 = TreeNode.make([1, 2])
    after_insertion0 = TreeNode.make([1, 2, 3, 4])
    inserter0 = cbt_inserter.CBTInserter(root0)

    assert inserter0.insert(3) == 1
    assert inserter0.insert(4) == 2
    assert is_same_tree(inserter0.get_root(), after_insertion0)


def test_wonderful_substrings():
    solution = wonderful_substrings.Solution()

    word0 = "aba"
    word1 = "aabb"
    word2 = "he"

    ret0 = solution.wonderful_substrings(word0)
    ret1 = solution.wonderful_substrings(word1)
    ret2 = solution.wonderful_substrings(word2)

    assert ret0 == 4
    assert ret1 == 9
    assert ret2 == 2


def test_is_majority_element():
    solution = is_majority_element.Solution()

    nums0 = [2, 4, 5, 5, 5, 5, 5, 6, 6]
    nums1 = [10, 100, 101, 101]

    target0 = 5
    target1 = 101

    ret0 = solution.is_majority_element(nums0, target0)
    ret1 = solution.is_majority_element(nums1, target1)

    assert ret0 is True
    assert ret1 is False


def test_max_two_events():
    solution = max_two_events.Solution()

    events0 = [[1, 3, 2], [4, 5, 2], [2, 4, 3]]
    events1 = [[1, 3, 2], [4, 5, 2], [1, 5, 5]]
    events2 = [[1, 5, 3], [1, 5, 1], [6, 6, 5]]
    events3 = [[66, 97, 90], [98, 98, 68], [38, 49, 63], [91, 100, 42], [92, 100, 22], [1, 77, 50], [64, 72, 97]]

    ret0 = solution.max_two_events(events0)
    ret1 = solution.max_two_events(events1)
    ret2 = solution.max_two_events(events2)
    ret3 = solution.max_two_events(events3)

    assert ret0 == 4
    assert ret1 == 5
    assert ret2 == 8
    assert ret3 == 165
