import sys
from os.path import abspath, dirname, join


SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_double_arrays_ignoring_order
from common.tree_node import TreeNode
import year_twenty_three.june.maximum_number_of_occurrences_of_a_substring as max_frequency
import year_twenty_three.june.smallest_subsequence_of_distinct_characters as smallest_subsequence
import year_twenty_three.june.fair_distribution_of_cookies as distribute_cookies
import year_twenty_three.june.maximum_tastiness_of_candy_basket as maximum_tastiness
import year_twenty_three.june.backspace_string_compare as backspace_compare
import year_twenty_three.june.count_good_nodes_in_binary_tree as good_nodes
import year_twenty_three.june.append_characters_to_string_to_make_subsequence as append_characters
import year_twenty_three.june.subsets_II as subsets_with_dup
import year_twenty_three.june.longest_nice_subarray as longest_nice_subarray
import year_twenty_three.june.construct_k_palindrome_strings as can_construct


def test_maximum_number_of_occurences_of_a_substring():
    solution0 = max_frequency.Solution()
    solution1 = max_frequency.Solution()
    solution2 = max_frequency.Solution()

    s0 = "aababcaab"
    max_letters0, min_size0, max_size0 = 2, 3, 4

    s1 = "aaaa"
    max_letters1, min_size1, max_size1 = 1, 3, 3

    s2 = "abcde"
    max_letters2, min_size2, max_size2 = 2, 3, 3

    answer0 = 2
    answer1 = 2
    answer2 = 0

    result0 = solution0.max_freq(s0, max_letters0, min_size0, max_size0)
    result1 = solution1.max_freq(s1, max_letters1, min_size1, max_size1)
    result2 = solution2.max_freq(s2, max_letters2, min_size2, max_size2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_smallest_subsequence():
    solution0 = smallest_subsequence.Solution()
    solution1 = smallest_subsequence.Solution()

    s0 = "bcabc"
    s1 = "cbacdcbc"

    answer0 = "abc"
    answer1 = "acdb"

    result0 = solution0.smallest_subsequence(s0)
    result1 = solution1.smallest_subsequence(s1)

    assert result0 == answer0
    assert result1 == answer1


def test_distribute_cookies():
    solution0 = distribute_cookies.Solution()
    solution1 = distribute_cookies.Solution()
    solution2 = distribute_cookies.Solution()

    cookies0, k0 = [8, 15, 10, 20, 8], 2
    cookies1, k1 = [6, 1, 3, 2, 2, 4, 1, 2], 3
    cookies2, k2 = [36597, 70125, 68220, 4921], 2

    answer0 = 31
    answer1 = 7
    answer2 = 104817

    result0 = solution0.distribute_cookies(cookies0, k0)
    result1 = solution1.distribute_cookies(cookies1, k1)
    result2 = solution2.distribute_cookies(cookies2, k2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_maximum_tastiness():
    solution0 = maximum_tastiness.Solution()
    solution1 = maximum_tastiness.Solution()
    solution2 = maximum_tastiness.Solution()

    price0, k0 = [13, 5, 1, 8, 21, 2], 3
    price1, k1 = [1, 3, 1], 2
    price2, k2 = [7, 7, 7, 7], 2

    answer0 = 8
    answer1 = 2
    answer2 = 0

    result0 = solution0.maximum_tastiness(price0, k0)
    result1 = solution1.maximum_tastiness(price1, k1)
    result2 = solution2.maximum_tastiness(price2, k2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_backspace_compare():
    solution0 = backspace_compare.Solution()
    solution1 = backspace_compare.Solution()
    solution2 = backspace_compare.Solution()

    s0, t0 = "ab#c", "ad#c"
    s1, t1 = "ab##", "c#d#"
    s2, t2 = "a#c", "b"

    result0 = solution0.backspace_compare(s0, t0)
    result1 = solution1.backspace_compare(s1, t1)
    result2 = solution2.backspace_compare(s2, t2)

    assert result0 is True
    assert result1 is True
    assert result2 is False


def test_good_nodes():
    solution0 = good_nodes.Solution()
    solution1 = good_nodes.Solution()
    solution2 = good_nodes.Solution()

    root0 = TreeNode.make([3, 1, 4, 3, None, 1, 5])
    root1 = TreeNode.make([3, 3, None, 4, 2])
    root2 = TreeNode.make([1])

    answer0 = 4
    answer1 = 3
    answer2 = 1

    result0 = solution0.good_nodes(root0)
    result1 = solution1.good_nodes(root1)
    result2 = solution2.good_nodes(root2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_append_characters():
    solution0 = append_characters.Solution()
    solution1 = append_characters.Solution()
    solution2 = append_characters.Solution()

    s0, t0 = "coaching", "coding"
    s1, t1 = "abcde", "a"
    s2, t2 = "z", "abcde"

    answer0 = 4
    answer1 = 0
    answer2 = 5

    result0 = solution0.append_characters(s0, t0)
    result1 = solution1.append_characters(s1, t1)
    result2 = solution2.append_characters(s2, t2)

    assert result0 == answer0
    assert result1 == answer1
    assert result2 == answer2


def test_subsets_II():
    solution0 = subsets_with_dup.Solution()
    solution1 = subsets_with_dup.Solution()
    solution2 = subsets_with_dup.Solution()

    nums0 = [1, 2, 2]
    nums1 = [0]
    nums2 = [4, 1, 0]

    result0 = solution0.subsets_with_dup(nums0)
    result1 = solution1.subsets_with_dup(nums1)
    result2 = solution2.subsets_with_dup(nums2)

    answer0 = [[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]
    answer1 = [[], [0]]
    answer2 = [[], [0], [1], [4], [0, 1], [0, 4], [1, 4], [0, 1, 4]]

    compare0 = is_same_double_arrays_ignoring_order(answer0, result0)
    compare1 = is_same_double_arrays_ignoring_order(answer1, result1)
    compare2 = is_same_double_arrays_ignoring_order(answer2, result2)

    assert compare0 is True
    assert compare1 is True
    assert compare2 is True


def test_longest_nice_subarray():
    solution0 = longest_nice_subarray.Solution()
    solution1 = longest_nice_subarray.Solution()

    nums0 = [1, 3, 8, 48, 10]
    nums1 = [3, 1, 5, 11, 13]

    answer0 = 3
    answer1 = 1

    result0 = solution0.longest_nice_subarray(nums0)
    result1 = solution1.longest_nice_subarray(nums1)

    assert result0 == answer0
    assert result1 == answer1


def test_can_construct():
    solution0 = can_construct.Solution()
    solution1 = can_construct.Solution()
    solution2 = can_construct.Solution()

    s0, k0 = "annabelle", 2
    s1, k1 = "leetcode", 3
    s2, k2 = "true", 4

    result0 = solution0.can_construct(s0, k0)
    result1 = solution1.can_construct(s1, k1)
    result2 = solution2.can_construct(s2, k2)

    assert result0 is True
    assert result1 is False
    assert result2 is True
