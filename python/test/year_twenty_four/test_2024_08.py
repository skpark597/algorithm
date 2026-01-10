import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# ruff: noqa
import year_twenty_four.august.minimum_length_of_string_after_deleting_similar_ends as minimum_length_of_string
import year_twenty_four.august.longest_string_chain as longest_str_chain


def test_minimum_number_of_operations():
    solution = minimum_length_of_string.Solution()

    s0 = "ca"
    s1 = "cabaabac"
    s2 = "aabccabba"
    s3 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb"

    result0 = solution.minimum_length(s0)
    result1 = solution.minimum_length(s1)
    result2 = solution.minimum_length(s2)
    result3 = solution.minimum_length(s3)

    assert result0 == 2
    assert result1 == 0
    assert result2 == 3
    assert result3 == 1


def test_longest_str_chain():
    solution = longest_str_chain.Solution()

    words0 = ["a", "b", "ba", "bca", "bda", "bdca"]
    words1 = ["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]
    words2 = ["abcd", "dbqca"]
    words3 = ["a", "b", "ab", "bac"]
    words4 = [
        "a",
        "ac",
        "abc",
        "aca",
        "acb",
        "acc",
        "acd",
        "ace",
        "acf",
        "acg",
        "ach",
        "aci",
        "acj",
        "ack",
        "acl",
        "acm",
        "acn",
        "aco",
        "acp",
        "acq",
        "acr",
        "acs",
        "act",
        "acu",
        "acv",
        "acw",
        "acx",
        "acy",
        "abcz",
    ]

    result0 = solution.longest_str_chain(words0)
    result1 = solution.longest_str_chain(words1)
    result2 = solution.longest_str_chain(words2)
    result3 = solution.longest_str_chain(words3)
    result4 = solution.longest_str_chain(words4)

    assert result0 == 4
    assert result1 == 5
    assert result2 == 1
    assert result3 == 2
    assert result4 == 4
