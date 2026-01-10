import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.february.meeting_rooms_ii as meeting_rooms_ii
import year_twenty_five.february.daily_temperatures as daily_temperatures
import year_twenty_five.february.continuous_subarray_sum as check_subarray_sum
import year_twenty_five.february.zigzag_conversion as zigzag_conversion
import year_twenty_five.february.buildings_with_an_ocean_view as buildings_with_an_ocean_view
import year_twenty_five.february.minimum_cost_to_connect_sticks as connect_sticks
import year_twenty_five.february.longest_continuous_subarray_with_absolute_diff_less_than_or_equal_to_limit as longest_subarray
import year_twenty_five.february.meeting_scheduler as meeting_scheduler
import year_twenty_five.february.minimum_insertions_to_balance_a_parentheses_string as min_insertion


def test_check_if_exist():
    solution = meeting_rooms_ii.Solution()

    intervals0 = [[0, 30], [5, 10], [15, 20]]
    intervals1 = [[7, 10], [2, 4]]
    intervals2 = [[1, 4], [7, 9], [0, 6], [2, 3], [5, 8]]
    intervals3 = [[13, 15], [1, 13]]

    result0 = solution.min_meeting_rooms(intervals0)
    result1 = solution.min_meeting_rooms(intervals1)
    result2 = solution.min_meeting_rooms(intervals2)
    result3 = solution.min_meeting_rooms(intervals3)

    assert result0 == 2
    assert result1 == 1
    assert result2 == 3
    assert result3 == 1


def test_daily_temperatures():
    solution = daily_temperatures.Solution()

    temperatures0 = [73, 74, 75, 71, 69, 72, 76, 73]
    temperatures1 = [30, 40, 50, 60]
    temperatures2 = [30, 60, 90]

    result0 = solution.daily_temperatures(temperatures0)
    result1 = solution.daily_temperatures(temperatures1)
    result2 = solution.daily_temperatures(temperatures2)

    assert result0 == [1, 1, 4, 2, 1, 1, 0, 0]
    assert result1 == [1, 1, 1, 0]
    assert result2 == [1, 1, 0]


def test_check_subarray_sum():
    solution = check_subarray_sum.Solution()

    nums0, k0 = [23, 2, 4, 6, 7], 6
    nums1, k1 = [23, 2, 6, 4, 7], 6
    nums2, k2 = [23, 2, 6, 4, 7], 13
    nums3, k3 = [0], 3
    nums4, k4 = [5, 0, 0, 0], 3

    result0 = solution.check_subarray_sum(nums0, k0)
    result1 = solution.check_subarray_sum(nums1, k1)
    result2 = solution.check_subarray_sum(nums2, k2)
    result3 = solution.check_subarray_sum(nums3, k3)
    result4 = solution.check_subarray_sum(nums4, k4)

    assert result0 is True
    assert result1 is True
    assert result2 is False
    assert result3 is False
    assert result4 is True


def test_zigzag_conversion():
    solution = zigzag_conversion.Solution()

    s0, num_rows0 = "PAYPALISHIRING", 3
    s1, num_rows1 = "PAYPALISHIRING", 4
    s2, num_rows2 = "A", 1
    s3, num_rows3 = "ABC", 1

    result0 = solution.convert(s0, num_rows0)
    result1 = solution.convert(s1, num_rows1)
    result2 = solution.convert(s2, num_rows2)
    result3 = solution.convert(s3, num_rows3)

    assert result0 == "PAHNAPLSIIGYIR"
    assert result1 == "PINALSIGYAHRPI"
    assert result2 == "A"
    assert result3 == "ABC"


def test_buildings_with_an_ocean_view():
    solution = buildings_with_an_ocean_view.Solution()

    heights0 = [4, 2, 3, 1]
    heights1 = [4, 3, 2, 1]
    heights2 = [1, 3, 2, 4]

    result0 = solution.find_buildings(heights0)
    result1 = solution.find_buildings(heights1)
    result2 = solution.find_buildings(heights2)

    assert result0 == [0, 2, 3]
    assert result1 == [0, 1, 2, 3]
    assert result2 == [3]


def test_connect_sticks():
    solution = connect_sticks.Solution()

    sticks0 = [2, 4, 3]
    sticks1 = [1, 8, 3, 5]
    sticks2 = [5]
    sticks3 = [3354, 4316, 3259, 4904, 4598, 474, 3166, 6322, 8080, 9009]

    result0 = solution.connect_sticks(sticks0)
    result1 = solution.connect_sticks(sticks1)
    result2 = solution.connect_sticks(sticks2)
    result3 = solution.connect_sticks(sticks3)

    assert result0 == 14
    assert result1 == 30
    assert result2 == 0
    assert result3 == 151646


def test_longest_subarray():
    solution = longest_subarray.Solution()

    nums0, limit0 = [8, 2, 4, 7], 4
    nums1, limit1 = [10, 1, 2, 4, 7, 2], 5
    nums2, limit2 = [4, 2, 2, 2, 4, 4, 2, 2], 0

    result0 = solution.longest_subarray(nums0, limit0)
    result1 = solution.longest_subarray(nums1, limit1)
    result2 = solution.longest_subarray(nums2, limit2)

    assert result0 == 2
    assert result1 == 4
    assert result2 == 3


def test_meeting_scheduler():
    solution = meeting_scheduler.Solution()

    slots01 = [[10, 50], [60, 120], [140, 210]]
    slots02 = [[0, 15], [60, 70]]
    duration0 = 8

    slots11 = [[10, 50], [60, 120], [140, 210]]
    slots12 = [[0, 15], [60, 70]]
    duration1 = 12

    slots21 = [
        [216397070, 363167701],
        [98730764, 158208909],
        [441003187, 466254040],
        [558239978, 678368334],
        [683942980, 717766451],
    ]
    slots22 = [
        [50490609, 222653186],
        [512711631, 670791418],
        [730229023, 802410205],
        [812553104, 891266775],
        [230032010, 399152578],
    ]
    duration2 = 456085

    result0 = solution.min_available_duration(slots01, slots02, duration0)
    result1 = solution.min_available_duration(slots11, slots12, duration1)
    result2 = solution.min_available_duration(slots21, slots22, duration2)

    assert result0 == [60, 68]
    assert result1 == []
    assert result2 == [98730764, 99186849]


def test_min_insertion():
    solution = min_insertion.Solution()

    s0 = "(()))"
    s1 = "())"
    s2 = "))())("
    s3 = "()()()()()("

    result0 = solution.min_insertions(s0)
    result1 = solution.min_insertions(s1)
    result2 = solution.min_insertions(s2)
    result3 = solution.min_insertions(s3)

    assert result0 == 1
    assert result1 == 0
    assert result2 == 3
    assert result3 == 7
