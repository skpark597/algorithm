import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.list_node import ListNode
import year_twenty_five.december.construct_binary_tree_from_preorder_and_inorder_traversal as build_tree
import year_twenty_five.december.make_sum_divisible_by_p as min_subarray
import year_twenty_five.december.merge_sorted_array as merge_sorted_array
import year_twenty_five.december.minimum_size_subarray_sum as minimum_size_subarray_sum
import year_twenty_five.december.ransom_note as ransom_note
import year_twenty_five.december.remove_duplicates_from_sorted_array as remove_duplicates_from_sorted_array
import year_twenty_five.december.remove_element as remove_element
import year_twenty_five.december.summary_ranges as summary_ranges
import year_twenty_five.december.two_sum_ii as two_sum_ii
import year_twenty_five.december.valid_palindrome as valid_palindrome
import year_twenty_five.december.add_two_numbers as add_two_numbers
import year_twenty_five.december.min_stack as min_stack
from common.tree_node import TreeNode
from common.util import is_same_list_nodes, is_same_tree


def test_min_subarray():
    solution = min_subarray.Solution()

    nums0, p0 = [3, 1, 4, 2], 6
    nums1, p1 = [6, 3, 5, 2], 9
    nums2, p2 = [1, 2, 3], 3
    nums3, p3 = [1, 2, 3], 7
    nums4, p4 = [3, 2, 2, 4, 6, 1, 6, 5], 7
    nums5, p5 = [1, 1, 1], 2

    ret0 = solution.min_subarray(nums0, p0)
    ret1 = solution.min_subarray(nums1, p1)
    ret2 = solution.min_subarray(nums2, p2)
    ret3 = solution.min_subarray(nums3, p3)
    ret4 = solution.min_subarray(nums4, p4)
    ret5 = solution.min_subarray(nums5, p5)

    assert ret0 == 1
    assert ret1 == 2
    assert ret2 == 0
    assert ret3 == -1
    assert ret4 == 1
    assert ret5 == 1


def test_merge_sorted_array():
    solution = merge_sorted_array.Solution()

    nums01, nums02, m0, n0 = [1, 2, 3, 0, 0, 0], [2, 5, 6], 3, 3
    nums11, nums12, m1, n1 = [1], [], 1, 0
    nums21, nums22, m2, n2 = [0], [1], 0, 1
    nums31, nums32, m3, n3 = [2, 0], [1], 1, 1

    solution.merge(nums01, m0, nums02, n0)
    solution.merge(nums11, m1, nums12, n1)
    solution.merge(nums21, m2, nums22, n2)
    solution.merge(nums31, m3, nums32, n3)

    assert nums01 == [1, 2, 2, 3, 5, 6]
    assert nums11 == [1]
    assert nums21 == [1]
    assert nums31 == [1, 2]


def test_remove_element():
    solution = remove_element.Solution()

    nums0, val0 = [3, 2, 2, 3], 3
    nums1, val1 = [0, 1, 2, 2, 3, 0, 4, 2], 2
    nums2, val2 = [2], 3
    nums3, val3 = [1], 1
    nums4, val4 = [4, 5], 4

    ret0 = solution.remove_element(nums0, val0)
    ret1 = solution.remove_element(nums1, val1)
    ret2 = solution.remove_element(nums2, val2)
    ret3 = solution.remove_element(nums3, val3)
    ret4 = solution.remove_element(nums4, val4)

    assert sorted(nums0[:ret0]) == [2, 2]
    assert sorted(nums1[:ret1]) == [0, 0, 1, 3, 4]
    assert sorted(nums2[:ret2]) == [2]
    assert sorted(nums3[:ret3]) == []
    assert sorted(nums4[:ret4]) == [5]


def test_remove_duplicates_from_sorted_array():
    solution = remove_duplicates_from_sorted_array.Solution()

    nums0 = [1, 1, 2]
    nums1 = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

    ret0 = solution.remove_duplicates(nums0)
    ret1 = solution.remove_duplicates(nums1)

    assert sorted(nums0[:ret0]) == [1, 2]
    assert sorted(nums1[:ret1]) == [0, 1, 2, 3, 4]


