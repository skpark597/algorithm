import sys
from os.path import abspath, dirname, join
from unittest import result


SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
from common.util import is_same_arrays_ignoring_order
import year_twenty_four.october.distant_barcodes as distant_barcodes
import year_twenty_four.october.substring_with_concatenation_of_all_words as find_substring
import year_twenty_four.october.car_pooling as car_pooling
import year_twenty_four.october.heaters as heaters


def test_distant_barcodes():
    solution = distant_barcodes.Solution()

    barcodes0 = [1, 1, 1, 2, 2, 2]
    barcodes1 = [1, 1, 1, 1, 2, 2, 3, 3]

    result0 = solution.rearrange_barcodes(barcodes0)
    result1 = solution.rearrange_barcodes(barcodes1)

    assert result0 == [1, 2, 1, 2, 1, 2]
    assert result1 == [1, 2, 1, 3, 1, 2, 1, 3]


def test_find_substring():
    solution = find_substring.Solution()

    s0 = "barfoothefoobarman"
    words0 = ["foo", "bar"]

    s1 = "wordgoodgoodgoodbestword"
    words1 = ["word", "good", "best", "word"]

    s2 = "barfoofoobarthefoobarman"
    words2 = ["bar", "foo", "the"]

    s3 = "wordgoodgoodgoodbestword"
    words3 = ["word", "good", "best", "good"]

    s4 = "aaaaaaaa"
    words4 = ["aa", "aa", "aa"]

    result0 = solution.find_substring(s0, words0)
    result1 = solution.find_substring(s1, words1)
    result2 = solution.find_substring(s2, words2)
    result3 = solution.find_substring(s3, words3)
    result4 = solution.find_substring(s4, words4)

    compare0 = is_same_arrays_ignoring_order(result0, [0, 9])
    compare1 = is_same_arrays_ignoring_order(result1, [])
    compare2 = is_same_arrays_ignoring_order(result2, [6, 9, 12])
    compare3 = is_same_arrays_ignoring_order(result3, [8])
    compare4 = is_same_arrays_ignoring_order(result4, [0, 1, 2])

    assert compare0
    assert compare1
    assert compare2
    assert compare3
    assert compare4


def test_car_pooling():
    solution = car_pooling.Solution()

    trips0, capacity0 = [[2, 1, 5], [3, 3, 7]], 4
    trips1, capacity1 = [[2, 1, 5], [3, 3, 7]], 5
    trips2, capacity2 = [[2, 1, 5], [3, 5, 7]], 3
    trips3, capacity3 = [[3, 2, 8], [4, 4, 6], [10, 8, 9]], 11

    result0 = solution.car_pooling(trips0, capacity0)
    result1 = solution.car_pooling(trips1, capacity1)
    result2 = solution.car_pooling(trips2, capacity2)
    result3 = solution.car_pooling(trips3, capacity3)

    assert result0 is False
    assert result1 is True
    assert result2 is True
    assert result3 is True


def test_heaters():
    solution = heaters.Solution()

    houses0, heaters0 = [1, 2, 3], [2]
    houses1, heaters1 = [1, 2, 3, 4], [1, 4]
    houses2, heaters2 = [1, 5], [2]

    result0 = solution.find_radius(houses0, heaters0)
    result1 = solution.find_radius(houses1, heaters1)
    result2 = solution.find_radius(houses2, heaters2)

    assert result0 == 1
    assert result1 == 1
    assert result2 == 3
