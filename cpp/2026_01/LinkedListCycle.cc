/**141. Linked List Cycle
Given head, the head of a linked list, determine if the linked list has a cycle
in it.

There is a cycle in a linked list if there is some node in the list that can be
reached again by continuously following the next pointer. Internally, pos is
used to denote the index of the node that tail's next pointer is connected to.
Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the
1st node (0-indexed).


Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the
0th node.


Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:
The number of the nodes in the list is in the range [0, 10^4].
-10^5 <= Node.val <= 10^5
pos is -1 or a valid index in the linked-list.


Follow up: Can you solve it using O(1) (i.e. constant) memory? */

#include <cassert>
#include <cmath>

#include "ListNode.h"

using namespace std;
using namespace util;

int VISITED = pow(10, 5) + 1;

bool hasCycle(ListNode* head) {
  if (head == nullptr) return false;

  ListNode* fast = head;
  ListNode* slow = head;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) return true;
  }

  return false;
}

int main() {
  ListNode* head0 = makeLinkedList(vector<int>{3, 2, 0, -4});
  ListNode* final0 = head0->next->next->next;
  final0->next = head0->next;

  ListNode* head1 = makeLinkedList(vector<int>{1, 2});
  ListNode* final1 = head1->next;
  final1->next = head1;

  ListNode* head2 = makeLinkedList(vector<int>{1});

  bool ret0 = hasCycle(head0);
  bool ret1 = hasCycle(head1);
  bool ret2 = hasCycle(head2);

  assert(ret0 == true);
  assert(ret1 == true);
  assert(ret2 == false);

  return 0;
}
