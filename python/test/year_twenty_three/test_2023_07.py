import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_double_arrays_ignoring_order

import year_twenty_three.july.group_the_people_given_the_group_size_they_belong_to as group_the_people
import year_twenty_three.july.longest_nice_substring as longest_nice_substring
import year_twenty_three.july.maximum_sum_of_two_non_overlapping_subarrays as max_sum_two_overlap
import year_twenty_three.july.optimal_partition_of_string as partition_string


def test_partition_string():
    solution0 = partition_string.Solution()
    solution1 = partition_string.Solution()
    s0, s1 = "abacaba", "ssssss"

    result0 = solution0.partition_string(s0)
    result1 = solution1.partition_string(s1)
    answer0, answer1 = 4, 6

    assert result0 == answer0
    assert result1 == answer1


def test_max_sum_two_no_overlap():
    solution0 = max_sum_two_overlap.Solution()
    solution1 = max_sum_two_overlap.Solution()
    solution2 = max_sum_two_overlap.Solution()

    nums0, first_len0, second_len0 = [0, 6, 5, 2, 2, 5, 1, 9, 4], 1, 2
    nums1, first_len1, second_len1 = [3, 8, 1, 3, 2, 1, 8, 9, 0], 3, 2
    nums2, first_len2, second_len2 = [2, 1, 5, 6, 0, 9, 5, 0, 3, 8], 4, 3

    result0 = solution0.max_sum_two_no_overlap(nums0, first_len0, second_len0)
    result1 = solution1.max_sum_two_no_overlap(nums1, first_len1, second_len1)
    result2 = solution2.max_sum_two_no_overlap(nums2, first_len2, second_len2)

    answer0, answer1, answer2 = 20, 29, 31

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_longest_nice_substring():
    solution0 = longest_nice_substring.Solution()
    solution1 = longest_nice_substring.Solution()
    solution2 = longest_nice_substring.Solution()

    s0, s1, s2 = "YazaAay", "Bb", "c"

    result0 = solution0.longest_nice_substring(s0)
    result1 = solution1.longest_nice_substring(s1)
    result2 = solution2.longest_nice_substring(s2)

    answer0, answer1, answer2 = "aAa", "Bb", ""

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_group_the_people():
    solution0 = group_the_people.Solution()
    solution1 = group_the_people.Solution()

    group_sizes0 = [3, 3, 3, 3, 3, 1, 3]
    group_sizes1 = [2, 1, 3, 3, 3, 2]

    result0 = solution0.group_the_people(group_sizes0)
    result1 = solution1.group_the_people(group_sizes1)

    answer0 = [[5], [0, 1, 2], [3, 4, 6]]
    answer1 = [[1], [0, 5], [2, 3, 4]]

    compare0 = is_same_double_arrays_ignoring_order(result0, answer0)
    compare1 = is_same_double_arrays_ignoring_order(result1, answer1)

    assert compare0 is True
    assert compare1 is True
