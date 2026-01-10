import sys
from os.path import abspath, dirname, join


SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
from common.tree_node import TreeNode
import year_twenty_four.september.flower_planting_with_no_adjacent as flower_planting_with_no_adjacent
import year_twenty_four.september.count_numbers_with_unique_digits as count_numbers_with_unique_digits
import year_twenty_four.september.find_132_pattern as find_132_pattern
import year_twenty_four.september.swap_for_longest_repeated_character_substring as swap_for_longest_repeated_character_substring
import year_twenty_four.september.leaf_similar_trees as leaf_similar_trees
import year_twenty_four.september.find_target_indices_after_sorting_array as target_indices
import year_twenty_four.september.plus_one as plus_one
import year_twenty_four.september.edit_distance as edit_distance


def test_garden_no_adj():
    solution = flower_planting_with_no_adjacent.Solution()

    n0, paths0 = 3, [[1, 2], [2, 3], [3, 1]]
    n1, paths1 = 4, [[1, 2], [3, 4]]
    n2, paths2 = 4, [[1, 2], [2, 3], [3, 4], [4, 1], [1, 3], [2, 4]]
    n3, paths3 = 1, []
    n4, paths4 = 8, [[7, 4], [3, 7], [1, 5], [5, 4], [7, 1], [3, 1], [4, 3], [6, 5]]

    result0 = solution.garden_no_adj(n0, paths0)
    result1 = solution.garden_no_adj(n1, paths1)
    result2 = solution.garden_no_adj(n2, paths2)
    result3 = solution.garden_no_adj(n3, paths3)
    result4 = solution.garden_no_adj(n4, paths4)

    assert result0 == [1, 2, 3]
    assert result1 == [1, 2, 1, 2]
    assert result2 == [1, 2, 3, 4]
    assert result3 == [1]
    assert result4 == [1, 1, 2, 1, 2, 1, 3, 1]


def test_count_numbers_with_unique_digits():
    solution = count_numbers_with_unique_digits.Solution()

    n0 = 2
    n1 = 0
    n2 = 3

    result0 = solution.count_numbers_with_unique_digits(n0)
    result1 = solution.count_numbers_with_unique_digits(n1)
    result2 = solution.count_numbers_with_unique_digits(n2)

    assert result0 == 91
    assert result1 == 1
    assert result2 == 739


def test_find_132_pattern():
    solution = find_132_pattern.Solution()

    nums0 = [1, 2, 3, 4]
    nums1 = [3, 1, 4, 2]
    nums2 = [-1, 3, 2, 0]
    nums3 = [3, 5, 0, 3, 4]
    nums4 = [1, 0, 1, -4, -3]
    nums5 = [1, 4, 0, -1, -2, -3, -1, -2]

    result0 = solution.find_132_pattern(nums0)
    result1 = solution.find_132_pattern(nums1)
    result2 = solution.find_132_pattern(nums2)
    result3 = solution.find_132_pattern(nums3)
    result4 = solution.find_132_pattern(nums4)
    result5 = solution.find_132_pattern(nums5)

    assert result0 is False
    assert result1 is True
    assert result2 is True
    assert result3 is True
    assert result4 is False
    assert result5 is True


def test_swap_for_longest_repeated_character_substring():
    solution = swap_for_longest_repeated_character_substring.Solution()

    text0 = "ababa"
    text1 = "aaabaaa"
    text2 = "aaaaa"

    result0 = solution.max_rep_opt1(text0)
    result1 = solution.max_rep_opt1(text1)
    result2 = solution.max_rep_opt1(text2)

    assert result0 == 3
    assert result1 == 6
    assert result2 == 5


def test_leaf_similar_trees():
    solution = leaf_similar_trees.Solution()

    root00 = TreeNode.make([3, 5, 1, 6, 2, 9, 8, None, None, 7, 4])
    root01 = TreeNode.make([3, 5, 1, 6, 7, 4, 2, None, None, None, None, None, None, 9, 8])

    root10 = TreeNode.make([1, 2, 3])
    root11 = TreeNode.make([1, 3, 2])

    result0 = solution.leaf_similar(root00, root01)
    result1 = solution.leaf_similar(root10, root11)

    assert result0 is True
    assert result1 is False


def test_target_indices():
    solution = target_indices.Solution()

    nums0, target0 = [1, 2, 5, 2, 3], 2
    nums1, target1 = [1, 2, 5, 2, 3], 3
    nums2, target2 = [1, 2, 5, 2, 3], 5

    result0 = solution.target_indices(nums0, target0)
    result1 = solution.target_indices(nums1, target1)
    result2 = solution.target_indices(nums2, target2)

    assert result0 == [1, 2]
    assert result1 == [3]
    assert result2 == [4]


def test_plus_one():
    solution = plus_one.Solution()

    digits0 = [1, 2, 3]
    digits1 = [4, 3, 2, 1]
    digits2 = [9]

    result0 = solution.plus_one(digits0)
    result1 = solution.plus_one(digits1)
    result2 = solution.plus_one(digits2)

    assert result0 == [1, 2, 4]
    assert result1 == [4, 3, 2, 2]
    assert result2 == [1, 0]


def test_edit_distance():
    solution = edit_distance.Solution()

    word00, word01 = "horse", "ros"
    word10, word11 = "intention", "execution"
    word20, word21 = "", "a"

    result0 = solution.min_distance(word00, word01)
    result1 = solution.min_distance(word10, word11)
    result2 = solution.min_distance(word20, word21)

    assert result0 == 3
    assert result1 == 5
    assert result2 == 1
