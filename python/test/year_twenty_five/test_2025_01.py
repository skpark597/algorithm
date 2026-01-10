import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.january.check_completeness_of_a_binary_tree as is_complete_tree
import year_twenty_five.january.check_if_n_and_its_double_exist as check_if_exist
import year_twenty_five.january.count_univalue_subtrees as count_univalue_subtrees
import year_twenty_five.january.flip_columns_for_maximum_number_of_equal_rows as max_equal_rows_after_flips
import year_twenty_five.january.greatest_common_divisor_of_strings as gcd_of_strings
import year_twenty_five.january.linked_list_components as num_components
import year_twenty_five.january.make_the_prefix_sum_non_negative as make_pref_sum_nonnegative
import year_twenty_five.january.maximum_size_subarray_sum_equals_k as max_sub_array_len
import year_twenty_five.january.remove_nth_node_from_end_of_list as remove_nth_from_end
import year_twenty_five.january.set_matrix_zeroes as set_zeroes
import year_twenty_five.january.shortest_path_in_binary_matrix as shortest_path_binary_matrix
import year_twenty_five.january.sliding_window_maximum as max_sliding_window
import year_twenty_five.january.walls_and_gates as walls_and_gates
import year_twenty_five.january.word_pattern_ii as word_patter_match
import year_twenty_five.january.word_subsets as word_subsets
from common.list_node import ListNode
from common.tree_node import TreeNode
from common.util import is_same_list_nodes


def test_check_if_exist():
    solution = check_if_exist.Solution()

    arr0 = [10, 2, 5, 3]
    arr1 = [3, 1, 7, 11]
    arr2 = [-2, 0, 10, -19, 4, 6, -8]

    result0 = solution.check_if_exist(arr0)
    result1 = solution.check_if_exist(arr1)
    result2 = solution.check_if_exist(arr2)

    assert result0 is True
    assert result1 is False
    assert result2 is False


def test_remove_nth_from_end():
    solution = remove_nth_from_end.Solution()

    head0, n0 = ListNode.make([1, 2, 3, 4, 5]), 2
    head1, n1 = ListNode.make([1]), 1
    head2, n2 = ListNode.make([1, 2]), 1

    result0 = solution.remove_nth_from_end(head0, n0)
    result1 = solution.remove_nth_from_end(head1, n1)
    result2 = solution.remove_nth_from_end(head2, n2)

    assert is_same_list_nodes(result0, ListNode.make([1, 2, 3, 5]))
    assert is_same_list_nodes(result1, ListNode.make([]))
    assert is_same_list_nodes(result2, ListNode.make([1]))


def test_num_componentes():
    solution = num_components.Solution()

    head0, nums0 = ListNode.make([0, 1, 2, 3]), [0, 1, 3]
    head1, nums1 = ListNode.make([0, 1, 2, 3, 4]), [0, 3, 1, 4]

    result0 = solution.num_components(head0, nums0)
    result1 = solution.num_components(head1, nums1)

    assert result0 == 2
    assert result1 == 2


def test_max_sliding_window():
    solution = max_sliding_window.Solution()

    nums0, k0 = [1, 3, -1, -3, 5, 3, 6, 7], 3
    nums1, k1 = [1], 1
    nums2, k2 = [3, 3, -1, -3, 5, 7, 6, 7, 7], 3

    result0 = solution.max_sliding_window(nums0, k0)
    result1 = solution.max_sliding_window(nums1, k1)
    result2 = solution.max_sliding_window(nums2, k2)

    assert result0 == [3, 3, 5, 5, 6, 7]
    assert result1 == [1]
    assert result2 == [3, 3, 5, 7, 7, 7, 7]


def test_max_sub_array_len():
    solution = max_sub_array_len.Solution()

    nums0, k0 = [1, -1, 5, -2, 3], 3
    nums1, k1 = [-2, -1, 2, 1], 1

    result0 = solution.max_sub_array_len(nums0, k0)
    result1 = solution.max_sub_array_len(nums1, k1)

    assert result0 == 4
    assert result1 == 2


def test_is_complete_tree():
    solution = is_complete_tree.Solution()

    root0 = TreeNode.make([1, 2, 3, 4, 5, 6])
    root1 = TreeNode.make([1, 2, 3, 4, 5, None, 7])
    root2 = TreeNode.make([1, 2, 3, 5, None, 7, 8])
    root3 = TreeNode.make([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, None, None, 15])

    result0 = solution.is_complete_tree(root0)
    result1 = solution.is_complete_tree(root1)
    result2 = solution.is_complete_tree(root2)
    result3 = solution.is_complete_tree(root3)

    assert result0 is True
    assert result1 is False
    assert result2 is False
    assert result3 is False


def test_word_pattern_match():
    solution = word_patter_match.Solution()

    pattern0, s0 = "abab", "redblueredblue"
    pattern1, s1 = "aaaa", "asdasdasdasd"
    pattern2, s2 = "aabb", "xyzabcxzyabc"
    pattern3, s3 = "ab", "aa"

    result0 = solution.word_pattern_match(pattern0, s0)
    result1 = solution.word_pattern_match(pattern1, s1)
    result2 = solution.word_pattern_match(pattern2, s2)
    result3 = solution.word_pattern_match(pattern3, s3)

    assert result0 is True
    assert result1 is True
    assert result2 is False
    assert result3 is False


