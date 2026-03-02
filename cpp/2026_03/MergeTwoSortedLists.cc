/**21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order. */

#include <cassert>
#include <vector>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode dummy;
  ListNode* cur = &dummy;

  while (list1 && list2) {
    if (list1->val <= list2->val) {
      cur->next = list1;
      list1 = list1->next;
    } else if (list2->val < list1->val) {
      cur->next = list2;
      list2 = list2->next;
    }

    cur = cur->next;
  }

  cur->next = list1 ? list1 : list2;

  return dummy.next;
}

int main() {
  ListNode* list01 = makeLinkedList(vector<int>{1, 2, 4});
  ListNode* list02 = makeLinkedList(vector<int>{1, 3, 4});

  ListNode* list11 = makeLinkedList(vector<int>{});
  ListNode* list12 = makeLinkedList(vector<int>{});

  ListNode* list21 = makeLinkedList(vector<int>{});
  ListNode* list22 = makeLinkedList(vector<int>{0});

  ListNode* ret0 = mergeTwoLists(list01, list02);
  ListNode* ret1 = mergeTwoLists(list11, list12);
  ListNode* ret2 = mergeTwoLists(list21, list22);

  ListNode* ans0 = makeLinkedList(vector<int>{1, 1, 2, 3, 4, 4});
  ListNode* ans1 = makeLinkedList(vector<int>{});
  ListNode* ans2 = makeLinkedList(vector<int>{0});

  assert(isSameLinkedList(ret0, ans0));
  assert(isSameLinkedList(ret1, ans1));
  assert(isSameLinkedList(ret2, ans2));

  return 0;
}
