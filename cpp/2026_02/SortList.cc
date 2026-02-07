/** 148. Sort List
Given the head of a linked list, return the list after sorting it in ascending
order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []

Constraints:
The number of nodes in the list is in the range [0, 5 * 10^4].
-10^5 <= Node.val <= 10^5

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e.
constant space)? */

#include <cassert>
#include <vector>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* merge(ListNode* h0, ListNode* h1) {
  ListNode dummy = ListNode(0);
  ListNode* cur = &dummy;

  while (h0 && h1) {
    if (h0->val < h1->val) {
      cur->next = h0;
      h0 = h0->next;
    } else {
      cur->next = h1;
      h1 = h1->next;
    }

    cur = cur->next;
  }

  if (h0) cur->next = h0;
  if (h1) cur->next = h1;

  return dummy.next;
}

ListNode* sortList(ListNode* head) {
  if (!head || !(head->next)) return head;

  ListNode* prev = nullptr;
  ListNode* slow = head;
  ListNode* fast = head;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = nullptr;

  ListNode* left = sortList(head);
  ListNode* right = sortList(slow);

  return merge(left, right);
}

int main() {
  ListNode* head0 = makeLinkedList(vector<int>{4, 2, 1, 3});
  ListNode* head1 = makeLinkedList(vector<int>{-1, 5, 3, 4, 0});
  ListNode* head2 = makeLinkedList(vector<int>{});

  ListNode* ret0 = sortList(head0);
  ListNode* ret1 = sortList(head1);
  ListNode* ret2 = sortList(head2);

  ListNode* ans0 = makeLinkedList(vector<int>{1, 2, 3, 4});
  ListNode* ans1 = makeLinkedList(vector<int>{-1, 0, 3, 4, 5});
  ListNode* ans2 = makeLinkedList(vector<int>{});

  assert(isSameLinkedList(ret0, ans0) == true);
  assert(isSameLinkedList(ret1, ans1) == true);
  assert(isSameLinkedList(ret2, ans2) == true);

  return 0;
}