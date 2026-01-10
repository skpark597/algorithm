import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.tree_node import TreeNode
from common.util import is_same_double_arrays_ignoring_order
import year_twenty_five.march.evaluate_reverse_polish_notation as eval_rpn
import year_twenty_five.march.simplify_path as simplify_path
import year_twenty_five.march.surrounded_regions as surrounded_regions
import year_twenty_five.march.rotate_array as rotate_array
import year_twenty_five.march.reverse_words_in_a_string as reverse_words
import year_twenty_five.march.single_number_ii as single_number
import year_twenty_five.march.bitwise_and_of_numbers_range as range_bitwise_and
import year_twenty_five.march.game_of_life as game_of_life
import year_twenty_five.march.find_k_pairs_with_smallest_sums as k_smallest_pairs
import year_twenty_five.march.rotate_image as rotate_image
import year_twenty_five.march.insert_delete_get_random_o1 as insert_delete_get_random_o1
import year_twenty_five.march.validate_binary_search_tree as is_valid_bst


def test_eval_rpn():
    solution = eval_rpn.Solution()

    tokens0 = ["2", "1", "+", "3", "*"]
    tokens1 = ["4", "13", "5", "/", "+"]
    tokens2 = ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]

    result0 = solution.eval_rpn(tokens0)
    result1 = solution.eval_rpn(tokens1)
    result2 = solution.eval_rpn(tokens2)

    assert result0 == 9
    assert result1 == 6
    assert result2 == 22


def test_simplify_path():
    solution = simplify_path.Solution()

    path0 = "/home/"
    path1 = "/home//foo/"
    path2 = "/home/user/Documents/../Pictures"
    path3 = "/../"
    path4 = "/.../a/../b/c/../d/./"

    result0 = solution.simplify_path(path0)
    result1 = solution.simplify_path(path1)
    result2 = solution.simplify_path(path2)
    result3 = solution.simplify_path(path3)
    result4 = solution.simplify_path(path4)

    assert result0 == "/home"
    assert result1 == "/home/foo"
    assert result2 == "/home/user/Pictures"
    assert result3 == "/"
    assert result4 == "/.../b/d"


def test_surrounded_regions():
    solution = surrounded_regions.Solution()

    board0 = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    board1 = [["X"]]
    board2 = [["O", "X", "O"], ["X", "O", "X"], ["O", "X", "O"]]

    solution.solve(board0)
    solution.solve(board1)
    solution.solve(board2)

    assert board0 == [["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "X", "X", "X"], ["X", "O", "X", "X"]]
    assert board1 == [["X"]]
    assert board2 == [["O", "X", "O"], ["X", "X", "X"], ["O", "X", "O"]]


def test_rotate_array():
    solution = rotate_array.Solution()

    nums0, k0 = [1, 2, 3, 4, 5, 6, 7], 3
    nums1, k1 = [-1, -100, 3, 99], 2

    solution.rotate(nums0, k0)
    solution.rotate(nums1, k1)

    assert nums0 == [5, 6, 7, 1, 2, 3, 4]
    assert nums1 == [3, 99, -1, -100]


def test_reverse_words():
    solution = reverse_words.Solution()

    s0 = "the sky is blue"
    s1 = "  hello world  "
    s2 = "a good   example"

    result0 = solution.reverse_words(s0)
    result1 = solution.reverse_words(s1)
    result2 = solution.reverse_words(s2)

    assert result0 == "blue is sky the"
    assert result1 == "world hello"
    assert result2 == "example good a"


def test_single_number():
    solution = single_number.Solution()

    nums0 = [2, 2, 3, 2]
    nums1 = [0, 1, 0, 1, 0, 1, 99]

    # result0 = solution.single_number(nums0)
    # result1 = solution.single_number(nums1)

    result0 = solution.single_number_sort(nums0)
    result1 = solution.single_number_sort(nums1)

    assert result0 == 3
    assert result1 == 99


def test_range_bitwise_and():
    solution = range_bitwise_and.Solution()

    left0, right0 = 5, 7
    left1, right1 = 0, 0
    left2, right2 = 1, 2147483647
    left3, right3 = 2, 2

    result0 = solution.range_bitwise_and(left0, right0)
    result1 = solution.range_bitwise_and(left1, right1)
    result2 = solution.range_bitwise_and(left2, right2)
    result3 = solution.range_bitwise_and(left3, right3)

    assert result0 == 4
    assert result1 == 0
    assert result2 == 0
    assert result3 == 2


def test_game_of_life():
    solution = game_of_life.Solution()

    board0 = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    board1 = [[1, 1], [1, 0]]

    solution.game_of_life(board0)
    solution.game_of_life(board1)

    assert board0 == [[0, 0, 0], [1, 0, 1], [0, 1, 1], [0, 1, 0]]
    assert board1 == [[1, 1], [1, 1]]


def test_k_smallest_pairs():
    solution = k_smallest_pairs.Solution()

    nums01, nums02, k0 = [1, 7, 11], [2, 4, 6], 3
    nums11, nums12, k1 = [1, 1, 2], [1, 2, 3], 2
    nums21, nums22, k2 = [0, 0, 0, 0, 0], [-3, 22, 35, 56, 76], 22

    result0 = solution.k_smallest_pairs(nums01, nums02, k0)
    result1 = solution.k_smallest_pairs(nums11, nums12, k1)
    result2 = solution.k_smallest_pairs(nums21, nums22, k2)

    # fmt: off
    assert is_same_double_arrays_ignoring_order(result0, [[1, 2], [1, 4], [1, 6]])
    assert is_same_double_arrays_ignoring_order(result1, [[1, 1], [1, 1]])
    assert is_same_double_arrays_ignoring_order(result2, [[0, -3],[0, -3],[0, -3],[0, -3],[0, -3],[0, 22],[0, 22],[0, 22],[0, 22],[0, 22],[0, 35],[0, 35],[0, 35],[0, 35],[0, 35],[0, 56],[0, 56],[0, 56],[0, 56],[0, 56],[0, 76],[0, 76]])


def test_rotate_image():
    solution = rotate_image.Solution()

    matrix0 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    matrix1 = [[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]]

    solution.rotate(matrix0)
    solution.rotate(matrix1)

    assert matrix0 == [[7, 4, 1], [8, 5, 2], [9, 6, 3]]
    assert matrix1 == [[15, 13, 2, 5], [14, 3, 4, 1], [12, 6, 8, 9], [16, 7, 10, 11]]


def test_insert_delete_random_o1():
    solution = insert_delete_get_random_o1.RandomizedSet()

    result0 = solution.insert(0)
    result1 = solution.insert(1)
    result2 = solution.insert(1)

    result3 = solution.remove(0)
    result4 = solution.insert(2)
    result5 = solution.remove(1)
    result6 = solution.remove(1)

    result7 = solution.get_random()

    assert result0 is True
    assert result1 is True
    assert result2 is False

    assert result3 is True
    assert result4 is True
    assert result5 is True
    assert result6 is False

    assert result7 == 2


def test_is_valid_bst():
    solution = is_valid_bst.Solution()

    root0 = TreeNode.make([2, 1, 3])
    root1 = TreeNode.make([5, 1, 4, None, None, 3, 6])
    root2 = TreeNode.make([5, 4, 6, None, None, 3, 7])

    result0 = solution.is_valid_bst(root0)
    result1 = solution.is_valid_bst(root1)
    result2 = solution.is_valid_bst(root2)

    assert result0 is True
    assert result1 is False
    assert result2 is False
