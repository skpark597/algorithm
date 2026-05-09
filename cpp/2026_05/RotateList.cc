/** 61. Rotate List
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9 */

#include <cassert>

#include "ListNode.h"

using namespace std;
using namespace util;

ListNode* rotateRight(ListNode* head, int k) {
  int len = 0;
  ListNode *fast = head, *slow = head;

  while (fast) {
    len++;
    fast = fast->next;
  }

  if (!head || k % len == 0) return head;

  fast = head;

  for (int i = 0; i < len - 1; ++i) {
    fast = fast->next;
    if (i >= k % len) slow = slow->next;
  }

  ListNode* new_head = slow->next;
  slow->next = nullptr;
  fast->next = head;

  return new_head;
}

int main() {
  ListNode* node0 = makeLinkedList(vector<int>{1, 2, 3, 4, 5});
  ListNode* node1 = makeLinkedList(vector<int>{0, 1, 2});
  ListNode* node2 = makeLinkedList(vector<int>{1});

  int k0 = 2;
  int k1 = 4;
  int k2 = 0;

  ListNode* ret0 = rotateRight(node0, k0);
  ListNode* ret1 = rotateRight(node1, k1);
  ListNode* ret2 = rotateRight(node2, k2);

  ListNode* ans0 = makeLinkedList(vector<int>{4, 5, 1, 2, 3});
  ListNode* ans1 = makeLinkedList(vector<int>{2, 0, 1});
  ListNode* ans2 = makeLinkedList(vector<int>{1});

  assert(isSameLinkedList(ret0, ans0));
  assert(isSameLinkedList(ret1, ans1));
  assert(isSameLinkedList(ret2, ans2));

  return 0;
}