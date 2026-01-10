#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* makeListNode(vector<int> &nums) {
    ListNode *node = nullptr;

    for (int i = nums.size()-1; i >= 0; --i) {
        ListNode *list = new ListNode(nums[i], node);
        node = list;
    }

    return node;
}

void printListNode(ListNode *list) {
    ListNode *node = list;

    while (node != nullptr) {
        cout<< node->val << " ";
        node = node->next;
    }
    cout << endl;
}