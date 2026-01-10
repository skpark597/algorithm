import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.november.binary_string_with_substrings_representing_1_to_n as query_string
import year_twenty_five.november.maximum_number_of_eaten_apples as eaten_apples
import year_twenty_five.november.maximum_value_at_a_given_index_in_a_bounded_array as max_value
import year_twenty_five.november.remove_duplicates_from_an_unsorted_linked_list as delete_duplicates_unsorted
import year_twenty_five.november.shortest_distance_to_target_color as shortest_distance_color
import year_twenty_five.november.smallest_number_in_infinite_set as smallest_infinite_set
import year_twenty_five.november.sparse_matrix_multiplication as sparse_matrix_multiplication
import year_twenty_five.november.stone_game_ii as stone_game_ii
import year_twenty_five.november.three_sum_smaller as three_sum_smaller
import year_twenty_five.november.two_sum_iii as two_sum_iii
import year_twenty_five.november.range_addition as range_addition
from common.list_node import ListNode
from common.util import is_same_list_nodes


def test_multiply():
    solution = sparse_matrix_multiplication.Solution()

    mat01, mat02 = [[1, 0, 0], [-1, 0, 3]], [[7, 0, 0], [0, 0, 0], [0, 0, 1]]
    mat11, mat12 = [[0]], [[0]]
    mat21, mat22 = [[1, -5]], [[12], [-1]]

    ret0 = solution.multiply(mat01, mat02)
    ret1 = solution.multiply(mat11, mat12)
    ret2 = solution.multiply(mat21, mat22)

    assert ret0 == [[7, 0, 0], [-7, 0, 3]]
    assert ret1 == [[0]]
    assert ret2 == [[17]]


def test_max_value():
    solution = max_value.Solution()

    n0, index0, max_sum0 = 4, 2, 6
    n1, index1, max_sum1 = 6, 1, 10
    n2, index2, max_sum2 = 8, 7, 14
    n3, index3, max_sum3 = 4, 0, 4

    ret0 = solution.max_value(n0, index0, max_sum0)
    ret1 = solution.max_value(n1, index1, max_sum1)
    ret2 = solution.max_value(n2, index2, max_sum2)
    ret3 = solution.max_value(n3, index3, max_sum3)

    assert ret0 == 2
    assert ret1 == 3
    assert ret2 == 4
    assert ret3 == 1


def test_delete_duplicates_unsorted():
    solution = delete_duplicates_unsorted.Solution()

    head0 = ListNode.make([1, 2, 3, 2])
    head1 = ListNode.make([2, 1, 1, 2])
    head2 = ListNode.make([3, 2, 2, 1, 3, 2, 4])

    ret0 = solution.delete_duplicates_unsorted(head0)
    ret1 = solution.delete_duplicates_unsorted(head1)
    ret2 = solution.delete_duplicates_unsorted(head2)

    answer0 = ListNode.make([1, 3])
    answer1 = ListNode.make([])
    answer2 = ListNode.make([1, 4])

    assert is_same_list_nodes(ret0, answer0)
    assert is_same_list_nodes(ret1, answer1)
    assert is_same_list_nodes(ret2, answer2)


def test_eaten_apples():
    solution = eaten_apples.Solution()

    apples0 = [1, 2, 3, 5, 2]
    days0 = [3, 2, 1, 4, 2]

    apples1 = [3, 0, 0, 0, 0, 2]
    days1 = [3, 0, 0, 0, 0, 2]

    ret0 = solution.eaten_apples(apples0, days0)
    ret1 = solution.eaten_apples(apples1, days1)

    assert ret0 == 7
    assert ret1 == 5


def test_two_sum_iii():
    two_sum0 = two_sum_iii.TwoSum2()

    two_sum0.add(3)
    two_sum0.add(1)
    two_sum0.add(5)

    ret0 = two_sum0.find(4)
    ret1 = two_sum0.find(7)

    two_sum1 = two_sum_iii.TwoSum2()

    two_sum1.add(3)
    two_sum1.add(2)
    two_sum1.add(1)

    ret2 = two_sum1.find(2)
    ret3 = two_sum1.find(3)
    ret4 = two_sum1.find(4)
    ret5 = two_sum1.find(5)
    ret6 = two_sum1.find(6)

    assert ret0 is True
    assert ret1 is False

    assert ret2 is False
    assert ret3 is True
    assert ret4 is True
    assert ret5 is True
    assert ret6 is False


def test_shortest_distance_color():
    solution = shortest_distance_color.Solution()

    colors0 = [1, 1, 2, 1, 3, 2, 2, 3, 3]
    queries0 = [[1, 3], [2, 2], [6, 1]]

    colors1 = [1, 2]
    queries1 = [[0, 3]]

    ret0 = solution.shortest_distance_color(colors0, queries0)
    ret1 = solution.shortest_distance_color(colors1, queries1)

    assert ret0 == [3, 0, 3]
    assert ret1 == [-1]


