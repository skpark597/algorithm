import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_four.march.kth_smallest_prime_fraction as kth_smallest
import year_twenty_four.march.interleaving_string as interleave
import year_twenty_four.march.minimize_maximum_of_array as minimize_array_value


def test_kth_smallest():
    solution0 = kth_smallest.Solution()
    solution1 = kth_smallest.Solution()

    arr0, arr1 = [1, 2, 3, 5], [1, 7]
    k0, k1 = 3, 1

    result0 = solution0.kth_smallest_prime_fraction(arr0, k0)
    result1 = solution1.kth_smallest_prime_fraction(arr1, k1)

    assert result0 == [2, 5]
    assert result1 == [1, 7]


def test_is_interleave():
    solution0 = interleave.Solution()
    solution1 = interleave.Solution()
    solution2 = interleave.Solution()
    solution3 = interleave.Solution()

    s01, s02, s03 = "aabcc", "dbbca", "aadbbcbcac"
    s11, s12, s13 = "aabcc", "dbbca", "aadbbbaccc"
    s21, s22, s23 = "", "", ""
    s31, s32, s33 = "", "", "a"

    result0 = solution0.is_interleave(s01, s02, s03)
    result1 = solution1.is_interleave(s11, s12, s13)
    result2 = solution2.is_interleave(s21, s22, s23)
    result3 = solution3.is_interleave(s31, s32, s33)

    assert result0 is True
    assert result1 is False
    assert result2 is True
    assert result3 is False


def test_minimize_array_value():
    solution0 = minimize_array_value.Solution()
    solution1 = minimize_array_value.Solution()
    solution2 = minimize_array_value.Solution()

    nums0 = [3, 7, 1, 6]
    nums1 = [10, 1]
    nums2 = [6, 9, 3, 8, 14]

    result0 = solution0.minimize_array_value(nums0)
    result1 = solution1.minimize_array_value(nums1)
    result2 = solution2.minimize_array_value(nums2)

    assert result0 == 5
    assert result1 == 10
    assert result2 == 8
