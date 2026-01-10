import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

# pylint: disable=C0411,C0413,R0402,E0401
import year_twenty_three.november.reverse_string_ii as reverse_string_ii
import year_twenty_three.november.fair_candy_swap as fair_candy_swap


def test_reverse_string_ii():
    solution0 = reverse_string_ii.Solution()
    solution1 = reverse_string_ii.Solution()
    solution2 = reverse_string_ii.Solution()
    solution3 = reverse_string_ii.Solution()
    solution4 = reverse_string_ii.Solution()
    solution5 = reverse_string_ii.Solution()
    solution6 = reverse_string_ii.Solution()
    solution7 = reverse_string_ii.Solution()

    s0, k0 = "abcdefg", 2
    s1, k1 = "abcd", 2
    s2, k2 = "abcdefghijklgm", 3
    s3, k3 = "abcdefghijklgm", 4

    result0 = solution0.reverse_str_v1(s0, k0)
    result1 = solution1.reverse_str_v1(s1, k1)
    result2 = solution2.reverse_str_v1(s2, k2)
    result3 = solution3.reverse_str_v1(s3, k3)
    result4 = solution4.reverse_str_v2(s0, k0)
    result5 = solution5.reverse_str_v2(s1, k1)
    result6 = solution6.reverse_str_v2(s2, k2)
    result7 = solution7.reverse_str_v2(s3, k3)

    assert result0 == "bacdfeg"
    assert result1 == "bacd"
    assert result2 == "cbadefihgjklmg"
    assert result3 == "dcbaefghlkjigm"
    assert result4 == "bacdfeg"
    assert result5 == "bacd"
    assert result6 == "cbadefihgjklmg"
    assert result7 == "dcbaefghlkjigm"


def test_fair_candy_swap():
    solution0 = fair_candy_swap.Solution()
    solution1 = fair_candy_swap.Solution()
    solution2 = fair_candy_swap.Solution()

    alice_sizes0, bob_sizes0 = [1, 1], [2, 2]
    alice_sizes1, bob_sizes1 = [1, 2], [2, 3]
    alice_sizes2, bob_sizes2 = [2], [1, 3]

    result0 = solution0.fair_candy_swap(alice_sizes0, bob_sizes0)
    result1 = solution1.fair_candy_swap(alice_sizes1, bob_sizes1)
    result2 = solution2.fair_candy_swap(alice_sizes2, bob_sizes2)

    assert result0 == [1, 2]
    assert result1 == [1, 2]
    assert result2 == [2, 3]