def test_valid_palindrome():
    solution = valid_palindrome.Solution()

    s0 = "A man, a plan, a canal: Panama"
    s1 = "race a car"
    s2 = " "

    ret0 = solution.is_palindrome(s0)
    ret1 = solution.is_palindrome(s1)
    ret2 = solution.is_palindrome(s2)

    assert ret0 is True
    assert ret1 is False
    assert ret2 is True


def test_two_sum_ii():
    solution = two_sum_ii.Solution()

    numbers0, target0 = [2, 7, 11, 15], 9
    numbers1, target1 = [2, 3, 4], 6
    numbers2, target2 = [-1, 0], -1

    ret0 = solution.two_sum(numbers0, target0)
    ret1 = solution.two_sum(numbers1, target1)
    ret2 = solution.two_sum(numbers2, target2)

    assert ret0 == [1, 2]
    assert ret1 == [1, 3]
    assert ret2 == [1, 2]


def test_ransom_note():
    solution = ransom_note.Solution()

    ransom_note0, magazine0 = "a", "b"
    ransom_note1, magazine1 = "aa", "ab"
    ransom_note2, magazine2 = "aa", "aab"

    ret0 = solution.can_construct(ransom_note0, magazine0)
    ret1 = solution.can_construct(ransom_note1, magazine1)
    ret2 = solution.can_construct(ransom_note2, magazine2)

    assert ret0 is False
    assert ret1 is False
    assert ret2 is True


def test_minimum_size_subarray_sum():
    solution = minimum_size_subarray_sum.Solution()

    target0, nums0 = 7, [2, 3, 1, 2, 4, 3]
    target1, nums1 = 4, [1, 4, 4]
    target2, nums2 = 11, [1, 1, 1, 1, 1, 1, 1, 1]

    ret0 = solution.min_sub_array_len(target0, nums0)
    ret1 = solution.min_sub_array_len(target1, nums1)
    ret2 = solution.min_sub_array_len(target2, nums2)

    assert ret0 == 2
    assert ret1 == 1
    assert ret2 == 0


def test_summary_ranges():
    solution = summary_ranges.Solution()

    nums0 = [0, 1, 2, 4, 5, 7]
    nums1 = [0, 2, 3, 4, 6, 8, 9]

    ret0 = solution.summary_ranges(nums0)
    ret1 = solution.summary_ranges(nums1)

    assert ret0 == ["0->2", "4->5", "7"]
    assert ret1 == ["0", "2->4", "6", "8->9"]


def test_build_tree():
    solution = build_tree.Solution()

    preorder0, inorder0 = [3, 9, 20, 15, 7], [9, 3, 15, 20, 7]
    preorder1, inorder1 = [-1], [-1]

    ret0 = solution.build_tree(preorder0, inorder0)
    ret1 = solution.build_tree(preorder1, inorder1)

    ans0 = TreeNode.make([3, 9, 20, None, None, 15, 7])
    ans1 = TreeNode.make([-1])

    assert is_same_tree(ret0, ans0)
    assert is_same_tree(ret1, ans1)


def test_add_two_numbers():
    solution = add_two_numbers.Solution()

    l01 = ListNode.make([2, 4, 3])
    l02 = ListNode.make([5, 6, 4])

    l11 = ListNode.make([0])
    l12 = ListNode.make([0])

    l21 = ListNode.make([9, 9, 9, 9, 9, 9, 9])
    l22 = ListNode.make([9, 9, 9, 9])

    ans0 = ListNode.make([7, 0, 8])
    ans1 = ListNode.make([0])
    ans2 = ListNode.make([8, 9, 9, 9, 0, 0, 0, 1])

    ret0 = solution.add_two_numbers(l01, l02)
    ret1 = solution.add_two_numbers(l11, l12)
    ret2 = solution.add_two_numbers(l21, l22)

    assert is_same_list_nodes(ret0, ans0)
    assert is_same_list_nodes(ret1, ans1)
    assert is_same_list_nodes(ret2, ans2)


def test_min_stack():
    stack0 = min_stack.MinStack()

    stack0.push(-2)
    stack0.push(0)
    stack0.push(-3)

    ret0 = stack0.get_min()

    stack0.pop()

    ret1 = stack0.top()
    ret2 = stack0.get_min()

    assert ret0 == -3
    assert ret1 == 0
    assert ret2 == -2
