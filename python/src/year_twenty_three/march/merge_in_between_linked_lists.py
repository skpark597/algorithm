"""
1669. Merge In Between Linked Lists

You are given two linked lists: list1 and list2 of sizes n and m respectively.
Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
The blue edges and nodes in the following figure indicate the result:
Build the result list and return its head.

Example 1:
Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [0,1,2,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place.
The blue edges and nodes in the above figure indicate the result.

Example 2:
Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
Explanation: The blue edges and nodes in the above figure indicate the result.

Constraints:
3 <= list1.length <= 10^4
1 <= a <= b < list1.length - 1
1 <= list2.length <= 10^4
"""

from common.list_node import ListNode


class Solution:
    def merge_in_between(
        self, list1: ListNode, a: int, b: int, list2: ListNode
    ) -> ListNode:
        cur1, cur2, res1, res2 = list1, list2, [], []

        while cur1:
            res1.append(cur1.val)
            cur1 = cur1.next

        while cur2:
            res2.append(cur2.val)
            cur2 = cur2.next

        res = res1[:a] + res2 + res1[b + 1 :]

        r1 = r2 = ListNode()

        for i in res:
            r1.next = ListNode(i)
            r1 = r1.next

        return r2.next

    def merge_in_between_old(
        self, list1: ListNode, a: int, b: int, list2: ListNode
    ) -> ListNode:
        head, node, list2_end = list1, list2, None
        merge_start, merge_end = None, None

        while node is not None:
            if node.next is None:
                list2_end = node
                break

            node = node.next

        node = list1

        for i in range(b + 2):
            if i == a - 1:
                merge_start = node
            if i == b + 1:
                merge_end = node

            node = node.next

        merge_start.next = list2
        list2_end.next = merge_end

        return head
