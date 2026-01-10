import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
import year_twenty_four.july.minimum_number_of_operations_to_sort_a_binary_tree_by_level as minimum_number_of_operations
import year_twenty_four.july.count_servers_that_communicate as count_servers
import year_twenty_four.july.ransom_note as ransom_note
import year_twenty_four.july.pancake_sorting as pancake_sorting
from common.tree_node import TreeNode


def test_minimum_number_of_operations():
    solution = minimum_number_of_operations.Solution()

    root0 = TreeNode.make([1, 4, 3, 7, 6, 8, 5, None, None, None, None, 9, None, 10])
    root1 = TreeNode.make([1, 3, 2, 7, 6, 5, 4])
    root2 = TreeNode.make([1, 2, 3, 4, 5, 6])

    result0 = solution.minimum_operations(root0)
    result1 = solution.minimum_operations(root1)
    result2 = solution.minimum_operations(root2)

    assert result0 == 3
    assert result1 == 3
    assert result2 == 0


def test_count_servers():
    solution = count_servers.Solution()

    grid0 = [[1, 0], [0, 1]]
    grid1 = [[1, 0], [1, 1]]
    grid2 = [[1, 1, 0, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 0, 1]]

    result0 = solution.count_servers(grid0)
    result1 = solution.count_servers(grid1)
    result2 = solution.count_servers(grid2)

    assert result0 == 0
    assert result1 == 3
    assert result2 == 4

    result0 = solution.count_servers_2(grid0)
    result1 = solution.count_servers_2(grid1)
    result2 = solution.count_servers_2(grid2)

    assert result0 == 0
    assert result1 == 3
    assert result2 == 4


def test_can_construct():
    solution = ransom_note.Solution()

    ransom_note0, magazine0 = "a", "b"
    ransom_note1, magazine1 = "aa", "ab"
    ransom_note2, magazine2 = "aa", "aab"

    result0 = solution.can_construct(ransom_note0, magazine0)
    result1 = solution.can_construct(ransom_note1, magazine1)
    result2 = solution.can_construct(ransom_note2, magazine2)

    assert result0 is False
    assert result1 is False
    assert result2 is True

    result3 = solution.can_construct(ransom_note0, magazine0)
    result4 = solution.can_construct(ransom_note1, magazine1)
    result5 = solution.can_construct(ransom_note2, magazine2)

    assert result3 is False
    assert result4 is False
    assert result5 is True


def test_pancake_sorting():
    soution = pancake_sorting.Solution()

    arr0 = [3, 2, 4, 1]
    arr1 = [1, 2, 3]

    result0 = soution.pancake_sort(arr0)
    result1 = soution.pancake_sort(arr1)

    assert result0 == [3, 4, 2, 3, 2]
    assert result1 == []
