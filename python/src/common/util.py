from typing import List, Optional

# pylint: disable=E0401
from common.list_node import ListNode
from common.tree_node import TreeNode


def is_same_double_arrays_ignoring_order(arr0: List[List[int]], arr1: List[List[int]]):
    sorted0 = sorted(arr0)
    sorted1 = sorted(arr1)

    return sorted0 == sorted1


def is_same_tree_arrays_ignoring_order(arr0: List[TreeNode], arr1: List[TreeNode]):
    sorted0 = sorted(arr0, key=lambda x: x.val)
    sorted1 = sorted(arr1, key=lambda x: x.val)

    for tree0, tree1 in zip(sorted0, sorted1):
        if not is_same_tree(tree0, tree1):
            return False

    return True


def is_same_arrays_ignoring_order(arr0: List[int], arr1: List[int]):
    sorted0 = sorted(arr0)
    sorted1 = sorted(arr1)

    return sorted0 == sorted1


def is_same_list_nodes(head0: Optional[ListNode], head1: Optional[ListNode]):
    node0 = head0
    node1 = head1

    while node0 is not None:
        if node1 is None:
            return False

        if node0.val != node1.val:
            return False

        node0 = node0.next
        node1 = node1.next

    return node1 is None


def is_same_tree(tree0: Optional[TreeNode], tree1: Optional[TreeNode]) -> bool:
    if tree0 is None or tree1 is None:
        return tree0 is None and tree1 is None

    if tree0.val != tree1.val:
        return False

    is_left_same = is_same_tree(tree0.left, tree1.left)
    is_right_same = is_same_tree(tree0.right, tree1.right)

    return is_left_same and is_right_same
