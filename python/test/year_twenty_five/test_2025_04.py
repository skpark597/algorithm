import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

import year_twenty_five.april.take_k_of_each_character_from_left_and_right as take_characters
import year_twenty_five.april.lru_cache as lru_cache
import year_twenty_five.april.search_in_rotated_sorted_array as search
import year_twenty_five.april.longest_uncommon_subsequence_ii as find_lus_length


def test_take_characters():
    solution = take_characters.Solution()

    s0, k0 = "aabaaaacaabc", 2
    s1, k1 = "a", 1
    s2, k2 = "a", 0
    s3, k3 = "cbbac", 1

    result0 = solution.take_characters(s0, k0)
    result1 = solution.take_characters(s1, k1)
    result2 = solution.take_characters(s2, k2)
    result3 = solution.take_characters(s3, k3)

    assert result0 == 8
    assert result1 == -1
    assert result2 == 0
    assert result3 == 3


def test_lru_cache():
    cache = lru_cache.LRUCache(2)

    cache.put(1, 1)
    cache.put(2, 2)
    assert list(cache.data.items()) == [(1, 1), (2, 2)]

    result0 = cache.get(1)
    assert result0 == 1
    assert list(cache.data.items()) == [(2, 2), (1, 1)]

    cache.put(3, 3)
    assert list(cache.data.items()) == [(1, 1), (3, 3)]

    result1 = cache.get(2)
    assert result1 == -1

    cache.put(4, 4)
    assert list(cache.data.items()) == [(3, 3), (4, 4)]

    result2 = cache.get(1)
    result3 = cache.get(3)
    result4 = cache.get(4)

    assert result2 == -1
    assert result3 == 3
    assert result4 == 4

    cache = lru_cache.LRUCache(2)
    result0 = cache.get(2)
    assert result0 == -1

    cache.put(2, 6)
    assert list(cache.data.items()) == [(2, 6)]

    result1 = cache.get(1)
    assert result1 == -1

    cache.put(1, 5)
    assert list(cache.data.items()) == [(2, 6), (1, 5)]

    cache.put(1, 2)
    assert list(cache.data.items()) == [(2, 6), (1, 2)]

    result2 = cache.get(1)
    assert list(cache.data.items()) == [(2, 6), (1, 2)]
    assert result2 == 2

    result3 = cache.get(2)
    assert list(cache.data.items()) == [(1, 2), (2, 6)]
    assert result3 == 6


def test_search():
    solution = search.Solution()

    nums0, target0 = [4, 5, 6, 7, 0, 1, 2], 0
    nums1, target1 = [4, 5, 6, 7, 0, 1, 2], 3
    nums2, target2 = [1], 0

    result0 = solution.search(nums0, target0)
    result1 = solution.search(nums1, target1)
    result2 = solution.search(nums2, target2)

    assert result0 == 4
    assert result1 == -1
    assert result2 == -1


def test_find_lus_length():
    solution = find_lus_length.Solution()

    strs0 = ["aba", "cdc", "eae"]
    strs1 = ["aaa", "aaa", "aa"]
    strs2 = ["abcd", "abcd", "abc", "bcd", "ace", "a"]
    strs3 = ["abcd", "abcd", "ae"]

    result0 = solution.find_lus_length(strs0)
    result1 = solution.find_lus_length(strs1)
    result2 = solution.find_lus_length(strs2)
    result3 = solution.find_lus_length(strs3)

    assert result0 == 3
    assert result1 == -1
    assert result2 == 3
    assert result3 == 2
