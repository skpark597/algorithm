import sys
from os.path import abspath, dirname, join

SRC_DIR = join(dirname(__file__), "../../src")
TEST_DIR = join(dirname(__file__), "../../test")

sys.path.insert(1, abspath(SRC_DIR))
sys.path.insert(1, abspath(TEST_DIR))

# pylint: disable=C0413,R0402,E0401
from common.util import is_same_list_nodes
from common.list_node import ListNode


def list_node_example0():
    node2 = ListNode(3)
    node1 = ListNode(2, node2)

    return ListNode(1, node1)


def test_make_list_node0():
    nums = [1, 2, 3]
    result = ListNode.make(nums)
    answer = list_node_example0()

    compare = is_same_list_nodes(result, answer)
    assert compare is True


def test_make_list_node1():
    result = ListNode.make([])
    answer = None

    compare = is_same_list_nodes(result, answer)
    assert compare is True
