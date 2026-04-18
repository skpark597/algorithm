import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
sys.path.insert(1, abspath(SRC_DIR))

from common.list_node import ListNode
from common.tree_node import TreeNode
from common.util import is_same_list_nodes, is_same_tree
import year_twenty_six.april.construct_binary_tree_from_inorder_and_postorder_traversal as inorder_and_postorder_traversal
import year_twenty_six.april.average_of_levels_in_binary_tree as average_of_levels_in_binary_tree
import year_twenty_six.april.word_break as word_break
import year_twenty_six.april.remove_nth_node_from_end_of_list as remove_nth_from_end
import year_twenty_six.april.simplify_path as simplify_path


def test_inorder_and_postorder_traversal():
    solution = inorder_and_postorder_traversal.Solution()

    inorder0 = [9, 3, 15, 20, 7]
    postorder0 = [9, 15, 7, 20, 3]

    inorder1 = [-1]
    postorder1 = [-1]

    inorder2 = [8, 1, 4, 3, 15, 20, 2, 7, 9]
    postorder2 = [8, 4, 1, 15, 2, 9, 7, 20, 3]

    ret0 = solution.build_tree(inorder0, postorder0)
    ret1 = solution.build_tree(inorder1, postorder1)
    ret2 = solution.build_tree(inorder2, postorder2)

    ans0 = TreeNode.make([3, 9, 20, None, None, 15, 7])
    ans1 = TreeNode.make([-1])
    ans2 = TreeNode.make([3, 1, 20, 8, 4, 15, 7, None, None, None, None, None, None, 2, 9])

    assert is_same_tree(ret0, ans0)
    assert is_same_tree(ret1, ans1)
    assert is_same_tree(ret2, ans2)


def test_average_of_levels_in_binary_tree():
    solution = average_of_levels_in_binary_tree.Solution()

    root0 = TreeNode.make([3, 9, 20, None, None, 15, 7])
    root1 = TreeNode.make([3, 9, 20, 15, 7])

    ans0 = [3.0, 14.5, 11.0]
    ans1 = [3.0, 14.5, 11.0]

    ret0 = solution.average_of_levels(root0)
    ret1 = solution.average_of_levels(root1)

    assert ret0 == ans0
    assert ret1 == ans1


def test_word_break():
    solution = word_break.Solution()

    s0 = "leetcode"
    word_dict0 = ["leet", "code"]

    s1 = "applepenapple"
    word_dict1 = ["apple", "pen"]

    s2 = "catsandog"
    word_dict2 = ["cats", "dog", "sand", "and", "cat"]

    ret0 = solution.word_break(s0, word_dict0)
    ret1 = solution.word_break(s1, word_dict1)
    ret2 = solution.word_break(s2, word_dict2)

    assert ret0 is True
    assert ret1 is True
    assert ret2 is False


def test_remove_nth_from_end():
    solution = remove_nth_from_end.Solution()

    head0 = ListNode.make([1, 2, 3, 4, 5])
    head1 = ListNode.make([1])
    head2 = ListNode.make([1, 2])

    n0 = 2
    n1 = 1
    n2 = 1

    ret0 = solution.remove_nth_from_end(head0, n0)
    ret1 = solution.remove_nth_from_end(head1, n1)
    ret2 = solution.remove_nth_from_end(head2, n2)

    ans0 = ListNode.make([1, 2, 3, 5])
    ans1 = ListNode.make([])
    ans2 = ListNode.make([1])

    assert is_same_list_nodes(ret0, ans0)
    assert is_same_list_nodes(ret1, ans1)
    assert is_same_list_nodes(ret2, ans2)


def test_simplify_path():
    solution = simplify_path.Solution()

    path0 = "/home/"
    path1 = "/home//foo"
    path2 = "/home/user/Documents/../Pictures"
    path3 = "/../"
    path4 = "/.../a/../b/c/../d/./"

    ret0 = solution.simplify_path(path0)
    ret1 = solution.simplify_path(path1)
    ret2 = solution.simplify_path(path2)
    ret3 = solution.simplify_path(path3)
    ret4 = solution.simplify_path(path4)

    ans0 = "/home"
    ans1 = "/home/foo"
    ans2 = "/home/user/Pictures"
    ans3 = "/"
    ans4 = "/.../b/d"

    assert ret0 == ans0
    assert ret1 == ans1
    assert ret2 == ans2
    assert ret3 == ans3
    assert ret4 == ans4