def test_gcd_of_strings():
    solution = gcd_of_strings.Solution()

    str00, str01 = "ABCABC", "ABC"
    str10, str11 = "ABABAB", "ABAB"
    str20, str21 = "LEET", "CODE"

    result0 = solution.gcd_of_strings(str00, str01)
    result1 = solution.gcd_of_strings(str10, str11)
    result2 = solution.gcd_of_strings(str20, str21)

    assert result0 == "ABC"
    assert result1 == "AB"
    assert result2 == ""


def test_word_subsets():
    solution = word_subsets.Solution()

    words01, words02 = ["amazon", "apple", "facebook", "google", "leetcode"], ["e", "o"]
    words11, words12 = ["amazon", "apple", "facebook", "google", "leetcode"], ["lc", "eo"]
    words21, words22 = ["acaac", "cccbb", "aacbb", "caacc", "bcbbb"], ["c", "cc", "b"]
    words31, words32 = ["amazon", "apple", "facebook", "google", "leetcode"], ["lo", "eo"]

    result0 = solution.word_subsets(words01, words02)
    result1 = solution.word_subsets(words11, words12)
    result2 = solution.word_subsets(words21, words22)
    result3 = solution.word_subsets(words31, words32)

    assert result0 == ["facebook", "google", "leetcode"]
    assert result1 == ["leetcode"]
    assert result2 == ["cccbb"]
    assert result3 == ["google", "leetcode"]


def test_shortest_path_binary_matrix():
    solution = shortest_path_binary_matrix.Solution()

    grid0 = [[0, 1], [1, 0]]
    grid1 = [[0, 0, 0], [1, 1, 0], [1, 1, 0]]
    grid2 = [[1, 0, 0], [1, 1, 0], [1, 1, 0]]
    grid3 = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]

    result0 = solution.shortest_path_binary_matrix(grid0)
    result1 = solution.shortest_path_binary_matrix(grid1)
    result2 = solution.shortest_path_binary_matrix(grid2)
    result3 = solution.shortest_path_binary_matrix(grid3)

    assert result0 == 2
    assert result1 == 4
    assert result2 == -1
    assert result3 == 4


def test_set_zeroes():
    solution = set_zeroes.Solution()

    matrix0 = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
    matrix1 = [[0, 1, 2, 0], [3, 4, 5, 2], [1, 3, 1, 5]]
    matrix2 = [[1, 2, 3, 4], [5, 0, 7, 8], [0, 10, 11, 12], [13, 14, 15, 0]]

    solution.set_zeroes(matrix0)
    solution.set_zeroes(matrix1)
    solution.set_zeroes(matrix2)

    assert matrix0 == [[1, 0, 1], [0, 0, 0], [1, 0, 1]]
    assert matrix1 == [[0, 0, 0, 0], [0, 4, 5, 0], [0, 3, 1, 0]]
    assert matrix2 == [[0, 0, 3, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]


def test_count_univalue_subtrees():
    solution = count_univalue_subtrees.Solution()

    root0 = TreeNode.make([5, 1, 5, 5, 5, None, 5])
    root1 = TreeNode.make([])
    root2 = TreeNode.make([5, 5, 5, 5, 5, None, 5])
    root3 = TreeNode.make([1, 1, 1, 5, 5, None, 5])

    result0 = solution.count_unival_subtrees(root0)
    result1 = solution.count_unival_subtrees(root1)
    result2 = solution.count_unival_subtrees(root2)
    result3 = solution.count_unival_subtrees(root3)

    assert result0 == 4
    assert result1 == 0
    assert result2 == 6
    assert result3 == 3


def test_make_pref_sum_nonnegative():
    solution = make_pref_sum_nonnegative.Solution()

    nums0 = [2, 3, -5, 4]
    nums1 = [3, -5, -2, 6]
    nums2 = [6, -6, -3, 3, 1, 5, -4, -3, -2, -3, 4, -1, 4, 4, -2, 6, 0]

    result0 = solution.make_pref_sum_nonnegative(nums0)
    result1 = solution.make_pref_sum_nonnegative(nums1)
    result2 = solution.make_pref_sum_nonnegative(nums2)

    assert result0 == 0
    assert result1 == 1
    assert result2 == 1


def test_max_equal_rows_after_flips():
    solution = max_equal_rows_after_flips.Solution()

    matrix0 = [[0, 1], [1, 1]]
    matrix1 = [[0, 1], [1, 0]]
    matrix2 = [[0, 0, 0], [0, 0, 1], [1, 1, 0]]

    result0 = solution.max_equal_rows_after_flips(matrix0)
    result1 = solution.max_equal_rows_after_flips(matrix1)
    result2 = solution.max_equal_rows_after_flips(matrix2)

    assert result0 == 1
    assert result1 == 2
    assert result2 == 2


def test_walls_and_gates():
    solution = walls_and_gates.Solution()

    rooms0 = [
        [2147483647, -1, 0, 2147483647],
        [2147483647, 2147483647, 2147483647, -1],
        [2147483647, -1, 2147483647, -1],
        [0, -1, 2147483647, 2147483647],
    ]
    rooms1 = [[-1]]

    solution.walls_and_gates(rooms0)
    solution.walls_and_gates(rooms1)

    assert rooms0 == [[3, -1, 0, 1], [2, 2, 1, -1], [1, -1, 2, -1], [0, -1, 3, 4]]
    assert rooms1 == [[-1]]
