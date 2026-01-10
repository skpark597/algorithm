/* 445. Add Two Numbers II */
/** You are given two non-empty linked lists representing two non-negative integers. 
 *  The most significant digit comes first and each of their nodes contain a single digit. 
 *  Add the two numbers and return it as a linked list.
 * 
 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *  Follow up:
 *  What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 
 *  Example:
 *  Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 8 -> 0 -> 7 **/
// 처음 풀이. list로 표현되는 숫자가 너무 커지면 stoll 또는 stoi로 이 숫자를 표현하지 못하여 에러가 난다.

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 아래는 내가 처음 생각한 풀이. 복잡하다
ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<ListNode *> st1;
    stack<ListNode *> st2;
    ListNode *next = nullptr;
    bool moreThanTen = false;
    
    while (l1 != nullptr || l2 != nullptr) {
        if (l1 != nullptr) {
            st1.push(l1);
            l1 = l1->next;
        }
        
        if (l2 != nullptr) {
            st2.push(l2);
            l2 = l2->next;
        }
    }

    while (moreThanTen || !st1.empty() || !st2.empty()) {
        int leftVal = 0;
        int rightVal = 0;

        if (!st1.empty()) {
            leftVal = st1.top()->val;
            st1.pop();
        }

        if (!st2.empty()) {
            rightVal = st2.top()->val;
            st2.pop();
        }

        int val = moreThanTen ? leftVal+rightVal+1 : leftVal + rightVal;
        moreThanTen = val >= 10;
        val %= 10;
        ListNode *newNode = new ListNode(val);
        if (next != nullptr) newNode->next = next;
        next = newNode;
    }

    return next;
}

int main() {
    ListNode *l00 = new ListNode(3);
    ListNode *l01 = new ListNode(4, l00);
    ListNode *l02 = new ListNode(2, l01);
    ListNode *l03 = new ListNode(7, l02);
    
    ListNode *r00 = new ListNode(4);
    ListNode *r01 = new ListNode(6, r00);
    ListNode *r02 = new ListNode(5, r01);
    ListNode *ans0 = addTwoNumbers(l03, r02);

    ListNode *l10 = new ListNode(9);
    ListNode *l11 = new ListNode(9, l10);
    ListNode *l12 = new ListNode(9, l11);
    ListNode *l13 = new ListNode(9, l12);
    ListNode *l14 = new ListNode(9, l13);
    ListNode *l15 = new ListNode(9, l14);
    ListNode *l16 = new ListNode(9, l15);
    ListNode *l17 = new ListNode(9, l16);
    ListNode *l18 = new ListNode(9, l17);
    ListNode *l19 = new ListNode(3, l18);

    ListNode *r10 = new ListNode(7);
    ListNode *ans1 = addTwoNumbers(l19, r10);

    ListNode *l20 = new ListNode(5);
    ListNode *r20 = new ListNode(5);
    ListNode *ans2 = addTwoNumbers(l20, r20);

    while (ans0 != nullptr) {
        cout << ans0->val << " ";
        ans0 = ans0->next;
    } cout << endl; // 7 -> 8 -> 0 -> 7

    while (ans1 != nullptr) {
        cout << ans1->val << " ";
        ans1 = ans1->next;
    } cout << endl; //4 0 0 0 0 0 0 0 0 6

    while (ans2 != nullptr) {
        cout << ans2->val << " ";
        ans2 = ans2->next;
    } cout << endl; // 1 0

    return 0;
}
