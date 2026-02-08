/** 92. Reverse Linked List II
Given the head of a singly linked list and two integers left and right where
left <= right, reverse the nodes of the list from position left to position
right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

Follow up: Could you do it in one pass? */

#include <cassert>
#include <vector>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* reverseBetween(ListNode* head, int left, int right) {
  if (!head || left == right) return head;

  ListNode dummy = ListNode(0);
  ListNode* pre = &dummy;

  dummy.next = head;

  for (int i = 0; i < left - 1; ++i) pre = pre->next;

  ListNode* cur = pre->next;

  for (int i = 0; i < right - left; ++i) {
    ListNode* temp = cur->next;

    cur->next = temp->next;
    temp->next = pre->next;
    pre->next = temp;
  }

  return dummy.next;
}

int main() {
  ListNode* head0 = makeLinkedList(vector<int>{1, 2, 3, 4, 5});
  ListNode* head1 = makeLinkedList(vector<int>{5});

  ListNode* ret0 = reverseBetween(head0, 2, 4);
  ListNode* ret1 = reverseBetween(head1, 1, 1);

  ListNode* ans0 = makeLinkedList(vector<int>{1, 4, 3, 2, 5});
  ListNode* ans1 = makeLinkedList(vector<int>{5});

  assert(isSameLinkedList(ret0, ans0));
  assert(isSameLinkedList(ret1, ans1));

  return 0;
}
