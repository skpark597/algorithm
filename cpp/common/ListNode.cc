#include <iostream>
#include "ListNode.h"

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {}
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

namespace util { 
    ListNode *makeLinkedList(vector<int> nums) {
        ListNode *head = nullptr;
        ListNode *prev = nullptr;

        if (nums.empty()) return nullptr;

        head = new ListNode(nums[0]);
        prev = head;

        for (int i = 1; i < nums.size(); ++i) {
            ListNode *newNode = new ListNode(nums[i]);
            prev->next = newNode;
            prev = newNode;
        }

        return head;
    }

    void printList(ListNode *head) {
        ListNode *iter = head;

        if (head == nullptr) {
            cout << "no element" << endl;
            return;
        }

        cout << "[";
        while (iter->next != nullptr) {
            cout << iter->val << ", ";
            iter = iter->next;
        }

        cout << iter->val << "]" << endl;
    } 
}

