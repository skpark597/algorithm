import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_four.december.diagonal_traverse_ii as diagonal_traverse_ii
import year_twenty_four.december.maximum_distance_in_arrays as maximum_distance_in_arrays
import year_twenty_four.december.zero_array_transformation as zero_array_transformation
import year_twenty_four.december.find_first_and_last_position_of_element_in_sorted_array as find_first_and_last
import year_twenty_four.december.merge_strings_alternately as merge_alternately
import year_twenty_four.december.continuous_subarrays as continuous_subarrays
import year_twenty_four.december.minimum_remove_to_make_valid_parentheses as minimum_remove
import year_twenty_four.december.valid_sudoku as valid_sudoku
import year_twenty_four.december.longest_arithmetic_subsequence_of_given_difference as longest_subsequence
import year_twenty_four.december.product_of_array_except_self as product_except_self


def test_diagonal_traverse_ii():
    solution = diagonal_traverse_ii.Solution()

    nums0 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    nums1 = [[1, 2, 3, 4, 5], [6, 7], [8], [9, 10, 11], [12, 13, 14, 15, 16]]

    result0 = solution.find_diagonal_order(nums0)
    result1 = solution.find_diagonal_order(nums1)

    assert result0 == [1, 4, 2, 7, 5, 3, 8, 6, 9]
    assert result1 == [1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16]


def test_maximum_distance_in_arrays():
    solution = maximum_distance_in_arrays.Solution()

    arrays0 = [[1, 2, 3], [4, 5], [1, 2, 3]]
    arrays1 = [[1], [1]]

    result0 = solution.max_distance(arrays0)
    result1 = solution.max_distance(arrays1)

    assert result0 == 4
    assert result1 == 0


def test_zero_array_transformation():
    solution = zero_array_transformation.Solution()

    nums0 = [1, 0, 1]
    queries0 = [[0, 2]]

    nums1 = [4, 3, 2, 1]
    queries1 = [[1, 3], [0, 2]]

    result0 = solution.is_zero_array(nums0, queries0)
    result1 = solution.is_zero_array(nums1, queries1)

    assert result0 is True
    assert result1 is False


def test_first_and_last():
    solution = find_first_and_last.Solution()

    nums0 = [5, 7, 7, 8, 8, 10]
    target0 = 8

    nums1 = [5, 7, 7, 8, 8, 10]
    target1 = 6

    nums2 = []
    target2 = 0

    result0 = solution.search_range(nums0, target0)
    result1 = solution.search_range(nums1, target1)
    result2 = solution.search_range(nums2, target2)

    assert result0 == [3, 4]
    assert result1 == [-1, -1]
    assert result2 == [-1, -1]


def test_merge_alternately():
    solution = merge_alternately.Solution()

    word01, word02 = "abc", "pqr"
    word11, word12 = "ab", "pqrs"
    word21, word22 = "abcd", "pq"

    result0 = solution.merge_alternately(word01, word02)
    result1 = solution.merge_alternately(word11, word12)
    result2 = solution.merge_alternately(word21, word22)

    assert result0 == "apbqcr"
    assert result1 == "apbqrs"
    assert result2 == "apbqcd"


def test_continuous_subarrays():
    solution = continuous_subarrays.Solution()

    nums0 = [5, 4, 2, 4]
    nums1 = [1, 2, 3]

    result0 = solution.continuous_subarrays_old(nums0)
    result1 = solution.continuous_subarrays_old(nums1)

    assert result0 == 8
    assert result1 == 6


def test_minimum_remove():
    solution = minimum_remove.Solution()

    s0 = "lee(t(c)o)de)"
    s1 = "a)b(c)d"
    s2 = "))(("

    result0 = solution.min_remove_to_make_valid(s0)
    result1 = solution.min_remove_to_make_valid(s1)
    result2 = solution.min_remove_to_make_valid(s2)

    assert result0 == "lee(t(c)o)de"
    assert result1 == "ab(c)d"
    assert result2 == ""


def test_valid_sudoku():
    solution = valid_sudoku.Solution()

    board0 = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]

    board1 = [
        ["8", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]

    result0 = solution.is_valid_sudoku(board0)
    result1 = solution.is_valid_sudoku(board1)

    assert result0 is True
    assert result1 is False


def test_longest_subsequence():
    solution = longest_subsequence.Solution()

    arr0, diff0 = [1, 2, 3, 4], 1
    arr1, diff1 = [1, 3, 5, 7], -1
    arr2, diff2 = [1, 5, 7, 8, 5, 3, 4, 2, 1], -2
    arr3, diff3 = [3, 4, -3, -2, -4], -5
    arr4, diff4 = [4, 12, 10, 0, -2, 7, -8, 9, -9, -12, -12, 8, 8], 0

    result0 = solution.longest_subsequence(arr0, diff0)
    result1 = solution.longest_subsequence(arr1, diff1)
    result2 = solution.longest_subsequence(arr2, diff2)
    result3 = solution.longest_subsequence(arr3, diff3)
    result4 = solution.longest_subsequence(arr4, diff4)

    assert result0 == 4
    assert result1 == 1
    assert result2 == 4
    assert result3 == 2
    assert result4 == 2


def test_product_except_self():
    solution = product_except_self.Solution()

    nums0 = [1, 2, 3, 4]
    nums1 = [-1, 1, 0, -3, 3]

    result0 = solution.product_except_self(nums0)
    result1 = solution.product_except_self(nums1)

    assert result0 == [24, 12, 8, 6]
    assert result1 == [0, 0, 9, 0, 0]
