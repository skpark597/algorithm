import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_arrays_ignoring_order, is_same_list_nodes

import year_twenty_two.december.arithmetic_subarrays as arithmetic_subarrays
import year_twenty_two.december.maximum_split_of_positive_even_integer as maximum_split
import year_twenty_two.december.partition_list as partition_list
from common.list_node import ListNode


def test_maximum_split_of_positive_even_integers():
    final_sum0 = 12
    final_sum1 = 7
    final_sum2 = 28

    solution0 = maximum_split.Solution()
    solution1 = maximum_split.Solution()
    solution2 = maximum_split.Solution()

    result0 = solution0.maximum_even_split(final_sum0)
    result1 = solution1.maximum_even_split(final_sum1)
    result2 = solution2.maximum_even_split(final_sum2)

    answer0 = [2, 4, 6]
    answer1 = []
    answer2 = [2, 4, 6, 16]

    compare0 = is_same_arrays_ignoring_order(result0, answer0)
    compare1 = is_same_arrays_ignoring_order(result1, answer1)
    compare2 = is_same_arrays_ignoring_order(result2, answer2)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True


def test_partition_list():
    head0 = ListNode.make([1, 4, 3, 2, 5, 2])
    head1 = ListNode.make([2, 1])
    head2 = ListNode.make([])
    head3 = ListNode.make([1, 4, 3, 0, 2, 5, 2])

    x0 = 3
    x1 = 2
    x2 = 0
    x3 = 3

    solution0 = partition_list.Solution()
    solution1 = partition_list.Solution()
    solution2 = partition_list.Solution()
    solution3 = partition_list.Solution()

    result0 = solution0.partition(head0, x0)
    result1 = solution1.partition(head1, x1)
    result2 = solution2.partition(head2, x2)
    result3 = solution3.partition(head3, x3)

    answer0 = ListNode.make([1, 2, 2, 4, 3, 5])
    answer1 = ListNode.make([1, 2])
    answer2 = ListNode.make([])
    answer3 = ListNode.make([1, 0, 2, 2, 4, 3, 5])

    compare0 = is_same_list_nodes(result0, answer0)
    compare1 = is_same_list_nodes(result1, answer1)
    compare2 = is_same_list_nodes(result2, answer2)
    compare3 = is_same_list_nodes(result3, answer3)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True
    assert compare3 is True


def test_arithmetic_subarrays():
    nums0 = [4, 6, 5, 9, 3, 7]
    nums1 = [-12, -9, -3, -12, -6, 15, 20, -25, -20, -15, -10]

    l0 = [0, 0, 2]
    l1 = [0, 1, 6, 4, 8, 7]

    r0 = [2, 3, 5]
    r1 = [4, 4, 9, 7, 9, 10]

    solution0 = arithmetic_subarrays.Solution()
    solution1 = arithmetic_subarrays.Solution()

    result0 = solution0.check_arithmetic_subarrays(nums0, l0, r0)
    result1 = solution1.check_arithmetic_subarrays(nums1, l1, r1)

    answer0 = [True, False, True]
    answer1 = [False, True, False, False, True, True]

    assert result0 == answer0
    assert result1 == answer1
