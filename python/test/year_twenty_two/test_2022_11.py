import sys
from os.path import dirname, abspath, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
import year_twenty_two.november.target_sum as target_sum
import year_twenty_two.november.split_array_into_consecutive_subsequences as subsequences
import year_twenty_two.november.number_of_substrings_containing_all_three_characters as chars
import year_twenty_two.november.maximum_total_importance_of_roads as importance_of_roads
import year_twenty_two.november.find_common_characters as common_characters
import year_twenty_two.november.circular_permutation_in_binary_representation as representation
import year_twenty_two.november.count_number_of_nice_subarrays as number_of_nice_subarrays
import year_twenty_two.november.count_number_of_nice_subarrays_again as subarrays_again
import year_twenty_two.november.validate_stack_sequences as stack_sequences


def test_target_sum():
    nums0 = [1, 1, 1, 1, 1]
    nums1 = [1]
    nums2 = [1, 0]
    nums3 = [0, 0, 0, 0, 0, 0, 0, 0, 1]
    nums4 = [1, 999]

    target0 = 3
    target1 = 1
    target2 = 1
    target3 = 1
    target4 = 998

    solution0 = target_sum.Solution()
    solution1 = target_sum.Solution()
    solution2 = target_sum.Solution()
    solution3 = target_sum.Solution()
    solution4 = target_sum.Solution()

    result0 = solution0.find_target_sum_ways(nums0, target0)
    result1 = solution1.find_target_sum_ways(nums1, target1)
    result2 = solution2.find_target_sum_ways(nums2, target2)
    result3 = solution3.find_target_sum_ways(nums3, target3)
    result4 = solution4.find_target_sum_ways(nums4, target4)

    assert result0 == 5
    assert result1 == 1
    assert result2 == 2
    assert result3 == 256
    assert result4 == 1


def test_split_array_into_consecutive_subsequences():
    nums0 = [1, 2, 3, 3, 4, 5]
    nums1 = [1, 2, 3, 3, 4, 4, 5, 5]
    nums2 = [1, 2, 3, 4, 4, 5]

    solution0 = subsequences.Solution()
    solution1 = subsequences.Solution()
    solution2 = subsequences.Solution()

    answer0 = solution0.is_possible(nums0)
    answer1 = solution1.is_possible(nums1)
    answer2 = solution2.is_possible(nums2)

    assert answer0 is True
    assert answer1 is True
    assert answer2 is False


def test_number_of_substrings_containing_all_three_characters():
    string0 = "abcabc"
    string1 = "aaacb"
    string2 = "abc"
    string3 = "ababbbc"

    solution0 = chars.Solution()
    solution1 = chars.Solution()
    solution2 = chars.Solution()
    solution3 = chars.Solution()

    answer0 = solution0.number_of_substrings(string0)
    answer1 = solution1.number_of_substrings(string1)
    answer2 = solution2.number_of_substrings(string2)
    answer3 = solution3.number_of_substrings(string3)

    assert answer0 == 10
    assert answer1 == 3
    assert answer2 == 1
    assert answer3 == 3


def test_maximum_total_importance_of_roads():
    n0 = 5
    n1 = 5
    n2 = 5

    roads0 = [[0, 1], [1, 2], [2, 3], [0, 2], [1, 3], [2, 4]]
    roads1 = [[0, 3], [2, 4], [1, 3]]
    roads2 = [[0, 1]]

    solution0 = importance_of_roads.Solution()
    solution1 = importance_of_roads.Solution()
    solution2 = importance_of_roads.Solution()

    result0 = solution0.maximum_importance(n0, roads0)
    result1 = solution1.maximum_importance(n1, roads1)
    result2 = solution2.maximum_importance(n2, roads2)

    assert result0 == 43
    assert result1 == 20
    assert result2 == 9


def test_find_common_characters():
    words0 = ["bella", "label", "roller"]
    words1 = ["cool", "lock", "cook"]

    solution0 = common_characters.Solution()
    solution1 = common_characters.Solution()

    result0 = solution0.common_chars(words0)
    result1 = solution1.common_chars(words1)

    assert result0 == ["e", "l", "l"]
    assert result1 == ["c", "o"]


def test_circular_permutation_in_binary_representation():
    n0 = 2
    start0 = 3

    n1 = 3
    start1 = 2

    solution0 = representation.Solution()
    solution1 = representation.Solution()

    result0 = solution0.circular_permutation(n0, start0)
    result1 = solution1.circular_permutation(n1, start1)

    assert result0 == [3, 2, 0, 1]
    assert result1 == [2, 6, 7, 5, 4, 0, 1, 3]


def test_count_number_of_nice_subarrays():
    nums0 = [1, 1, 2, 1, 1]
    nums1 = [2, 4, 6]
    nums2 = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2]
    nums3 = [1, 1, 1, 1, 1]

    k0 = 3
    k1 = 1
    k2 = 2
    k3 = 1

    solution0 = number_of_nice_subarrays.Solution()
    solution1 = number_of_nice_subarrays.Solution()
    solution2 = number_of_nice_subarrays.Solution()
    solution3 = number_of_nice_subarrays.Solution()

    result0 = solution0.number_of_subarrays(nums0, k0)
    result1 = solution1.number_of_subarrays(nums1, k1)
    result2 = solution2.number_of_subarrays(nums2, k2)
    result3 = solution3.number_of_subarrays(nums3, k3)

    assert result0 == 2
    assert result1 == 0
    assert result2 == 16
    assert result3 == 5


def test_count_number_of_nice_subarrays_again():
    nums0 = [1, 1, 2, 1, 1]
    nums1 = [2, 4, 6]
    nums2 = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2]
    nums3 = [1, 1, 1, 1, 1]

    k0 = 3
    k1 = 1
    k2 = 2
    k3 = 1

    solution0 = subarrays_again.Solution()
    solution1 = subarrays_again.Solution()
    solution2 = subarrays_again.Solution()
    solution3 = subarrays_again.Solution()

    result0 = solution0.number_of_subarrays(nums0, k0)
    result1 = solution1.number_of_subarrays(nums1, k1)
    result2 = solution2.number_of_subarrays(nums2, k2)
    result3 = solution3.number_of_subarrays(nums3, k3)

    assert result0 == 2
    assert result1 == 0
    assert result2 == 16
    assert result3 == 5


def test_validate_stack_sequences():
    pushed0 = [1, 2, 3, 4, 5]
    popped0 = [4, 5, 3, 2, 1]

    pushed1 = [1, 2, 3, 4, 5]
    popped1 = [4, 3, 5, 1, 2]

    solution0 = stack_sequences.Solution()
    solution1 = stack_sequences.Solution()

    result0 = solution0.validate_stack_sequences(pushed0, popped0)
    result1 = solution1.validate_stack_sequences(pushed1, popped1)

    assert result0 is True
    assert result1 is False
