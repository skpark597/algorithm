import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.util import is_same_double_arrays_ignoring_order
import year_twenty_six.may.add_binary as add_binary
import year_twenty_six.may.combination_sum as combination_sum


def test_add_binary():
    solution = add_binary.Solution()

    a0, b0 = "11", "1"
    a1, b1 = "1010", "1011"

    ret0 = solution.add_binary(a0, b0)
    ret1 = solution.add_binary(a1, b1)

    assert ret0 == "100"
    assert ret1 == "10101"


def test_combination_sum():
    solution = combination_sum.Solution()

    candidates0 = [2, 3, 6, 7]
    candidates1 = [2, 3, 5]
    candidates2 = [2]

    target0 = 7
    target1 = 8
    target2 = 1

    ret0 = solution.combination_sum(candidates0, target0)
    ret1 = solution.combination_sum(candidates1, target1)
    ret2 = solution.combination_sum(candidates2, target2)

    ans0 = [[2, 2, 3], [7]]
    ans1 = [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
    ans2 = []

    assert is_same_double_arrays_ignoring_order(ret0, ans0)
    assert is_same_double_arrays_ignoring_order(ret1, ans1)
    assert is_same_double_arrays_ignoring_order(ret2, ans2)
