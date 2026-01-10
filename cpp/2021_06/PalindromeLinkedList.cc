/** 234. Palindrome Linked List */
/** Given the head of a singly linked list, return true if it is a palindrome.
 * 
 *  Example 1:
 *  Input: head = [1,2,2,1]
 *  Output: true
 * 
 *  Example 2:
 *  Input: head = [1,2]
 *  Output: false
 * 
 *  Constraints:
 *  The number of nodes in the list is in the range [1, 10^5].
 *  0 <= Node.val <= 9
 * 
 *  Follow up: Could you do it in O(n) time and O(1) space? **/

#include <vector>
#include <stack>
#include "ListNode.h"

ListNode *reverseLinkedList(ListNode *head) {
    stack<ListNode*> st;
    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;
    
    if (head != nullptr) next = head->next;
    
    while (cur != nullptr) {
        cur->next = prev;
        prev = cur;
        cur = next;
        if (next != nullptr) next = next->next;
    }
    
    return prev;
}
    
bool isPalindrome(ListNode *head) {
    ListNode *iter = head;
    ListNode *reverseHead = nullptr;
    int count = 0;
    int start = 0;
    
    while (iter != nullptr) {
        count++;
        iter = iter->next;
    }
    
    iter = head;
    start = count % 2 == 0 ? count / 2 : (count + 1) / 2;
    for (int i = 0; i < start; ++i) {
        iter = iter->next;
    }
    
    reverseHead = reverseLinkedList(iter);
    iter = head;
    
    for (int i = 0; i < count/2; ++i) {
        if (iter->val != reverseHead->val) return false;
        iter = iter->next;
        reverseHead = reverseHead->next;
    }
    
    return true; 
}

bool isPalindrome2(ListNode *head) {
    ListNode *iter = head;
    int count = 0;
    stack<ListNode *> st;
    
    while (iter != nullptr) {
        count++;
        iter = iter->next;
    }
    
    iter = head;
    for (int i = 0; i < count/2; ++i) {
        st.push(iter);
        iter = iter->next;
    }
    
    if (count % 2 != 0) iter = iter->next;
    
    for (int i = 0; i < count/2; ++i) {
        if (st.top()->val != iter->val) return false;
        st.pop();
        iter = iter->next;
    }
    
    return true;
}

int main() {
    vector<int> nums0 {1,1,2,1};
    ListNode *head0 = util::makeLinkedList(nums0);

    bool ans0 = isPalindrome(head0);
    return 0;
}