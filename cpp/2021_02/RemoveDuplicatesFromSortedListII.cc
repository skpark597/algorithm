/* 82. Remove Duplicates from Sorted List II */
/** Given the head of a sorted linked list, delete all nodes that have duplicate numbers, 
 *  leaving only distinct numbers from the original list. Return the linked list sorted as well.
 * 
 *  Example 1:
 *  Input: head = [1,2,3,3,4,4,5]
 *  Output: [1,2,5]
 * 
 *  Example 2:
 *  Input: head = [1,1,1,2,3]
 *  Output: [2,3]
 * 
 *  Constraints:
 *  The number of nodes in the list is in the range [0, 300].
 *  -100 <= Node.val <= 100
 *  The list is guaranteed to be sorted in ascending order. **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode *head) {
    ListNode *iter;
    ListNode *start;

    ListNode *dummy = new ListNode(INT_MAX, head);
    iter = dummy;
    start = nullptr;

    while (iter->next != nullptr) {
        ListNode *next = iter->next;
        ListNode *nextNext = iter->next->next;

        if (iter->val != next->val) {
            if (start == nullptr && nextNext != nullptr && next->val == nextNext->val) {
                start = iter;
            } else if (start != nullptr && (nextNext == nullptr || next->val != nextNext->val)) {
                start->next = iter->next;
                start = nullptr;
            }
        }

        iter = iter->next;
    }

    if (start != nullptr) start->next = iter->next;

    return dummy->next;
}

ListNode* makeListNode(vector<int> nums) {
    ListNode *next = nullptr;
    reverse(nums.begin(), nums.end());

    for (int iter : nums) {
        ListNode *newNode = new ListNode(iter, next);
        next = newNode;
    }

    return next;
}

void printListNode(ListNode *node) {
    while (node != nullptr) {
        cout << node->val << " ";
        node = node->next;
    } cout << endl;
}

int main() {
    ListNode *test0 = makeListNode({1,2,3,3,4,4,5});
    ListNode *ans0 = deleteDuplicates(test0);

    ListNode *test1 = makeListNode({1,1,1,2,3});
    ListNode *ans1 = deleteDuplicates(test1);

    ListNode *test2 = makeListNode({1,1});
    ListNode *ans2 = deleteDuplicates(test2);

    printListNode(ans0);
    printListNode(ans1);
    printListNode(ans2);

    return 0;
}