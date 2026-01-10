/* 328. Odd Even Linked List */
/** Given a singly linked list, group all odd nodes together followed by the even nodes. 
 *  Please note here we are talking about the node number and not the value in the nodes.
 *  You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 * 
 *  Example 1:
 *  Input: 1->2->3->4->5->NULL
 *  Output: 1->3->5->2->4->NULL
 * 
 *  Example 2:
 *  Input: 2->1->3->5->6->4->7->NULL
 *  Output: 2->3->6->7->1->5->4->NULL
 * 
 *  Constraints:
 *  The relative order inside both the even and odd groups should remain as it was in the input.
 *  The first node is considered odd, the second node even and so on ...
 *  The length of the linked list is between [0, 10^4]. **/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Discussion을 보고 구현한 풀이. 완전 간단함.
ListNode* oddEvenList2(ListNode* head) {
    ListNode *odd, *even, *evenHead;
    if (head == nullptr) return head;

    odd = head;
    even = head->next;
    evenHead= even;

    while (even != nullptr && even->next != nullptr) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}


// 아래는 내가 처음 생각한 풀이
ListNode* oddEvenList(ListNode *head) {
    ListNode *cur, *second, *next, *nextNext;
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

    second = head->next;
    cur = head;

    while (cur->next != nullptr) {
        next = cur->next;
        nextNext = nullptr;
        
        if (next->next != nullptr) {
            nextNext = next->next;
            next->next = nextNext->next;
        }

        cur->next = nextNext;
        if (nextNext != nullptr) cur = nextNext;
    }

    cur->next = second;
    return head;
}

int main() {
    ListNode *node05 = new ListNode(5);
    ListNode *node04 = new ListNode(4, node05);
    ListNode *node03 = new ListNode(3, node04);
    ListNode *node02 = new ListNode(2, node03);
    ListNode *node01 = new ListNode(1, node02);
    ListNode *ans0 = oddEvenList2(node01);

    ListNode *node17 = new ListNode(7);
    ListNode *node16 = new ListNode(4, node17);
    ListNode *node15 = new ListNode(6, node16);
    ListNode *node14 = new ListNode(5, node15);
    ListNode *node13 = new ListNode(3, node14);
    ListNode *node12 = new ListNode(1, node13);
    ListNode *node11 = new ListNode(2, node12);
    ListNode *ans1 = oddEvenList2(node11);

    ListNode *node28 = new ListNode(8);
    ListNode *node27 = new ListNode(7, node28);
    ListNode *node26 = new ListNode(6, node27);
    ListNode *node25 = new ListNode(5, node26);
    ListNode *node24 = new ListNode(4, node25);
    ListNode *node23 = new ListNode(3, node24);
    ListNode *node22 = new ListNode(2, node23);
    ListNode *node21 = new ListNode(1, node22);
    ListNode *ans2 = oddEvenList2(node21);

    while (ans0 != nullptr) {
        cout << ans0->val << " ";
        ans0 = ans0->next;
    }
    cout << endl; // 1->3->5->2->4->NULL

    while (ans1 != nullptr) {
        cout << ans1->val << " ";
        ans1 = ans1->next;
    }
    cout << endl; // 2->3->6->7->1->5->4->NULL

    while (ans2 != nullptr) {
        cout << ans2->val << " ";
        ans2 = ans2->next;
    }
    cout << endl; // 1->3->5->7->2->4->6->8->NULL

    return 0;
}

