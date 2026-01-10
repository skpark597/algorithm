import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.february.maximum_score_from_removing_stones as maximum_score
import year_twenty_four.february.valid_parenthesis_string as valid_parenthesis_string
import year_twenty_four.february.minimum_increment_to_make_array_unique as min_increment
import year_twenty_four.february.reach_a_number as reach_a_number
import year_twenty_four.february.battleships_in_a_board as battleships_in_a_board


def test_reach_a_number():
    solution0 = reach_a_number.Solution()
    solution1 = reach_a_number.Solution()
    solution2 = reach_a_number.Solution()
    solution3 = reach_a_number.Solution()

    target0, target1, target2, target3 = 2, 3, -2, 8

    result0 = solution0.reach_number(target0)
    result1 = solution1.reach_number(target1)
    result2 = solution2.reach_number(target2)
    result3 = solution3.reach_number(target3)

    assert result0 == 3
    assert result1 == 2
    assert result2 == 3
    assert result3 == 4


def test_maximum_the_confusion():
    solution0 = maximum_score.Solution()
    solution1 = maximum_score.Solution()
    solution2 = maximum_score.Solution()

    a0, b0, c0 = 2, 4, 6
    a1, b1, c1 = 4, 4, 6
    a2, b2, c2 = 1, 8, 8

    result0 = solution0.maximum_score(a0, b0, c0)
    result1 = solution1.maximum_score(a1, b1, c1)
    result2 = solution2.maximum_score(a2, b2, c2)

    assert result0 == 6
    assert result1 == 7
    assert result2 == 8


def test_valid_parenthesis_string():
    solution0 = valid_parenthesis_string.Solution()
    solution1 = valid_parenthesis_string.Solution()
    solution2 = valid_parenthesis_string.Solution()

    s0 = "()"
    s1 = "(*)"
    s2 = "(*))"

    result0 = solution0.check_valid_string(s0)
    result1 = solution1.check_valid_string(s1)
    result2 = solution2.check_valid_string(s2)

    assert result0 is True
    assert result1 is True
    assert result2 is True


def test_min_increment():
    solution0 = min_increment.Solution()
    solution1 = min_increment.Solution()

    nums0 = [1, 2, 2]
    nums1 = [3, 2, 1, 2, 1, 7]

    result0 = solution0.min_increment_for_unique(nums0)
    result1 = solution1.min_increment_for_unique(nums1)

    assert result0 == 1
    assert result1 == 6


def test_count_battleships():
    solution0 = battleships_in_a_board.Solution()
    solution1 = battleships_in_a_board.Solution()
    solution2 = battleships_in_a_board.Solution()

    board0 = [["X", ".", ".", "X"], [".", ".", ".", "X"], [".", ".", ".", "X"]]
    board1 = [["."]]
    board2 = [["X", "X", "X"]]

    result0 = solution0.count_battleships(board0)
    result1 = solution1.count_battleships(board1)
    result2 = solution2.count_battleships(board2)

    assert result0 == 2
    assert result1 == 0
    assert result2 == 1
