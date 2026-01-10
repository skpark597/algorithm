from __future__ import annotations

from typing import List


class ListNode:
    val: int
    next: ListNode

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    @staticmethod
    def make(nums: List[int]):
        if len(nums) == 0:
            return None

        head = ListNode(nums[0])
        prev = head

        for idx in range(1, len(nums)):
            prev.next = ListNode(nums[idx])
            prev = prev.next

        return head
