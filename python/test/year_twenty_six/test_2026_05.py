import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_six.may.add_binary as add_binary


def test_add_binary():
    solution = add_binary.Solution()

    a0, b0 = "11", "1"
    a1, b1 = "1010", "1011"

    ret0 = solution.add_binary(a0, b0)
    ret1 = solution.add_binary(a1, b1)

    assert ret0 == "100"
    assert ret1 == "10101"
