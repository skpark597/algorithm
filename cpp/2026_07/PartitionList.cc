/** 86. Partition List
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater
than or equal to x.

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
-200 <= x <= 200  */

#include <cassert>
#include <vector>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* partition(ListNode* head, int x) {
  ListNode dummy(-101, head);
  ListNode *prev = &dummy, *less_tail = nullptr;

  while (prev->next) {
    ListNode* cur = prev->next;

    if (cur->val < x && less_tail) {
      prev->next = cur->next;
      cur->next = less_tail->next;
      less_tail->next = cur;
      less_tail = cur;
    } else {
      if (cur->val >= x && !less_tail) less_tail = prev;
      prev = prev->next;
    }
  }

  return dummy.next;
}

int main() {
  ListNode* head0 = makeLinkedList(vector<int>{1, 4, 3, 2, 5, 2});
  ListNode* head1 = makeLinkedList(vector<int>{2, 1});

  int x0 = 3;
  int x1 = 2;

  ListNode* ret0 = partition(head0, x0);
  ListNode* ret1 = partition(head1, x1);

  ListNode* ans0 = makeLinkedList(vector<int>{1, 2, 2, 4, 3, 5});
  ListNode* ans1 = makeLinkedList(vector<int>{1, 2});

  assert(isSameLinkedList(ret0, ans0));
  assert(isSameLinkedList(ret1, ans1));

  return 0;
}