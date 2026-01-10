"""
2. Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
"""

from common.list_node import ListNode


class Solution:
    def _list_to_int(self, head: ListNode):
        digits = ""
        cur = head

        while cur:
            digits += str(cur.val)
            cur = cur.next

        return int(digits[::-1])

    def _int_to_list(self, num: int) -> ListNode:
        dummy = ListNode()
        prev = None

        for digit in str(num)[::-1]:
            cur = ListNode(val=int(digit))

            if not prev:
                dummy.next = cur
            else:
                prev.next = cur

            prev = cur

        return dummy.next

    def add_two_numbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = self._list_to_int(l1)
        num2 = self._list_to_int(l2)

        return self._int_to_list(num1 + num2)
