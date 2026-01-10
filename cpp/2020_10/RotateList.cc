/* 61. Rotate List */
/** Given a linked list, rotate the list to the right by k places, where k is non-negative.
 * 
 *  Example 1:
 *  Input: 1->2->3->4->5->NULL, k = 2
 *  Output: 4->5->1->2->3->NULL
 *  Explanation:
 *  rotate 1 steps to the right: 5->1->2->3->4->NULL
 *  rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 *  Example 2:
 *  Input: 0->1->2->NULL, k = 4
 *  Output: 2->0->1->NULL
 *  Explanation:
 *  rotate 1 steps to the right: 2->0->1->NULL
 *  rotate 2 steps to the right: 1->2->0->NULL
 *  rotate 3 steps to the right: 0->1->2->NULL
 *  rotate 4 steps to the right: 2->0->1->NULL **/

#include <list>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    int count = 1;
    ListNode *iter = head;
    ListNode *answer;

    if (head == nullptr) return nullptr;

    while (iter->next != nullptr) {
        count++;
        iter = iter->next;
    }

    iter->next = head;

    for (int i=0; i < count-k%count; ++i) {
        iter = iter->next;
    }

    answer = iter->next;
    iter->next = nullptr;

    return answer;
}

int main() {
    //ListNode *five = new ListNode(5);
    //ListNode *four = new ListNode(4,five);
    ListNode *three= new ListNode(2);
    ListNode *two = new ListNode(1, three);
    ListNode *one = new ListNode(0, two);
    int k = 4;

    ListNode *answer = rotateRight(one, k);

    while (answer != nullptr) {
        cout << answer->val << " ";
        answer = answer->next;
    }

    return 0;
}

