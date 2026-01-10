import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.tree_node import TreeNode
import year_twenty_six.january.isomorphic_strings as isomorphic_strings
import year_twenty_six.january.valid_sudoku as is_valid_sudoku
import year_twenty_six.january.remove_duplicates_from_sorted_array_ii as remove_duplicates
import year_twenty_six.january.best_time_to_buy_and_sell_stock as max_profit
import year_twenty_six.january.binary_tree_right_side_view as right_side_view
import year_twenty_six.january.house_robber as house_robber


def test_isomorphic_strings():
    solution = isomorphic_strings.Solution()

    s0, t0 = "egg", "add"
    s1, t1 = "foo", "bar"
    s2, t2 = "paper", "title"
    s3, t3 = "badc", "baba"

    ret0 = solution.is_isomorphic(s0, t0)
    ret1 = solution.is_isomorphic(s1, t1)
    ret2 = solution.is_isomorphic(s2, t2)
    ret3 = solution.is_isomorphic(s3, t3)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True
    assert ret3 is False


def test_is_valid_sudoku():
    solution = is_valid_sudoku.Solution()
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
    board2 = [
        [".", ".", ".", ".", "5", ".", ".", "1", "."],
        [".", "4", ".", "3", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "3", ".", ".", "1"],
        ["8", ".", ".", ".", ".", ".", ".", "2", "."],
        [".", ".", "2", ".", "7", ".", ".", ".", "."],
        [".", "1", "5", ".", ".", ".", ".", ".", "."],
        [".", ".", ".", ".", ".", "2", ".", ".", "."],
        [".", "2", ".", "9", ".", ".", ".", ".", "."],
        [".", ".", "4", ".", ".", ".", ".", ".", "."],
    ]

    ret0 = solution.is_valid_sudoku(board0)
    ret1 = solution.is_valid_sudoku(board1)
    ret2 = solution.is_valid_sudoku(board2)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is False


def test_remove_duplicates():
    solution = remove_duplicates.Solution()

    nums0 = [1, 1, 1, 2, 2, 3]
    nums1 = [0, 0, 1, 1, 1, 1, 2, 3, 3]

    ret0 = solution.remove_duplicates(nums0)
    ret1 = solution.remove_duplicates(nums1)

    assert ret0 == 5
    assert nums0[:ret0] == [1, 1, 2, 2, 3]

    assert ret1 == 7
    assert nums1[:ret1] == [0, 0, 1, 1, 2, 3, 3]


def test_max_profit():
    solution = max_profit.Solution()

    prices0 = [7, 1, 5, 3, 6, 4]
    prices1 = [7, 6, 4, 3, 2]

    ret0 = solution.max_profit(prices0)
    ret1 = solution.max_profit(prices1)

    assert ret0 == 5
    assert ret1 == 0


def test_right_side_view():
    solution = right_side_view.Solution()

    root0 = TreeNode.make([1, 2, 3, None, 5, None, 4])
    root1 = TreeNode.make([1, 2, 3, 4, None, None, None, 5])
    root2 = TreeNode.make([1, None, 3])
    root3 = TreeNode.make([])

    ret0 = solution.right_side_view(root0)
    ret1 = solution.right_side_view(root1)
    ret2 = solution.right_side_view(root2)
    ret3 = solution.right_side_view(root3)

    assert ret0 == [1, 3, 4]
    assert ret1 == [1, 3, 4, 5]
    assert ret2 == [1, 3]
    assert ret3 == []


def test_house_robber():
    solution = house_robber.Solution()

    nums0 = [1, 2, 3, 1]
    nums1 = [2, 7, 9, 3, 1]

    ret0 = solution.rob(nums0)
    ret1 = solution.rob(nums1)

    assert ret0 == 4
    assert ret1 == 12
