"""
86. Partition List
Given the head of a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:
Input: head = [2,1], x = 2
Output: [1,2]

Constraints:
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200
"""

from typing import Optional
from common.list_node import ListNode


MIN_VALUE = -201


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        if head is None:
            return None

        first = ListNode(MIN_VALUE, head)
        node = first

        while node.next is not None:
            if node.next.val >= x:
                prev_of_first_ge = node
                break

            node = node.next

        while node is not None and node.next is not None:
            next = node.next

            if next.val < x:
                node.next = next.next
                temp = prev_of_first_ge.next
                prev_of_first_ge.next = next
                next.next = temp
                prev_of_first_ge = next
            else:
                node = next

        return first.next
