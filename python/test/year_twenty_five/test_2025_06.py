import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.june.remove_stones_to_minimize_the_total as min_stone_sum
import year_twenty_five.june.kth_smallest_subarray_sum as kth_smallest_subarray_sum


def test_min_stone_sum():
    solution = min_stone_sum.Solution()

    piles0, k0 = [5, 4, 9], 2
    piles1, k1 = [4, 3, 6, 7], 3

    result0 = solution.min_stone_sum(piles0, k0)
    result1 = solution.min_stone_sum(piles1, k1)

    assert result0 == 12
    assert result1 == 12


def test_kth_smallest_subarray_sum():
    solution = kth_smallest_subarray_sum.Solution()

    nums0, k0 = [2, 1, 3], 4
    nums1, k1 = [3, 3, 5, 5], 7
    nums2, k2 = [2, 1, 3], 1

    result0 = solution.kth_smallest_subarray_sum(nums0, k0)
    result1 = solution.kth_smallest_subarray_sum(nums1, k1)
    result2 = solution.kth_smallest_subarray_sum(nums2, k2)

    assert result0 == 3
    assert result1 == 10
    assert result2 == 1
