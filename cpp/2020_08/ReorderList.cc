/* 143. Reorder List */
/** Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 *  reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 *  
 *  You may not modify the values in the list's nodes, only nodes itself may be changed.
 *  
 *  Example 1:
 *  Given 1->2->3->4, reorder it to 1->4->2->3.
 *  
 *  Example 2:
 *  Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*/

#include <vector>
#include <stdlib.h>

using namespace std;

// Judge는 통과했으나 좀 더 간단한 방법이 없을까??

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    int size = 0;
    ListNode *next = head;
    ListNode *temp = nullptr;
    ListNode *temp2 = nullptr;
    vector<ListNode *> reverse;

    while (next != nullptr) {
        size++;
        next = next->next;
    }

    if (size == 0 || size == 1) return;

    next = head;
    for (int i=0; i < (size/2)-1; ++i) {
        next = next->next;
    }

    temp = next->next;
    next->next = nullptr;
    reverse.resize((size+1)/2);

    for (int i= (size-1)/2; i>=0; --i) {
        reverse[i] = temp;
        temp = temp->next;
    }

    for (int i=0; i < (size-1)/2; ++i) {
        reverse[i]->next = reverse[i+1];
    }
    reverse.back()->next = nullptr;

    temp = reverse[0];
    next= head;

    while (next != nullptr) {
        temp2 = next->next;
        next->next = temp;
        next = temp2;

        if (next != nullptr) {
            temp2 = temp->next;
            temp->next = next;
            temp = temp2;
        }
    }
}

int main() {
    //ListNode *node5 = new ListNode(5);
    //ListNode *node4 = new ListNode(4,node5);
    //ListNode *node3 = new ListNode(3);
    //ListNode *node2 = new ListNode(2,node3);
    ListNode *node1 = new ListNode(1);

    reorderList(node1);

    return 0;
}