def test_stone_game_ii():
    solution = stone_game_ii.Solution()

    piles0 = [2, 7, 9, 4, 4]
    piles1 = [1, 2, 3, 4, 5, 100]
    piles2 = [77, 12, 64, 35, 28, 4, 87, 21, 20]

    ret0 = solution.stone_game_ii(piles0)
    ret1 = solution.stone_game_ii(piles1)
    ret2 = solution.stone_game_ii(piles2)

    assert ret0 == 10
    assert ret1 == 104
    assert ret2 == 217


def test_three_sum_smaller():
    solution0 = three_sum_smaller.Solution0()
    solution1 = three_sum_smaller.Solution1()

    nums0, target0 = [-2, 0, 1, 3], 2
    nums1, target1 = [], 0
    nums2, target2 = [0], 0
    nums3, target3 = [-3, -1, 0, 2, 4], 2
    nums4, target4 = [0, 0, 0], 0
    nums5, target5 = [3, 1, 0, -2], 4

    ret00 = solution0.three_sum_smaller(nums0, target0)
    ret01 = solution0.three_sum_smaller(nums1, target1)
    ret02 = solution0.three_sum_smaller(nums2, target2)
    ret03 = solution0.three_sum_smaller(nums3, target3)
    ret04 = solution0.three_sum_smaller(nums4, target4)
    ret05 = solution0.three_sum_smaller(nums5, target5)

    assert ret00 == 2
    assert ret01 == 0
    assert ret02 == 0
    assert ret03 == 6
    assert ret04 == 0
    assert ret05 == 3

    ret10 = solution1.three_sum_smaller(nums0, target0)
    ret11 = solution1.three_sum_smaller(nums1, target1)
    ret12 = solution1.three_sum_smaller(nums2, target2)
    ret13 = solution1.three_sum_smaller(nums3, target3)
    ret14 = solution1.three_sum_smaller(nums4, target4)
    ret15 = solution1.three_sum_smaller(nums5, target5)

    assert ret10 == 2
    assert ret11 == 0
    assert ret12 == 0
    assert ret13 == 6
    assert ret14 == 0
    assert ret15 == 3


def test_smallest_infinite_set():
    obj = smallest_infinite_set.SmallestInfiniteSet()

    obj.add_back(2)
    ret0 = obj.pop_smallest()
    ret1 = obj.pop_smallest()
    ret2 = obj.pop_smallest()

    obj.add_back(1)
    ret3 = obj.pop_smallest()
    ret4 = obj.pop_smallest()
    ret5 = obj.pop_smallest()

    assert ret0 == 1
    assert ret1 == 2
    assert ret2 == 3
    assert ret3 == 1
    assert ret4 == 4
    assert ret5 == 5


def test_query_string():
    solution0 = query_string.Solution0()

    s0, n0 = "0110", 3
    s1, n1 = "0110", 4
    s2, n2 = "1111000101", 5
    s3, n3 = "110101011011000011011111000000", 15
    s4, n4 = "0", 1

    ret0 = solution0.query_string(s0, n0)
    ret1 = solution0.query_string(s1, n1)
    ret2 = solution0.query_string(s2, n2)
    ret3 = solution0.query_string(s3, n3)
    ret4 = solution0.query_string(s4, n4)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True
    assert ret3 is False
    assert ret4 is False

    solution1 = query_string.Solution1()

    s0, n0 = "0110", 3
    s1, n1 = "0110", 4
    s2, n2 = "1111000101", 5
    s3, n3 = "110101011011000011011111000000", 15
    s4, n4 = "0", 1

    ret0 = solution1.query_string(s0, n0)
    ret1 = solution1.query_string(s1, n1)
    ret2 = solution1.query_string(s2, n2)
    ret3 = solution1.query_string(s3, n3)
    ret4 = solution1.query_string(s4, n4)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True
    assert ret3 is False
    assert ret4 is False


def test_range_addition():
    solution = range_addition.Solution()

    length0, updates0 = 5, [[1, 3, 2], [2, 4, 3], [0, 2, -2]]
    length1, updates1 = 10, [[2, 4, 6], [5, 6, 8], [1, 9, -4]]

    ret0 = solution.get_modified_array(length0, updates0)
    ret1 = solution.get_modified_array(length1, updates1)

    assert ret0 == [-2, 0, 3, 5, 3]
    assert ret1 == [0, -4, 2, 2, 2, 4, 4, -4, -4, -4]
