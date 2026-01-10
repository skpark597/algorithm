import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.august.before_and_after_puzzle as before_and_after_puzzle
import year_twenty_five.august.frequency_of_the_most_frequent_element as max_frequency
import year_twenty_five.august.greatest_sum_divisible_by_three as max_sum_div_three


def test_before_and_after_puzzles():
    solution = before_and_after_puzzle.Solution()

    phrases0 = ["writing code", "code rocks"]
    phrases1 = [
        "mission statement",
        "a quick bite to eat",
        "a chip off the old block",
        "chocolate bar",
        "mission impossible",
        "a man on a mission",
        "block party",
        "eat my words",
        "bar of soap",
    ]
    phrases2 = ["a", "b", "a"]

    ret0 = solution.beforeAndAfterPuzzles(phrases0)
    ret1 = solution.beforeAndAfterPuzzles(phrases1)
    ret2 = solution.beforeAndAfterPuzzles(phrases2)

    assert ret0 == ["writing code rocks"]
    assert ret1 == [
        "a chip off the old block party",
        "a man on a mission impossible",
        "a man on a mission statement",
        "a quick bite to eat my words",
        "chocolate bar of soap",
    ]
    assert ret2 == ["a"]


def test_max_sum_div_three():
    solution = max_sum_div_three.Solution()

    nums0 = [3, 6, 5, 1, 8]
    nums1 = [4]
    nums2 = [1, 2, 3, 4, 4]

    ret0 = solution.maxSumDivThree(nums0)
    ret1 = solution.maxSumDivThree(nums1)
    ret2 = solution.maxSumDivThree(nums2)

    assert ret0 == 18
    assert ret1 == 0
    assert ret2 == 12


def test_max_frequency():
    solution = max_frequency.Solution()

    nums0, k0 = [1, 2, 4], 5
    nums1, k1 = [1, 4, 8, 13], 5
    nums2, k2 = [3, 9, 6], 2

    # fmt: off
    nums3, k3 = [9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966], 3056
    # fmt: on

    ret0 = solution.max_frequency(nums0, k0)
    ret1 = solution.max_frequency(nums1, k1)
    ret2 = solution.max_frequency(nums2, k2)
    ret3 = solution.max_frequency(nums3, k3)

    assert ret0 == 3
    assert ret1 == 2
    assert ret2 == 1
    assert ret3 == 73
