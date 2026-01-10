import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
import year_twenty_three.august.maximum_distance_between_a_pair_of_values as max_distance


def test_partition_string():
    solution0 = max_distance.Solution()
    solution1 = max_distance.Solution()
    solution2 = max_distance.Solution()

    nums01, nums02 = [55, 30, 5, 4, 2], [100, 20, 10, 10, 5]
    nums11, nums12 = [2, 2, 2], [10, 10, 1]
    nums21, nums22 = [30, 29, 19, 5], [25, 25, 25, 25, 25]

    result0 = solution0.max_distance(nums01, nums02)
    result1 = solution1.max_distance(nums11, nums12)
    result2 = solution2.max_distance(nums21, nums22)

    assert result0 == 2
    assert result1 == 1
    assert result2 == 2
