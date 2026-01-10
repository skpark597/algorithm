/** 21. Merge Two Sorted Lists */
/** Merge two sorted linked lists and return it as a sorted list. 
 *  The list should be made by splicing together the nodes of the first two lists.
 * 
 *  Example 1:
 *  Input: l1 = [1,2,4], l2 = [1,3,4]
 *  Output: [1,1,2,3,4,4]
 *  
 *  Example 2:
 *  Input: l1 = [], l2 = []
 *  Output: []
 * 
 *  Example 3:
 *  Input: l1 = [], l2 = [0]
 *  Output: [0]
 * 
 *  Constraints:
 *  The number of nodes in both lists is in the range [0, 50].
 *  -100 <= Node.val <= 100
 *  Both l1 and l2 are sorted in non-decreasing order. **/

#include "ListNode.h"
#include <iostream>

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(101);
    ListNode *prev = dummy;
    ListNode *iter1 = l1;
    ListNode *iter2 = l2;

    while (iter1 != nullptr || iter2 != nullptr) {
        if (iter1 == nullptr) {
            prev->next = new ListNode(iter2->val);
            iter2 = iter2->next;
        } else if (iter2 == nullptr) {
            prev->next = new ListNode(iter1->val);
            iter1 = iter1->next;
        } else if (iter1->val <= iter2->val) {
            prev->next = new ListNode(iter1->val);
            iter1 = iter1->next;
        } else {
            prev->next = new ListNode(iter2->val);
            iter2 = iter2->next;
        }

        prev = prev->next;
    }

    return dummy->next;
}

int main() {
    ListNode *l00 = util::makeLinkedList({1,2,4});
    ListNode *l01 = util::makeLinkedList({1,3,4});

    ListNode *l10 = nullptr;
    ListNode *l11 = nullptr;

    ListNode *l20 = nullptr;
    ListNode *l21 = util::makeLinkedList({0});

    ListNode *ans0 = mergeTwoLists(l00, l01);
    ListNode *ans1 = mergeTwoLists(l10, l11);
    ListNode *ans2 = mergeTwoLists(l20, l21);

    util::printList(ans0);
    util::printList(ans1);
    util::printList(ans2);

    return 0;
}

