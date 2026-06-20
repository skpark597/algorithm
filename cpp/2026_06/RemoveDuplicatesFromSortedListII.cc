/** 82. Remove Duplicates from Sorted List II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from
the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:
The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order. */

#include <cassert>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* deleteDuplicates(ListNode* head) {
  ListNode* dummy = new ListNode(101, head);
  ListNode *prev = dummy, *cur = head;

  while (cur && cur->next) {
    if (cur->val == cur->next->val) {
      int duplicate_val = cur->val;

      while (cur && cur->val == duplicate_val) cur = cur->next;
      prev->next = cur;

    } else {
      prev = prev->next;
      cur = cur->next;
    }
  }

  ListNode* result = dummy->next;
  delete dummy;

  return result;
}

int main() {
  ListNode* head0 = makeLinkedList(vector<int>{1, 2, 3, 3, 4, 4, 5});
  ListNode* head1 = makeLinkedList(vector<int>{1, 1, 1, 2, 3});

  ListNode* ret0 = deleteDuplicates(head0);
  ListNode* ret1 = deleteDuplicates(head1);

  ListNode* ans0 = makeLinkedList(vector<int>{1, 2, 5});
  ListNode* ans1 = makeLinkedList(vector<int>{2, 3});

  assert(isSameLinkedList(ret0, ans0));
  assert(isSameLinkedList(ret1, ans1));

  return 0;
}
